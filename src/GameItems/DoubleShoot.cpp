//
//  DoubleShoot.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "DoubleShoot.h"
void DoubleShoot::translate(float amplitude, float angle)
{
    float newX =getHead()->getPosX()+cos(getRad(angle))*amplitude;
    if(_yTop> getHead()->getPosY() + getLength()/4)
        diffY=-diffY;
    if(_yTop<getHead()->getPosY() - getLength()/4)
        diffY=-diffY;
    //This shoot goes only from left to right in a straight line
    
    float newLength= getLength();
    if(newX>1.0f || newX<-1.0f)
    {
        newLength=0;
        newX=(int)  1;
    }
    if(cptMov%100)
    {
        _yTop+=diffY;
        _yBot-=diffY;
        cptMov=1;
    }
    cptMov++;
    setLength(newLength);
    getHead()->setPosX(newX);
    // getHead()->setPosY(newY);
}
void DoubleShoot::act()
{
    translate(getSpeed(), 0.0);
    getHitbox()->move(getHead(), getDirection(), getSpeed(), 0.0);

   
}
void DoubleShoot::rotateArround(float x, float y, float angle)
{
   //not IMPLEMENTED
}

void DoubleShoot::draw()
{
    GraphicPrimitives::drawLine2D(getHead()->getPosX(), _yTop, getX2(), _yTop, 1.0f, 0.0f, 0.0f);
    GraphicPrimitives::drawLine2D(getHead()->getPosX(), _yBot, getX2(), _yBot, 0.0f, 1.0f, 0.0f);
    
}
