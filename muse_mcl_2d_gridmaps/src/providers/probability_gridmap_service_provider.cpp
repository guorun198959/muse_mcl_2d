#include "probability_gridmap_service_provider.h"

#include <cslibs_gridmaps/static_maps/conversion/convert_probability_gridmap.hpp>
#include <class_loader/class_loader_register_macro.h>
CLASS_LOADER_REGISTER_CLASS(muse_mcl_2d_gridmaps::ProbabilityGridmapServiceProvider, muse_mcl_2d::MapProvider2D)

namespace muse_mcl_2d_gridmaps {
    ProbabilityGridmapServiceProvider::ProbabilityGridmapServiceProvider()
    {
    }

    void ProbabilityGridmapServiceProvider::setup(ros::NodeHandle &nh_private)
    {
        auto param_name = [this](const std::string &name){return name_ + "/" + name;};
        service_name_ = nh_private.param<std::string>(param_name("service"), "/static_map");
        source_ = nh_private.serviceClient<nav_msgs::GetMap>(service_name_);
        blocking_ = nh_private.param<bool>(param_name("blocking"), false);
    }


    ProbabilityGridmapServiceProvider::state_space_t::ConstPtr ProbabilityGridmapServiceProvider::getStateSpace() const
    {
        if(!map_) {
            nav_msgs::GetMap req;
            if(source_.call(req)) {
                ROS_INFO_STREAM("[" << name_ << "]: Loading map.");
                cslibs_gridmaps::static_maps::ProbabilityGridmap::Ptr map;
                cslibs_gridmaps::static_maps::conversion::from(req.response.map, map);
                map_.reset(new ProbabilityGridmap(map, std::string(req.response.map.header.frame_id)));
                ROS_INFO_STREAM("[" << name_ << "]: Loaded map.");
            }
        }
        return map_;
    }
}