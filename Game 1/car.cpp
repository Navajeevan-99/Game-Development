#include "def.hpp"
using namespace std;
car::car(float x,float y,float height,float width,string color)
:carspr(cartex)
{
    carposx=x;
    carposy=y;
    carheight=height;
    carwidth=width;
    carcolor=color;

    filesystem::path cwd=filesystem::current_path();
    if (carcolor=="blue"){
        carurl=(cwd/ "images/rectangleblue.png").string();
    }
    else if (carcolor=="red"){
        carurl=(cwd/ "images/rectanglered.png").string();
    }
    else{
        return;
    }
    if (!cartex.loadFromFile(carurl)){
        cout<<"image loading is error";
        return;

    }
    carspr.setTexture(cartex,true);
    carspr.setPosition({carposx,carposy});
    carspr.setScale({carheight,carwidth});
    carspr.setOrigin({(float)(height/2),(float)(width/2)});
}
sf::Sprite& car::getsprite(){
    return carspr;
}
sf::FloatRect car::getbound(){
    return carspr.getGlobalBounds();
}

circle::circle(float x,float y,float height,float width,string color)
:circlespr(circletex)
{
    circleposx=x;
    circleposy=y;
    circleheight=height;
    circlewidth=width;
    circlecolor=color;
    filesystem::path cwd=filesystem::current_path();
    if (circlecolor=="blue"){
        circleurl=(cwd/ "images/circleblue.png").string();
    }
    else if (circlecolor=="red"){
        circleurl=(cwd/ "images/circlered.png").string();
    }
    else{
        return;
    }
    if (!circletex.loadFromFile(circleurl)){
        cout<<"circle image loading is error";
        return;

    }
    circlespr.setTexture(circletex,true);
    circlespr.setPosition({circleposx,circleposy});
    circlespr.setScale({circleheight,circlewidth});
}
sf::Sprite& circle::circlegetsprite(){
    return circlespr;
}
sf::FloatRect circle::circlegetbound(){
    return circlespr.getGlobalBounds();
}
square::square(float x,float y,float height,float width,string color)
:squarespr(squaretex)
{
    squareposx=x;
    squareposy=y;
    squareheight=height;
    squarewidth=width;
    squarecolor=color;
    filesystem::path cwd=filesystem::current_path();
    if (squarecolor=="blue"){
        squareurl=(cwd/ "images/squareblue.png").string();
    }
    else if (squarecolor=="red"){
        squareurl=(cwd/ "images/squarered.png").string();
    }
    else{
        return;
    }
    if (!squaretex.loadFromFile(squareurl)){
        cout<<"circle image loading is error";
        return;

    }
    squarespr.setTexture(squaretex,true);
    squarespr.setPosition({squareposx,squareposy});
    squarespr.setScale({squareheight,squarewidth});
}
sf::Sprite& square::squaregetsprite(){
    return squarespr;
}
sf::FloatRect square::squaregetbound(){
    return squarespr.getGlobalBounds();
}
int car::movecar(int side,sf::RenderWindow& window,deque<sf::Sprite*> bluesquareleft,deque<sf::Sprite*> bluesquareright,deque<sf::Sprite*> bluecircleleft,deque<sf::Sprite*> bluecircleright,deque<sf::Sprite*> redsquareleft,deque<sf::Sprite*> redsquareright,deque<sf::Sprite*> redcircleleft,deque<sf::Sprite*> redcircleright,float speed){
        int i=1;
        float degree=45.f;
        
         
    
        if (side==0){
           
            
            while(window.isOpen() && i<=15){
                carspr.rotate(sf::degrees(degree));
                
                carspr.move({25.f,0.f});
                bluecircleleft[1]->move({0.f,3.f});
            redcircleleft[1]->move({0.f,2.f});
            bluecircleright[1]->move({0.f,2.5f});
            redcircleright[1]->move({0.f,2.2f});
            bluesquareleft[1]->move({0.f,1.f});
            redsquareleft[1]->move({0.f,1.5f});
            bluesquareright[1]->move({0.f,6.f});
            redsquareright[1]->move({0.f,0.5f});
                window.clear();
                window.draw(carspr);
            window.draw(*bluecircleleft[1]);
            window.draw(*redcircleleft[1]);
            window.draw(*bluecircleright[1]);
            window.draw(*redcircleright[1]);
            window.draw(*bluesquareleft[1]);
            window.draw(*redsquareleft[1]);
            window.draw(*bluesquareright[1]);
            window.draw(*redsquareright[1]);
            window.display();
            degree-=3;   
            i++;
            }
            
            return 1;
        }
        else{
            
            carspr.rotate(sf::degrees(degree));
            while(window.isOpen() && i<=15){
                degree=-45.f;
                carspr.move({-25.f,0.f});
                bluecircleleft[1]->move({0.f,3.f});
            redcircleleft[1]->move({0.f,2.f});
            bluecircleright[1]->move({0.f,2.5f});
            redcircleright[1]->move({0.f,2.2f});
            bluesquareleft[1]->move({0.f,1.f});
            redsquareleft[1]->move({0.f,1.5f});
            bluesquareright[1]->move({0.f,6.f});
            redsquareright[1]->move({0.f,0.5f});
                i++;
                window.clear();
                 window.draw(*bluecircleleft[1]);
            window.draw(*redcircleleft[1]);
            window.draw(*bluecircleright[1]);
            window.draw(*redcircleright[1]);
            window.draw(*bluesquareleft[1]);
            window.draw(*redsquareleft[1]);
            window.draw(*bluesquareright[1]);
            window.draw(*redsquareright[1]);
                window.draw(carspr);
                window.display();
                degree+=3.f;
            }
            
            return 0;
       
        
    }
    return 0;
    
}
void square::squaremove(){

        squarespr.move({0.f,1.f});
    
    

}

