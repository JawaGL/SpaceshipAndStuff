//
//  Serenity.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef Serenity_h
#define Serenity_h
#include "CombatSpacecraft.h"
#include "RotatingShoot.h"
#include <stdio.h>
class Serenity: public CombatSpacecraft{
private:
    std::vector <RotatingShoot *> * _shoots;
public:
    Serenity(float x, float y, float size):
    CombatSpacecraft(
    /*Pos X*/                           x,
    /*Pos Y*/                           y,
    /*Direction*/                       0,
    /*side size*/                       size,
    /*R*/                               0.0,
    /*G*/                               0.0,
    /*B*/                               1.0,
    /*Price*/                           150,
    /*shootSpeed*/                      0.005,
    /*shootPower*/                      50,
    /*shootFreq*/                       150),
    _shoots(new std::vector<RotatingShoot*>())
    {
        // std::cout<<__FUNCTION__<< std::endl;
    }
    ~Serenity()
    {
        for(auto it= _shoots->begin(); it!=_shoots->end();)
        {
            
            delete (*it);
			it++;
            
            
        }
        /*for(RotatingShoot * rp: *_shoots)
        {
            delete rp;
        }*/
        delete _shoots;
    }
    
    //method
    void stopShoots();
    void shoot();
    int collidingShoot(std::vector<Asteroid *> * pvast);
    void draw();
};
#endif /* Serenity_h */
