//
//  Serenity.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "Serenity.h"

void Serenity::stopShoots()
{
    for(auto it= _shoots->begin(); it!=_shoots->end();)
    {
        
        delete (*it);
        ++it;
        
        
        
    }
    /*for(RotatingShoot * ps: *_shoots)
    {
        delete ps;
        
        
    }*/
    _shoots->clear();
}
void Serenity::shoot(){
    //  std::cout<< "CptHeat: " <<getCptHeat()<< "   ShootFreq: "<< getShootFreq()<< std::endl;
    //  std::cout<<_shoots->size()<<std::endl;
    
    if(getCptHeat()%getShootFreq() ==0)
    {
        //Penetrating shoot:float x, float y, float length, float speed, float power, float direction):Shoot( x, y, length, speed, power, direction
        _shoots->push_back(new RotatingShoot(
                                                getOrigin()->getPosX()+getSide(),
                                                getOrigin()->getPosY(),
                                                getSide()/4,
                                                getShootSpeed(),
                                                getShootPower(),
                                                0.0f
                                                )
                           );
        
        rstCptHeat();
    }
  //  int i=0;
    
    for(auto it= _shoots->begin(); it!=_shoots->end();)
    {
        if(!(*it)->checkAlive())
        {
            delete (*it);
            it=_shoots->erase(it);
        }
        else
        {
            (*it)->act();
            ++it;
        }
        
        
    }
    /*for(RotatingShoot * ps : *_shoots)
    {
        
        if(!ps->checkAlive())
        {
            delete ps;
            _shoots->erase(_shoots->begin() + i);
            
            i--;
            
        }
        else
        {
            ps->act();
        }
        i++;
    }*/
    IncCptHeat();
}
int Serenity::collidingShoot(std::vector<Asteroid *> *pvast)
{
    int gain=0;
    for(RotatingShoot * ps: *_shoots)
    {
        gain+= *ps&pvast;
    }
    return gain;
}
void Serenity::draw()
{
    Spacecraft::draw();
    for(RotatingShoot * ps : *_shoots)
    {
          // std::cout<<"Je dessine!!!\n"<< _shoots->size()<< std::endl;
        ps->draw();
    }
}
