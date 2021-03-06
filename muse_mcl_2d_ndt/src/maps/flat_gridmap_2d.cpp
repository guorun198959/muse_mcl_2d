#include <muse_mcl_2d_ndt/maps/flat_gridmap_2d.h>

namespace muse_mcl_2d_ndt {
FlatGridmap2D::FlatGridmap2D(const cslibs_ndt_2d::static_maps::mono::Gridmap::Ptr &map,
                 const std::string frame_id) :
    muse_mcl_2d::Map2D(frame_id),
    data_(map)
{
}

FlatGridmap2D::state_space_boundary_t FlatGridmap2D::getMin() const
{
    return data_->getInitialOrigin() * data_->getMin();
}

FlatGridmap2D::state_space_boundary_t FlatGridmap2D::getMax() const
{
    return data_->getInitialOrigin() * data_->getMax();
}

FlatGridmap2D::state_space_transform_t FlatGridmap2D::getOrigin() const
{
    return data_->getOrigin();
}

bool FlatGridmap2D::validate(const cslibs_math_2d::Pose2d &p) const
{
    return data_->validate(p);
}

cslibs_ndt_2d::static_maps::mono::Gridmap::Ptr& FlatGridmap2D::data()
{
    return data_;
}

cslibs_ndt_2d::static_maps::mono::Gridmap::Ptr const& FlatGridmap2D::data() const
{
    return data_;
}
}
