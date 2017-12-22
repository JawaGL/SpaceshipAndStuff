//
//  DoubleShoot.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef DoubleShoot_h
#define DoubleShoot_h
#include "Shoot.h"
#include <stdio.h>
class DoubleShoot : public Shoot{
    float _yTop;
    float _yBot;
    float diffY;
    int cptMov=1;
public:
    DoubleShoot(float x, float y, float length, float speed, float power, float direction):Shoot( x, y, length, speed, power, direction), _yTop(y+length/4.), _yBot(y-length/4.), diffY(getLength()/32) {
        //std::cout<<__FUNCTION__<< std::endl;
    }
    ~DoubleShoot(){
       // std::cout<<__FUNCTION__<<std::endl;
    }
    
    
    
    //methods
    void translate(float amplitude, float angle);
    void rotateArround(float x, float y, float angle);
    void act();
    void draw();
};
#endif /* DoubleShoot_h */
