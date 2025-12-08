#pragma once
#include <string>
#include<SFML/Graphics.hpp>
using namespace std;

class car{
    public:
    float carposx;
    float carposy;
    string carcolor;
    float carwidth;
    float carheight;
    void moveside();
    sf::Sprite& carsprite();
    sf::Texture cartex;
    sf::Sprite carspr;
   
    string carurl;
    car(float x,float y,string color,float width,float height);

};