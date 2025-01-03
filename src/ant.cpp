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
    /// TODO: implement SFML object creation
}

ant::Ant::~Ant()
{
    /// TODO: implement proper ant destructor
}

double ant::Ant::GetX()
{  return this->x;  }

double ant::Ant::GetY()
{  return this->y;  }

ant::Ant& ant::Ant::SetX(double x)
{
    this->x = x;
    return *this;
}

ant::Ant& ant::Ant::SetY(double y)
{
    this->y = y;
    return *this;
}