#ifndef MUSE_MCL_2D_OCCUPANCY_GRIDMAP_3D_LIKELIHOOD_FIELD_MODEL_H
#define MUSE_MCL_2D_OCCUPANCY_GRIDMAP_3D_LIKELIHOOD_FIELD_MODEL_H

#include <muse_mcl_2d/update/update_model_2d.hpp>
#include <cslibs_gridmaps/utility/inverse_model.hpp>

namespace muse_mcl_2d_ndt {
class OccupancyGridmap3dLikelihoodFieldModel : public muse_mcl_2d::UpdateModel2D
{
public:
    OccupancyGridmap3dLikelihoodFieldModel();

    virtual void apply(const data_t::ConstPtr         &data,
                       const state_space_t::ConstPtr  &map,
                       sample_set_t::weight_iterator_t set) override;

protected:
    std::size_t max_points_;
    double      d1_;
    double      d2_;
    double      occupied_threshold_;
    double      histogram_resolution_;
    cslibs_gridmaps::utility::InverseModel::Ptr inverse_model_;

    virtual void doSetup(ros::NodeHandle &nh) override;
};
}

#endif // MUSE_MCL_2D_OCCUPANCY_GRIDMAP_3D_LIKELIHOOD_FIELD_MODEL_H
