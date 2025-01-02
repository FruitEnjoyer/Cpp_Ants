/**
 * @brief header file for ant.cpp
 * 
 */

#ifndef ANT_HPP
#define ANT_HPP

namespace ant
{
    class Ant
    {
    private:
        double x, y; 
        double vx, vy;
        int health; /// range: 0-100
    public:
        Ant(double x, double y);
        ~Ant();
        double GetX();
        double GetY();
        Ant& SetX(double x);
        Ant& SetY(double y);
    };
} // namespace ant

#endif // ANT_HPP