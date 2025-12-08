#include "def.hpp"
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace std;
int main(){
    car carblue(100.f,100.f,"blue",5.f,5.f);
    sf::Sprite& bluecar=carblue.carsprite();
    sf::RenderWindow window(sf::VideoMode({1920,1080}),"Two Cars");

    while(window.isOpen()){
        
        while(auto event=window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
                window.close();
            }
        }
        window.clear();
        window.draw(bluecar);
        
        window.display();     

         
    }
    
}
