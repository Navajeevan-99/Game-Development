
#include "def.hpp"

using namespace std;
int main(){
    
    int bluecarside=0;
    int redcarside=0;
    sf::RenderWindow window(sf::VideoMode({1920,1080}),"Two Cars");
    car carblue(1100.f,700.f,0.5f,0.5f,"blue");
    sf::Sprite& bluecar=carblue.getsprite();
    car carred(700.f,700.f,0.5f,0.5f,"red");
    sf::Sprite& redcar=carred.getsprite();
    sf::FloatRect carbluebound=carblue.getbound();
    sf::FloatRect carredbound=carred.getbound();
    circle circleblue(10.f,10.f,0.5f,0.5f,"blue");
    sf::Sprite& bluecircle=circleblue.circlegetsprite();
    sf::FloatRect circlebluebound=circleblue.circlegetbound();                  
    circle circlered(10.f,10.f,0.5f,0.5f,"blue");
    sf::Sprite& redcircle=circlered.circlegetsprite();
    sf::FloatRect circleredbound=circlered.circlegetbound();

    if (carbluebound.findIntersection(carredbound)){
        cout<<"true"<<endl;
    }
    window.setFramerateLimit(60);
    while(window.isOpen()){
        while(auto event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            if (auto* keycode=event->getIf<sf::Event::KeyPressed>()){
                if (keycode->code==sf::Keyboard::Key::K){

                    bluecarside=carblue.movecar(bluecarside);
                    
                }
            }
        }
        window.clear();
        window.draw(bluecar);
        window.draw(redcar);
        window.draw(bluecircle);
        window.draw(redcircle);
        window.display();

    }


}