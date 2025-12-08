#include "def.hpp"
#include<iostream>
using namespace std;
car::car(float x,float y,string color,float height,float width):
carspr(cartex)
{
    carposx=x;
    carposy=y;
    carheight=height;
    carwidth=width;
    carcolor=color;
    cout<<"blue"<<endl;
    if (carcolor == "blue"){
        // We use the full, exact address you provided
        carurl = "/media/navajeevan/CONTENT/Linux works/c++/Game Development/Game 1/images/rectangleblue.png";
    }
    else{
        carurl="images/recatanglered.png";
    }
   
}
sf::Sprite& car::carsprite(){
   
    if (!cartex.loadFromFile(carurl)){
        cout<<"error"<<endl;
    }
    carspr.setPosition({carposx,carposy});
    carspr.setScale({carheight,carwidth});
    
    return carspr;


}