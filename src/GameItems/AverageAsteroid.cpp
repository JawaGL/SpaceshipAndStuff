//
//  AverageAsteroid.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "AverageAsteroid.h"
Point2D* AverageAsteroid::getInferiorLeftCorner()
{
    return _ilC;
}
void AverageAsteroid::setInferiorLeftCorner(float x, float y)
{
    _ilC->setPosX(x);
    _ilC->setPosY(y);
}
void AverageAsteroid::rotateArround(float x, float y, float angle)
{
    //NOT IMPLEMENTED
}
void AverageAsteroid::translate(float amplitude, float angle)
{
    setCenter(getCenter()->getPosX()+amplitude*cos(getRad(angle)), getCenter()->getPosY()+amplitude*sin(getRad(angle)));
    setInferiorLeftCorner(getInferiorLeftCorner()->getPosX()+amplitude*cos(getRad(angle)), getInferiorLeftCorner()->getPosY()+amplitude*sin(getRad(angle)));
   // getHitbox()->move(amplitude, angle);
    getHitbox()->move(getCenter());
    
}
void AverageAsteroid::draw()
{
    GraphicPrimitives::drawFillRect2D(getInferiorLeftCorner()->getPosX(), getInferiorLeftCorner()->getPosY(), getWidth(), getLength(), R, G, B);
}
void AverageAsteroid::act()
{
    translate(getSpeed(), 180.);
}
