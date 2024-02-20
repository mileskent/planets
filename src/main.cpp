#include <iostream>
#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System/Vector2.hpp>

#define WINDOWSIZE 600
#define WINW WINDOWSIZE
#define WINH WINDOWSIZE

constexpr int FPS = 60;
constexpr float deltatime = 1.0f / FPS;

#define G 30.0f

class Planet : public sf::CircleShape{
public:
    float mass;
    sf::Vector2<float> velocity;

    Planet () : sf::CircleShape (WINDOWSIZE / 2.0f) {
        this->mass = 0.0f;
        this->velocity = sf::Vector2(0.0f, 0.0f);
    }

    Planet (float mass, float radius) : sf::CircleShape (radius) {
        this-> mass = mass;
        this->velocity = sf::Vector2(0.0f, 0.0f);
    }

};


int main()
{
    Planet sun(1000, WINDOWSIZE / 30.0f);
    sun.setFillColor(sf::Color::Yellow);
    sun.setPosition(WINW / 2.0f, WINH / 2.0f);

    Planet earth(1, WINDOWSIZE / 90.0f);
    earth.setFillColor(sf::Color::Blue);
    earth.setPosition(WINW / 1.5f, WINH / 2.0f);
    earth.velocity = sf::Vector2 (-1.0f, 2.0f);

    std::vector<Planet*> bodies = {&sun, &earth};
    
    sf::RenderWindow window(sf::VideoMode(WINW, WINH), "Planets");
    window.setFramerateLimit(FPS);
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
        // Each Body Exerts a force on each other body
        // For each body, determine the net force applied by the other bodies
        for (int b = 0; b < bodies.size(); b++) {
            sf::Vector2<float> netforce (0.0f, 0.0f);
            for (int j = 0; j < bodies.size(); j++) {
                if (j != b) {
                    // direction
                    sf::Vector2<float> force = bodies.at(j)->getPosition() - bodies.at(b)->getPosition();
                    // unit direction
                    float distance = sqrt((pow(force.x, 2) + pow(force.y, 2)));
                    force /= distance;
                    // final
                    force *= G * bodies.at(j)->mass * bodies.at(b)->mass * (float)pow(distance, -2);
                    netforce += force;
                }
            }
            // Calculate velocity based on netforce vector
            // netForce = m*a
            //  a = netForce/m -> v = netForce/m * t
            bodies.at(b)->velocity += netforce / bodies.at(b)->mass * deltatime;
            bodies.at(b)->move(bodies.at(b)->velocity);
            
            // wrapping
            sf::Vector2<float> pos = bodies.at(b)->getPosition();
//            std::cout << pos.x << ", " << pos.y << "\n";
            if (pos.y < 0) bodies.at(b)->setPosition(pos.x, WINH);
            else if (pos.y > WINH) bodies.at(b)->setPosition(pos.x, 0);
            if (pos.x < 0) bodies.at(b)->setPosition(WINW, pos.y);
            else if (pos.x > WINW) bodies.at(b)->setPosition(pos.y, 0);
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


