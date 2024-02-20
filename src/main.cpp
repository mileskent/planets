#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector2.hpp>

#define WINDOWSIZE 600
#define WINW WINDOWSIZE
#define WINH WINDOWSIZE


int main()
{
    sf::RenderWindow window(sf::VideoMode(WINW, WINH), "Planets");
    window.setFramerateLimit(60);

    sf::CircleShape sun(WINDOWSIZE / 30.0f);
    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(WINW / 2.0f, WINH / 2.0f);

    sf::CircleShape earth(WINDOWSIZE / 90.0f);
    earth.setFillColor(sf::Color::Blue);
    earth.setPosition(WINW / 1.5f, WINH / 2.0f);

    while (window.isOpen())
    {
        // EVENTS
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // PHYSICS
//        shape.setPosition(shape.getPosition() + sf::Vector2(0.0f, 1.0f));

        // NEW FRAME

        window.clear();
        window.draw(sun);
        window.draw(earth);
        window.display();
    }

    return 0;
}


