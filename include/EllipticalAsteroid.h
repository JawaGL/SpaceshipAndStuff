//
//  EllipticalAsteroid.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 11/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef EllipticalAsteroid_h
#define EllipticalAsteroid_h
#include "Asteroid.h"
#include "GraphicPrimitives.h"
#include "GeometricalItem.h"
#include <stdio.h>
#include <vector>
class EllipticalAsteroid : public Asteroid{
private:
    std::vector<float *> * _pX;
    std::vector <float *> * _pY;
    float R,G,B;
    int _cptShield;
    bool _protected;
    
public:
    EllipticalAsteroid(float x, float y, int life, int killMoney, float speed, float w, float l):
    Asteroid(x,y,life, killMoney, speed, w,l),
    _pX(new std::vector<float *>()),
    _pY(new std::vector<float *>()),
    R(0.5),
    G(0.5),
    B(0.5),
    _cptShield(1),
    _protected(false)
    {
        float angle=0;
        while (angle <360)
        {
          //  xval=x+w*cos(angle)/2
            _pX->push_back( new float(x+w*cos(GeometricalItem::getRad(angle))/2));
            _pY->push_back(new float (y+l*sin(GeometricalItem::getRad(angle))/2));
            angle+=1;
        }
    }
    ~EllipticalAsteroid()
    {
        delete _pX;
        delete _pY;
    }
    
    void damage(int dmg);
    //methods
    virtual void rotateArround(float x, float y, float angle);
    virtual void draw();
    virtual void translate(float amplitude, float angle);
    virtual void act();
};
#endif /* EllipticalAsteroid_h */
