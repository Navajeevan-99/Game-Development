#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<filesystem>
#include<string>
#include<thread>
#include<chrono>
class car{
    public:
    car(float x,float y,float height,float width,std::string color);
    float carposx;
    float carposy;
    float carheight;
    float carwidth;
    std::string carcolor;
    std::string carurl;
    sf::Texture cartex;
    sf::Sprite carspr;
    sf::FloatRect carbound;
    sf::FloatRect getbound();
    sf::Sprite& getsprite();
    int movecar(int side);

};
class circle{
    public:
    circle(float x,float y,float height,float width,std::string color);
    float circleposx;
    float circleposy;
    float circleheight;
    float circlewidth;
    std::string circlecolor;
    std::string circleurl;
    sf::Texture circletex;
    sf::Sprite circlespr;
    sf::FloatRect circlebound;
    sf::FloatRect circlegetbound();
    sf::Sprite& circlegetsprite();

};

class square{
    public:
    square(float x,float y,float height,float width,std::string color);
    float squareposx;
    float squareposy;
    float squareheight;
    float squarewidth;
    std::string squarecolor;
    std::string squareurl;
    sf::Texture squaretex;
    sf::Sprite squarespr;
    sf::FloatRect squarebound;
    sf::FloatRect squaregetbound();
    sf::Sprite& squaregetsprite();
};

