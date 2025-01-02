#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

#include "ant.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Ant colony simulation");
    window.setFramerateLimit(60);

    ant::Ant(3.0, 4.6);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.display();
    }

    return 0;
}
