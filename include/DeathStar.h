//
//  DeathStar.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 04/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef DeathStar_h
#define DeathStar_h
#include "CombatSpacecraft.h"
#include "PenetratingShoot.h"
#include <stdio.h>
class DeathStar: public CombatSpacecraft{
private:
    std::vector<PenetratingShoot*> * _shoots;
public:
    DeathStar(float x, float y, float size):
    CombatSpacecraft(
/*Pos X*/                           x,
/*Pos Y*/                           y,
/*Direction*/                       0,
/*side size*/                       size,
/*R*/                               1.0,
/*G*/                               0.0,
/*B*/                               1.0,
/*Price*/                           200,
/*shootSpeed*/                      0.005,
/*shootPower*/                      4,
/*shootFreas*/                      600),
    _shoots(new std::vector<PenetratingShoot*>())
    {
   // std::cout<<__FUNCTION__<< std::endl;
    }
    ~DeathStar()
    {
        
        for(auto it= _shoots->begin(); it!=_shoots->end();)
        {
            
            delete (*it);
            
			++it;
            
        }
        /*for(PenetratingShoot * p:*_shoots)
        {
            delete p;
        }*/
        delete _shoots;

    }
    //method
    void stopShoots();
    void shoot();
    int collidingShoot(std::vector<Asteroid *> * pvast);
    void draw();
    

};
#endif /* DeathStar_h */
