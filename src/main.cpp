#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <cmath>
#include <iostream>

#include "ant.hpp"
#include "food.cpp"

Food_t* p_food;

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Ant colony simulation");
    sf::Event event;
    sf::ContextSettings settings;
    window.setFramerateLimit(60);
    settings.antialiasingLevel = 8;

    ant::Ant(3.0, 4.6);
    sf::CircleShape circle(30, 100);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(0, 0);
    
    float vx = 4.f, vy = std::sqrt(8.f);

    p_food = Food_initialize(0, 0, 100, 100, 10, 10);

    while (window.isOpen())
    {
        sf::Vector2f pos = circle.getPosition();
        if(pos.x > 540.f) 
        { 
            vx = -vx;
            circle.setPosition(539.5f, pos.y);
        }
        if(pos.x < 0.f)
        {
            vx = -vx;
            circle.setPosition(0.5f, pos.y);
        }
        if(pos.y > 540.f) 
        { 
            vy = -vy;
            circle.setPosition(pos.x, 539.5f);
        }
        if(pos.y < 0.f)
        {
            vy = -vy;
            circle.setPosition(pos.x, 0.5f);
        }

        circle.move(vx, vy);
        
        if (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(circle);
        window.display();

        //food test
        Food_set_by_position(p_food, 99, 99, 5);
        Food_print(p_food);
        
    }
    Food_terminate(p_food);

    std::cout << "\033[1;32m[Done]\n\033[0m" << std::endl;
    return 0;
}
