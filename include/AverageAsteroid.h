//
//  AverageAsteroid.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef AverageAsteroid_h
#define AverageAsteroid_h
#include "Asteroid.h"
#include "GraphicPrimitives.h"
#include <stdio.h>
class AverageAsteroid: public Asteroid{
private:
    Point2D * _ilC;
    
    float R, G, B;
    
public:
    //Asteroid(float x, float y, int life, int killMoney, float speed)
    AverageAsteroid(float x, float y, int life, int killMoney, float speed, float w, float l):Asteroid(x,y, life, killMoney, speed, w, l), _ilC(new Point2D(x-w/2, y-l/2)), R(0.4),G(0.137), B(0.0)
    {
    }
    ~AverageAsteroid()
    {
        delete _ilC;
    }
    //get/set
    Point2D* getInferiorLeftCorner();
    void setInferiorLeftCorner(float x, float y);
    
    //method
    virtual void rotateArround(float x, float y, float angle);
    virtual void draw();
    virtual void translate(float amplitude, float angle);
    virtual void act();
};
#endif /* AverageAsteroid_h */
