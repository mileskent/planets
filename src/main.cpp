#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector2.hpp>

#define WINDOWSIZE 600
#define WINW WINDOWSIZE
#define WINH WINDOWSIZE

// Make wrapper class for planet -> sf::CircleShape, mass


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

    std::vector<sf::CircleShape*> bodies = {&sun, &earth};

    while (window.isOpen())
    {
        // EVENTS
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // GRAVITY
        // F_g = K * m_1 * m_2 * r^-2
        for (auto body : bodies) {
            // body->move ( sf::Vector2(0.0f, 1.0f) );
        }

        // NEW FRAME

        window.clear();
        for (auto body : bodies) {
            window.draw(*body);
        }
        window.display();
    }

    return 0;
}


