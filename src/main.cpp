#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include <cmath>

#include "ant.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Ant colony simulation");
    window.setFramerateLimit(60);
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    ant::Ant(3.0, 4.6);
    sf::CircleShape circle(30, 100);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(0, 0);
    
    float vx = 4.f, vy = std::sqrt(8.f);

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
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(circle);
        window.display();
    }

    return 0;
}
