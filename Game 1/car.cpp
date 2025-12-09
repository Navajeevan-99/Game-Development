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
        squareurl=(cwd/ "images/rectangleblue.png").string();
    }
    else if (squarecolor=="red"){
        squareurl=(cwd/ "images/rectanglered.png").string();
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
int car::movecar(int side){
    int i=1;
    
        if (side==0){
            
            while(i<=25){
               
                
                carspr.move({10.f,0.f});
                this_thread::sleep_for(chrono::milliseconds(10));
                i++;
            }
            return 1;
        }
        else{
            while(i<=25){
                for(int i;i<=10000000;i++);
                
                carspr.move({-10.f,0.f});
                this_thread::sleep_for(chrono::milliseconds(10));
                i++;
            }
            return 0;
       
        
    }
    
}

