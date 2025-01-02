/**
 * @brief header file for ant.cpp
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
        enum Status status;
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