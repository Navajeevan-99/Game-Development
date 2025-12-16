
#include "def.hpp"
using namespace std;
int main(){
    sf::Clock clock;
    float dt=clock.restart().asSeconds();
    int bluecarside=0;
    int redcarside=1;
    sf::RenderWindow window(sf::VideoMode({1920,1080}),"Two Cars");
    car carblue(1100.f,700.f,0.5f,0.5f,"blue");
    sf::Sprite& bluecar=carblue.getsprite();
    car carred(700.f,700.f,0.5f,0.5f,"red");
    sf::Sprite& redcar=carred.getsprite();
    sf::FloatRect carbluebound=carblue.getbound();
    sf::FloatRect carredbound=carred.getbound();
    vector<circle> circleblueleft;
    vector<circle> circleblueright;
    vector< sf::Sprite>* bluecircleleft;
    for (int i=0;i<5;i++){
        circleblueleft.emplace_back(10.f,10.f,0.5f,0.5f,"blue");
        circleblueright.emplace_back(10.f,10.f,0.5f,0.5f,"blue");
        bluecircleleft
        

    }
    
    sf::FloatRect circlebluebound=circleblue.circlegetbound();                  
    circle circlered(10.f,10.f,0.5f,0.5f,"blue");
    sf::Sprite& redcircle=circlered.circlegetsprite();
    sf::FloatRect circleredbound=circlered.circlegetbound();
    square squareblue(10.f,10.f,0.5f,0.5f,"blue");
    sf::Sprite& bluesquare=squareblue.squaregetsprite();
    sf::FloatRect squarebluebound=squareblue.squaregetbound();                  
    square squarered(10.f,10.f,0.5f,0.5f,"blue");
    sf::Sprite& redsquare=squarered.squaregetsprite();
    sf::FloatRect squareredbound=squarered.squaregetbound();

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

                    bluecarside=carblue.movecar(bluecarside,window);
                    
                }
                if (keycode->code==sf::Keyboard::Key::S){

                    redcarside=carred.movecar(redcarside,window);
                    
                }
            }
            
        }
        squareblue.squaremove();
        window.clear();
        window.draw(bluecar);
        window.draw(redcar);
        window.draw(bluesquare);
        window.draw(redcircle);
        window.display();

    }


}