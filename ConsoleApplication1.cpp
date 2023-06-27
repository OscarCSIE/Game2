// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

unsigned int WINDOW_HEIGHT = 512;
unsigned int WINDOW_WIDTH = 512;

class Player {
private:
    sf::RectangleShape rectangle;
    sf::Vector2f pos;
    bool isJumping;
    sf::RenderWindow* window;

    float movementSpeed = 500.f;
    const float gravity = 9800.f;

public:
    Player(sf::Vector2f size, sf::Vector2f position, sf::Color color, sf::RenderWindow* window)
        : rectangle(size), isJumping(false){
        rectangle.setFillColor(color);
        rectangle.setPosition(position.x, position.y - size.y);
        this->window = window;
    }

    void update(float deltaTime) {
        sf::Vector2f velocity = { 0.f, 0.f };

        // Check for keyboard input 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            velocity.x -= movementSpeed;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocity.x += movementSpeed;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            isJumping = true;
            velocity.y -= 4.5 * movementSpeed;  // Start moving upwards
        }

        if (isJumping) {
            velocity.y += 4.5 * gravity * deltaTime;
            pos.y += 4.5 * velocity.y * deltaTime;
            if (pos.y == this->window->getSize().y - rectangle.getSize().y) {
                isJumping = false;
            }
        }

        // Update player position
        pos = rectangle.getPosition() + sf::Vector2f(velocity.x * deltaTime, velocity.y * deltaTime);

        // Check collision with window borders
        if (pos.x <= 0) {
            pos.x = 0;
        }
        if (pos.x> this->window->getSize().x - rectangle.getSize().x) {
            pos.x = window->getSize().x - rectangle.getSize().x;
        }
        if (pos.y <= 0) {
            pos.y = 0;
        }
        if (pos.y >= this->window->getSize().y - rectangle.getSize().y) {
            pos.y = this->window->getSize().y - rectangle.getSize().y;
            velocity.y = 0;
        }

        rectangle.setPosition(pos);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(rectangle);
    }
};


int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Game");
    window.setPosition(sf::Vector2i(0, 0));
    window.setFramerateLimit(60);
    sf::View view(sf::FloatRect(0.f, 0.f, static_cast<float>(desktopMode.width), static_cast<float>(desktopMode.height)));
    window.setView(view);

    sf::Clock clock;

    Player PlayerA(sf::Vector2f(100, 100), sf::Vector2f(0, (float)window.getSize().y - 100), sf::Color::Red, &window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        PlayerA.update(deltaTime);

        window.clear();
        PlayerA.draw(window);
        window.display();
    }

    return 0;
}