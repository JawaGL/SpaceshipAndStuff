//
//  PenetratingShoot.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 09/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef PenetratingShoot_h
#define PenetratingShoot_h
#include "Shoot.h"
#include <stdio.h>
class PenetratingShoot : public Shoot{
private:
    Point2D * _origin=NULL;
public:
    PenetratingShoot(float x, float y, float length, float speed, float power, float direction):Shoot( x, y, length, speed, power, direction), _origin(new Point2D(x+length,y)) {
    //std::cout<<__FUNCTION__<< std::endl;
    
    }
    ~PenetratingShoot()
    {
        delete _origin;
    }
    //get/set
    float getOriginX() const;
    float getOriginY() const;
    
    
    //methods
    void translate(float amplitude, float angle);
    void rotateArround(float x, float y, float angle);
    void die();
    void act();
    
};
#endif /* PenetratingShoot_h */
