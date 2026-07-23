
#include "def.hpp"
using namespace std;
int main(){
    float speed=0.5;
    int bluecarside=0;
    int redcarside=1;
    bool gamerun=true;
    //score definitions
    float score=0;
    float scorerate=0.1;
    int bestscore=0;
    sf::Font font;
    int movblueleftsquare=0;
    int movbluerightsquare=0;
    int movblueleftcircle=0;
    int movbluerightcircle=0;
    int movredleftsquare=0;
    int movredrightsquare=0;
    int movredleftcircle=0;
    int movredrightcircle=0;
    int loopcount=0;
    if (!font.openFromFile("roboto.ttf"))
{
    std::cout << "Failed to load font\n";
}
    sf::Text scoretext(font);
    scoretext.setString("Score: "+to_string((int)score));
    
    sf::RenderWindow window(sf::VideoMode({1920,1080}),"Two Cars");
    window.setKeyRepeatEnabled(false);
    car carblue(1100.f,800.f,0.5f,0.5f,"blue");
    sf::Sprite& bluecar=carblue.getsprite();
    car carred(700.f,700.f,0.5f,0.5f,"red");
    sf::Sprite& redcar=carred.getsprite();
    sf::FloatRect carbluebound=carblue.getbound();
    sf::FloatRect carredbound=carred.getbound();
    bluecar.setOrigin({
        carbluebound.size.x/2.f,
        carbluebound.size.y/2.f
    });
    redcar.setOrigin({
        carredbound.size.x/2.f,
        carredbound.size.y/2.f
    });

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
        circleblueleft[i].circlegetbound();
        circleblueright[i].circlegetbound();
        // red circle objects and other datas
        circleredleft.emplace_back(500.f,10.f,0.5f,0.5f,"red");
        circleredright.emplace_back(700.f,10.f,0.5f,0.5f,"red");
        redcircleleft.push_back(&circleredleft[i].circlegetsprite());
        redcircleright.push_back(&circleredright[i].circlegetsprite());
        circleredleft[i].circlegetbound();
        circleredright[i].circlegetbound();
        // blue square objects and other datas
        squareblueleft.emplace_back(1100.f,10.f,0.5f,0.5f,"blue");
        squareblueright.emplace_back(1300.f,10.f,0.5f,0.5f,"blue");
        bluesquareleft.push_back(&squareblueleft[i].squaregetsprite());
        bluesquareright.push_back(&squareblueright[i].squaregetsprite());
        squareblueleft[i].squaregetbound();
        squareblueright[i].squaregetbound();
        // red square objects and other datas
        squareredleft.emplace_back(500.f,10.f,0.5f,0.5f,"red");
        squareredright.emplace_back(700.f,10.f,0.5f,0.5f,"red");
        redsquareleft.push_back(&squareredleft[i].squaregetsprite());
        redsquareright.push_back(&squareredright[i].squaregetsprite());
        squareredleft[i].squaregetbound();
        squareredright[i].squaregetbound();
        
        
        }    
   
    window.setFramerateLimit(60);
    while(window.isOpen()){
        loopcount++;
        if(loopcount==1000){
            speed+=0.2;
        }
        
        if(gamerun){
        scoretext.setString("Score: "+to_string((int)score));
        while(auto event=window.pollEvent()){
            if(event->is<sf::Event::Closed>()){
                window.close();
            }
             
                    
            if (auto* keycode=event->getIf<sf::Event::KeyPressed>()){
                if(!carblue.carmoving){
                    
                if (keycode->code==sf::Keyboard::Key::K){
                   
                    
                    carblue.carmoving=true;
                    bluecarside=carblue.movecar(bluecarside,window,bluesquareleft,bluesquareright,bluecircleleft,bluecircleright,redsquareleft,redsquareright,redcircleleft,redcircleright,speed,redcar);
                    carblue.carmoving=false;
                
                }}
                if(!carred.carmoving){
                if (keycode->code==sf::Keyboard::Key::S){
                    carred.carmoving=true;
                    redcarside=carred.movecar(redcarside,window,bluesquareleft,bluesquareright,bluecircleleft,bluecircleright,redsquareleft,redsquareright,redcircleleft,redcircleright,speed,bluecar);
                    carred.carmoving=false;
                }}
            }
            
        }
  
        window.clear();
            for(int i=0;i<5;i++){
            
            
            bluecircleleft[i]->move({0.f,speed});
            redcircleleft[i]->move({0.f,speed});
            bluecircleright[i]->move({0.f,speed});
            redcircleright[i]->move({0.f,speed});
            bluesquareleft[i]->move({0.f,speed});
            redsquareleft[i]->move({0.f,speed});
            bluesquareright[i]->move({0.f,speed});
            redsquareright[i]->move({0.f,speed});
            

            window.draw(*bluecircleleft[i]);
            window.draw(*redcircleleft[i]);
            window.draw(*bluecircleright[i]);
            window.draw(*redcircleright[i]);
            window.draw(*bluesquareleft[i]);
            window.draw(*redsquareleft[i]);
            window.draw(*bluesquareright[i]);
            window.draw(*redsquareright[i]);
            squareredright[i].squaregetbound();
            carredbound=carred.getbound();
            if (squareredright[i].squarebound.findIntersection(carredbound)){
                    gamerun=false;
            }}
            // cout<<1<<"\n";}
        
        window.draw(bluecar);
        window.draw(redcar);
        window.draw(scoretext);
        
        window.display();
        score=score+scorerate;}
        else{
            scoretext.setPosition({900,500});
            if (bestscore<score){
                bestscore=score;
            }
            while(auto event=window.pollEvent()){
                if(event->is<sf::Event::Closed>()){
                window.close();
            }
            window.clear();
            
            window.draw(scoretext);
            
        
            window.display();
        }

    }


}}