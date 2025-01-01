#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "field.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");
    sf::Image icon;
    icon.loadFromFile("/home/ruslan/VSCodeProjects/makefile_1/build/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    window.setFramerateLimit(60);


    field::Field myfield(10,10);

    std::cout << myfield.GetStatus(std::pair<int,int>(1,2)) << std::endl;

    /*

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

    */

    return 0;
}