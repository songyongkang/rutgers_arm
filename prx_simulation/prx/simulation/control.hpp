/**
 * @file control.hpp 
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

#pragma once

#ifndef PRACSYS_CONTROL_HPP
#define PRACSYS_CONTROL_HPP

#include "prx/utilities/definitions/defs.hpp"
#include "prx/utilities/spaces/space.hpp"

namespace prx
{
    namespace sim
    {

        /** A \ref util::space_point_t that represent a control point */
        typedef util::space_point_t control_t;

    }
}

#endif
