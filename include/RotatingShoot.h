//
//  RotatingShoot.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef RotatingShoot_h
#define RotatingShoot_h
#include "Shoot.h"
#include <stdio.h>

class RotatingShoot: public Shoot {
private:
    float _rotatingDirection;
public:
    RotatingShoot(float x, float y, float length, float speed, float power, float direction):Shoot( x, y, length, speed, power, direction), _rotatingDirection(0.0) {
        //std::cout<<__FUNCTION__<< std::endl;        
    }
    ~RotatingShoot(){
        
    }
    
    
    
    //methods
    void translate(float amplitude, float angle);
    void rotateArround(float x, float y, float angle);
    void act();
};
#endif /* RotatingShoot_h */
