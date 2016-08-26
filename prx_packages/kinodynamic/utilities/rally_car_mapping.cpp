/**
 * @file rally_car_mapping.cpp 
 * 
 * @copyright Software License Agreement (BSD License)
 * Copyright (c) 2013, Rutgers the State University of New Jersey, New Brunswick  
 * All Rights Reserved.
 * For a full description see the file named LICENSE.
 * 
 * Authors: Andrew Dobson, Andrew Kimmel, Athanasios Krontiris, Zakary Littlefield, Kostas Bekris 
 * 
 * Email: pracsys@googlegroups.com
 */

#include "prx/utilities/parameters/parameter_reader.hpp"
#include "utilities/rally_car_mapping.hpp"
#include "prx/utilities/math/configurations/quaternion.hpp"
#include <pluginlib/class_list_macros.h> 

PLUGINLIB_EXPORT_CLASS( prx::packages::mapping_functions::rally_car_mapping_t, prx::util::mapping_function_t)

namespace prx
{
    namespace packages
    {       
        namespace mapping_functions
        {
            void rally_car_mapping_t::embed() const
            {
                unsigned start_index = preimage_interval.first;
                unsigned image_start_index = image_interval.first;
                get_image_index(image_start_index) = get_preimage_index(start_index);
                get_image_index(image_start_index + 1) = get_preimage_index(start_index + 1);
                get_image_index(image_start_index + 2) = get_preimage_index(start_index + 4);
            }

            void rally_car_mapping_t::invert() const
            {
                unsigned start_index = preimage_interval.first;
                unsigned image_start_index = image_interval.first;
                get_preimage_index(start_index) = get_image_index(image_start_index);
                get_preimage_index(start_index + 1) = get_image_index(image_start_index + 1);
                get_preimage_index(start_index + 4) = get_image_index(image_start_index + 2);
            }

            void rally_car_mapping_t::init_spaces()
            {
                //subspace and preimage should be set
                if( subspace == NULL || preimage_space == NULL )
                    PRX_FATAL_S("Rally car mapping doesn't have subspace or preimage_space");
                unsigned start_index = preimage_interval.first;
                //make the image space have the correct bounds information
                double low, high;
                preimage_space->get_bounds()[start_index]->get_bounds(low, high);
                subspace->get_bounds()[0]->set_bounds(low, high);
                preimage_space->get_bounds()[start_index+1]->get_bounds(low, high);
                subspace->get_bounds()[1]->set_bounds(low, high);
                preimage_space->get_bounds()[start_index + 4]->get_bounds(low, high);
                subspace->get_bounds()[2]->set_bounds(low, high);

            }
        }
    }
}