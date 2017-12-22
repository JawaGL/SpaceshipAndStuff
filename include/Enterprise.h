//
//  Enterprise.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef Enterprise_h
#define Enterprise_h
#include "CombatSpacecraft.h"
#include "DoubleShoot.h"
#include <stdio.h>
class Enterprise: public CombatSpacecraft{
private:
    std::vector<DoubleShoot*> * _shoots;
    
public:
    Enterprise(float x, float y, float size):
    CombatSpacecraft(
    /*Pos X*/                           x,
    /*Pos Y*/                           y,
    /*Direction*/                       0,
    /*side size*/                       size,
    /*R*/                               1.0,
    /*G*/                               0.0,
    /*B*/                               0.0,
    /*Price*/                           100,
    /*shootSpeed*/                      0.005,
    /*shootPower*/                      15,
    /*shootFreqs*/                      75),
    _shoots(new std::vector<DoubleShoot*>())
    {
        // std::cout<<__FUNCTION__<< std::endl;
    }
    ~Enterprise()
    {
        for(auto it= _shoots->begin(); it!=_shoots->end();)
        {
            
            delete (*it);
            
			++it;
        }
        /*for(DoubleShoot* ds: *_shoots)
        {
            delete ds;
        }*/
        delete _shoots;
    }
    
    //method
    void stopShoots();
    void shoot();
    int collidingShoot(std::vector<Asteroid *> * pvast);
    void draw();
};
#endif /* Enterprise_h */
