/**
 * @file ant.hpp
 * @author ruslan (valeev.rl@mipt.ru)
 * @brief header file for ant.cpp
 * @version 0.1
 * @date 2025-01-02
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#ifndef ANT_HPP
#define ANT_HPP

namespace ant
{
    enum Status
    {
        EATING = 0,
        SEARCHING
    };

    class Ant
    {
    private:
        double x, y; /// ant position
        double phi; /// ant body orientation in 2d
        double v; /// ant speed
        int health; /// range: 0-100
        Status status;
    public:
        Ant(double x, double y);
        ~Ant();
        double GetX();
        double GetY();
        Ant& SetX(double x);
        Ant& SetY(double y);
        /// TODO: implement method for ant visualisation
    };
} // namespace ant

#endif // ANT_HPP