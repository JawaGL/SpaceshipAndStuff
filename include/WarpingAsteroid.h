//
//  WarpingAsteroid.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef WarpingAsteroid_h
#define WarpingAsteroid_h
#include "Asteroid.h"
#include "GraphicPrimitives.h"
#include <stdio.h>
class WarpingAsteroid: public Asteroid{
private:
    Point2D * _ilC;
    float R, G, B;
    float _initialLane, _sizeCase, _beginBoardY, _endBoardY;
    int _cptWarp, _freqWarp;
public:
    WarpingAsteroid(float x, float y, int life, int killMoney, float speed, float w, float l, int freqWarp, float sizeCase, float beginBoardY, float endBoardY):Asteroid(x,y, life, killMoney, speed, w, l), _ilC(new Point2D(x-w/2, y-l/2)), R(0.0),G(0.72), B(0.77), _cptWarp(0), _freqWarp(freqWarp), _initialLane(y), _sizeCase(sizeCase), _beginBoardY(beginBoardY), _endBoardY(endBoardY)
    {
        
    }
    ~WarpingAsteroid()
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
#endif /* WarpingAsteroid_h */
