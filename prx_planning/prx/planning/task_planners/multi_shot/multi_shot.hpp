/**
 * @file multi_shot.hpp 
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
#ifndef PRX_MULTI_SHOT_HPP
#define	PRX_MULTI_SHOT_HPP

#include "prx/utilities/definitions/defs.hpp"
#include "prx/utilities/parameters/parameter_reader.hpp"

#include "prx/planning/modules/stopping_criteria/stopping_criteria.hpp"
#include "prx/planning/task_planners/task_planner.hpp"

namespace prx
{
    namespace plan
    {

        class multi_shot_specification_t;
        class multi_shot_query_t;
        class motion_planning_query_t;
        /**
         * @anchor multi_shot_planner_t
         * 
         * @brief <b> A simple task planner that runs a lot of queries on a single motion planner.</b>
         * 
         * @author Zakary Littlefield
         */
        class multi_shot_planner_t : public task_planner_t
        {

          public:
                       
            /**
             * @copydoc task_planner_t::init()
             */
            virtual void init(const util::parameter_reader_t* reader, const util::parameter_reader_t* template_reader = NULL);

            /**
             * @copydoc task_planner_t::setup()
             */
            virtual void setup();

            /**
             * @copydoc task_planner_t::execute()
             */
            virtual bool execute();

            /**
             * @copydoc task_planner_t::get_statistics()
             */
            virtual const util::statistics_t* get_statistics();

            /**
             * @copydoc task_planner_t::succeeded()
             */
            virtual bool succeeded() const;
            
            /**
             * @copydoc task_planner_t::link_specification(specification_t*)
             */
            virtual void link_specification(specification_t* in_specification);

            /**
             * @copydoc task_planner_t::link_query(query_t*)
             */
            virtual void link_query(query_t* in_query);

            /**
             * @copydoc task_planner_t::resolve_query()
             */
            virtual void resolve_query();

          protected:
            /**
             * @copydoc task_planner_t::update_vis_info()
             */
            virtual void update_vis_info() const;

            /** @brief The query for the single shot task planner. */
            multi_shot_specification_t* specification;
            specification_t* sub_spec;
            /** @brief The query for the single shot task planner. */
            multi_shot_query_t* query;
            motion_planning_query_t* sub_query;
            /** @brief An interruption criterion used for statistics gathering. */
            std::vector<criterion_t*> stats_criteria;
            /** @brief A flag indicating whether the statistics should be appended onto the file */
            bool append_statistics;
        };

    }
}

#endif

