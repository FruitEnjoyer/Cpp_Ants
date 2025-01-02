/**
 * @file ant.cpp
 * @author ruslan (valeev.rl@mipt.ru)
 * @brief implementation of ant class providing simulation methods
 * @version 0.1
 * @date 2025-01-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "ant.hpp"

/**
 * @brief Construct a new ant::Ant::Ant object
 * 
 * @param x x coordinate
 * @param y y coordinate
 */
ant::Ant::Ant(double x, double y)
{
    this->x = x;
    this->y = y;
}