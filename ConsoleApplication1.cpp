// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

float WINDOW_HEIGHT = 512;
float WINDOW_WIDTH = 512;

int main(){
    sf::RenderWindow window(sf::VideoMode((unsigned int)WINDOW_WIDTH, (unsigned int)WINDOW_HEIGHT), "SFML Window");
    window.setFramerateLimit(60);
    sf::Clock clock;
    float movementSpeed = 10;

    sf::RectangleShape PlayerA(sf::Vector2f(100, 200));

    PlayerA.setFillColor(sf::Color::Red);
    PlayerA.setPosition(sf::Vector2f(0, 0));


    sf::Font open_sans;
    open_sans.loadFromFile("C:\\Users\\Administrator\\Desktop\\Visual Studio\\Fonts\\open-sans\\OpenSans-Light.ttf");
    sf::Text message;
    message.setFont(open_sans);
    message.setFillColor(sf::Color::Green);
    message.setCharacterSize(48);
    message.setString("Hello World");
    sf::FloatRect messageBounds = message.getLocalBounds();
    message.setOrigin(messageBounds.left + messageBounds.width / 2.0f, 0);
    message.setPosition(window.getSize().x / 2.0f, 0);

    while (window.isOpen()){
        sf::Event event;
        
        while ( window.pollEvent(event) ){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        float movementX = 0.0f;
        float movementY = 0.0f;

        // Check for keyboard input
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            movementY -= movementSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            movementY += movementSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            movementX -= movementSpeed;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            movementX += movementSpeed;

        // Normalize the movement vector if diagonal movement is detected
        if (movementX * movementY != 0.0f){
            float length = std::sqrt(movementX * movementX + movementY * movementY);
            movementX = (movementX / length) * movementSpeed;
            movementY = (movementY / length) * movementSpeed;
        }

        PlayerA.move(movementX, movementY); // Move the object

        window.clear();
        window.draw(PlayerA);
        window.draw(message);
        window.display();
    }
    return 0;
}