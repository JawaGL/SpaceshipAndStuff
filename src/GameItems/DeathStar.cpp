//
//  DeathStar.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 04/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "DeathStar.h"
void DeathStar::stopShoots()
{
    
    for(auto it= _shoots->begin(); it!=_shoots->end();)
    {
        delete (*it);
        ++it;
        
    }
  /*  for(PenetratingShoot * ps: *_shoots)
    {
        delete ps;
        
        
    }*/
    _shoots->clear();
}
int DeathStar::collidingShoot(std::vector<Asteroid *> * pvast)
{
    int gain=0;
    for(PenetratingShoot * ps: *_shoots)
    {
       gain+= *ps&pvast;
    }
    return gain;
}

void DeathStar::shoot(){
  //  std::cout<< "CptHeat: " <<getCptHeat()<< "   ShootFreq: "<< getShootFreq()<< std::endl;
  //  std::cout<<_shoots->size()<<std::endl;

    if(getCptHeat()%getShootFreq() ==0)
    {
        //Penetrating shoot:float x, float y, float length, float speed, float power, float direction):Shoot( x, y, length, speed, power, direction
        _shoots->push_back(new PenetratingShoot(
                                                getOrigin()->getPosX(),
                                                getOrigin()->getPosY(),
                                                0.01,
                                                getShootSpeed(),
                                                getShootPower(),
                                                0.0f
                                                )                           
                           );
        
        rstCptHeat();
    }
    
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
   /* int i=0;
    for(PenetratingShoot * ps : *_shoots)
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
void DeathStar::draw()
{
    Spacecraft::draw();
    for(PenetratingShoot * ps : *_shoots)
    {
     //   std::cout<<"Je dessine!!!\n"<< _shoots->size()<< std::endl;
        ps->draw();
    }
}
