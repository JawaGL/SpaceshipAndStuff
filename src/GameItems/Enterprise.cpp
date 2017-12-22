//
//  Enterprise.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "Enterprise.h"
void Enterprise::stopShoots()
{
    
    for(auto it= _shoots->begin(); it!=_shoots->end();)
    {
        
        delete (*it);
        ++it;
        
    }
    
    _shoots->clear();
}
void Enterprise::shoot(){
    //  std::cout<< "CptHeat: " <<getCptHeat()<< "   ShootFreq: "<< getShootFreq()<< std::endl;
    //  std::cout<<_shoots->size()<<std::endl;
    
    if(getCptHeat()%getShootFreq() ==0)
    {
        //Penetrating shoot:float x, float y, float length, float speed, float power, float direction):Shoot( x, y, length, speed, power, direction
        _shoots->push_back(new DoubleShoot(
                                                getOrigin()->getPosX()+getSide()/4,
                                                getOrigin()->getPosY(),
                                                getSide()/4,
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
   /* for(i=0; i<size; i++)
    {
        
        DoubleShoot *ps = _shoots->at(i);//_shoots->operator[](i);
        if(!ps->checkAlive())
            
      
        
        
    }
    for(DoubleShoot * ps : *_shoots)
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
        count++;
    }*/
    IncCptHeat();
}
int Enterprise::collidingShoot(std::vector<Asteroid *> *pvast)
{
    int gain=0;
    for(DoubleShoot * ps: *_shoots)
    {
        gain+= *ps&pvast;
    }
    return gain;
}
void Enterprise::draw()
{
    Spacecraft::draw();
    for(DoubleShoot * ps : *_shoots)
    {
        //   std::cout<<"Je dessine!!!\n"<< _shoots->size()<< std::endl;
        ps->draw();
    }
}
