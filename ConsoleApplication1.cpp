// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <SFML/Graphics.hpp>

using namespace sf;

/*
text here:
try to reboot the live?
i triedd last night, i think it is busted

https://www.sfml-dev.org/documentation/2.6.0/modules.php
SFML website for us to check
可能要研究一下GIT 修改之後長怎樣這樣
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

    while (window.isOpen()){
        Event event;

        while ( window.pollEvent(event) ){
            if (event.type == Event::Closed)window.close();
            if (Keyboard::isKeyPressed(Keyboard::Escape))window.close();
        }
        window.clear();
        window.draw(circle);
        window.draw(rectangle);
        window.display();
    }
    return 0;
}