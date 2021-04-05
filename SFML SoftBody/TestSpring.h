#pragma once
#include <SFML/Graphics.hpp>
#include "DrawAgent.h" 
#include "DeltaT.h"
class TestSpring
{
private:
    // INITIAL SETTINGS
    float gravity = 10;
    float mass = 30;
    float positionY = 200;
    float positionX = 150;
    float velocityY = 0;
    float velocityX = 0;
    float timeStep = 0.28;
    float anchorX = 400;
    float anchorY = 181;
    float k = 2;
    float damping = 5;
    
    public :
    // DRAW FUNCTION
    void update() {
        // FORCE CALCULATIONS
        float springForceY = -k * (positionY - anchorY);
        float springForceX = -k * (positionX - anchorX);

        float dampingForceY = damping * velocityY;
        float dampingForceX = damping * velocityX;

        float forceY = springForceY + mass * gravity - dampingForceY;
        float forceX = springForceX - dampingForceX;

        float accelerationY = forceY / mass;
        float accelerationX = forceX / mass;

        velocityY = velocityY + accelerationY * timeStep;
        velocityX = velocityX + accelerationX * timeStep;

        positionY = positionY + velocityY * timeStep;
        positionX = positionX + velocityX * timeStep;
    }
    void draw(){
        sf::Vertex line[] =
        {
            sf::Vertex(sf::Vector2f(positionX, positionY)),
            sf::Vertex(sf::Vector2f(anchorX, anchorY))
        };

        sf::CircleShape circle;
        circle.setFillColor(sf::Color::Red);
        circle.setRadius(30);
        circle.setOrigin(30, 30);
        circle.setPosition({ positionX, positionY });

        DrawAgent::getInstance().Clear();

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            positionX= sf::Mouse::getPosition(DrawAgent::getInstance().getWindow()).x;
            positionY= sf::Mouse::getPosition(DrawAgent::getInstance().getWindow()).y;
        }

        //rect(anchorX - 5, anchorY - 5, 10, 10);



        //line(positionX, positionY, anchorX, anchorY);
        DrawAgent::getInstance().Draw(circle);
        DrawAgent::getInstance().getWindow().draw(line, 2, sf::Lines);
        //ellipse(positionX, positionY, 20, 20);

    };

};

