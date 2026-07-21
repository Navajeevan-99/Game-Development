
#include "def.hpp"
using namespace std;
int main(){
    float speed=0.1;
    int bluecarside=0;
    int redcarside=1;
    sf::RenderWindow window(sf::VideoMode({1920,1080}),"Two Cars");
    car carblue(1100.f,700.f,0.5f,0.5f,"blue");
    sf::Sprite& bluecar=carblue.getsprite();
    car carred(700.f,700.f,0.5f,0.5f,"red");
    sf::Sprite& redcar=carred.getsprite();
    sf::FloatRect carbluebound=carblue.getbound();
    sf::FloatRect carredbound=carred.getbound();
    //blue circles definition
    deque<circle> circleblueleft;
    deque<circle> circleblueright;
    deque< sf::Sprite*> bluecircleleft;
    deque<sf::Sprite*> bluecircleright;
    deque<sf::FloatRect*> bluecircleleftbound;
    deque<sf::FloatRect*> bluecirclerightbound;
    //red cicles definition
    deque<circle> circleredleft;
    deque<circle> circleredright;
    deque< sf::Sprite*> redcircleleft;
    deque<sf::Sprite*> redcircleright;
    deque<sf::FloatRect*> redcircleleftbound;
    deque<sf::FloatRect*> redcirclerightbound;
     //blue squares definition
    deque<square> squareblueleft;
    deque<square> squareblueright;
    deque< sf::Sprite*> bluesquareleft;
    deque<sf::Sprite*> bluesquareright;
    deque<sf::FloatRect*> bluesquareleftbound;
    deque<sf::FloatRect*> bluesquarerightbound;
    //red squares definition
    deque<square> squareredleft;
    deque<square> squareredright;
    deque< sf::Sprite*> redsquareleft;
    deque<sf::Sprite*> redsquareright;
    deque<sf::FloatRect*> redsquareleftbound;
    deque<sf::FloatRect*> redsquarerightbound;
    for (int i=0;i<5;i++){
        // blue circle objects and other datas
        circleblueleft.emplace_back(1100.f,10.f,0.5f,0.5f,"blue");
        circleblueright.emplace_back(1300.f,10.f,0.5f,0.5f,"blue");
        bluecircleleft.push_back(&circleblueleft[i].circlegetsprite());
        bluecircleright.push_back(&circleblueright[i].circlegetsprite());
       
        // red circle objects and other datas
        circleredleft.emplace_back(500.f,10.f,0.5f,0.5f,"red");
        circleredright.emplace_back(700.f,10.f,0.5f,0.5f,"red");
        redcircleleft.push_back(&circleredleft[i].circlegetsprite());
        redcircleright.push_back(&circleredright[i].circlegetsprite());
        
        // blue square objects and other datas
        squareblueleft.emplace_back(1100.f,10.f,0.5f,0.5f,"blue");
        squareblueright.emplace_back(1300.f,10.f,0.5f,0.5f,"blue");
        bluesquareleft.push_back(&squareblueleft[i].squaregetsprite());
        bluesquareright.push_back(&squareblueright[i].squaregetsprite());
   
        // red square objects and other datas
        squareredleft.emplace_back(500.f,10.f,0.5f,0.5f,"red");
        squareredright.emplace_back(700.f,10.f,0.5f,0.5f,"red");
        redsquareleft.push_back(&squareredleft[i].squaregetsprite());
        redsquareright.push_back(&squareredright[i].squaregetsprite());
        
        
        }    
   
    window.setFramerateLimit(60);
    while(window.isOpen()){
        while(auto event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
            if (auto* keycode=event->getIf<sf::Event::KeyPressed>()){
                if (keycode->code==sf::Keyboard::Key::K){

                    bluecarside=carblue.movecar(bluecarside,window,bluesquareleft,bluesquareright,bluecircleleft,bluecircleright,redsquareleft,redsquareright,redcircleleft,redcircleright,speed);
                    
                }
                if (keycode->code==sf::Keyboard::Key::S){

                    redcarside=carred.movecar(redcarside,window,bluesquareleft,bluesquareright,bluecircleleft,bluecircleright,redsquareleft,redsquareright,redcircleleft,redcircleright,speed);
                    
                }
            }
            
        }
  
        window.clear();
        
            bluecircleleft[1]->move({0.f,3.f});
            redcircleleft[1]->move({0.f,2.f});
            bluecircleright[1]->move({0.f,2.5f});
            redcircleright[1]->move({0.f,2.2f});
            bluesquareleft[1]->move({0.f,1.f});
            redsquareleft[1]->move({0.f,1.5f});
            bluesquareright[1]->move({0.f,6.f});
            redsquareright[1]->move({0.f,0.5f});
            window.draw(*bluecircleleft[1]);
            window.draw(*redcircleleft[1]);
            window.draw(*bluecircleright[1]);
            window.draw(*redcircleright[1]);
            window.draw(*bluesquareleft[1]);
            window.draw(*redsquareleft[1]);
            window.draw(*bluesquareright[1]);
            window.draw(*redsquareright[1]);
            // cout<<1<<"\n";
        
        window.draw(bluecar);
        window.draw(redcar);
        
        window.display();

    }


}