// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using namespace sf;

/*
text here:

https://www.sfml-dev.org/documentation/2.6.0/modules.php
SFML website for us to check

https://docs.github.com/en/pull-requests/committing-changes-to-your-project/creating-and-editing-commits/creating-a-commit-with-multiple-authors

*/
int main(){
    RenderWindow window(VideoMode(1024, 768), "SFML Window");
    window.setFramerateLimit(60);

    CircleShape circle(100.f);
    RectangleShape rectangle;
    circle.setFillColor(Color::Green);
    rectangle.setFillColor(Color::Magenta);

    Vector2f rectanglePosition(512, 384);
    rectangle.setPosition(rectanglePosition);
    rectangle.setSize(Vector2f(100,200) );


    Font open_sans;
    open_sans.loadFromFile("C:\\Users\\Administrator\\Desktop\\Visual Studio\\Fonts\\open-sans\\OpenSans-Light.ttf");
    Text message;
    message.setFont(open_sans);
    message.setString("Hello World");
    message.setPosition(300, 400);

    while (window.isOpen()){
        Event event;

        while ( window.pollEvent(event) ){
            if (event.type == Event::Closed)window.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))window.close();
        }
        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.draw(message);
        window.display();
    }
    return 0;
}