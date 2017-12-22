//
//  RotatingShoot.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "RotatingShoot.h"

void RotatingShoot::translate(float amplitude, float angle)
{
    float newX =getHead()->getPosX()+cos(getRad(angle))*amplitude;
  //  float newY=getHead()->getPosY()+sin(getRad(angle))*amplitude;
    //This shoot goes only from left to right in a straight line
    float newLength= getLength();
    if(newX>1.0f || newX<-1.0f)
    {
        newLength=0;
        newX=(int) 1;
    }
    
    setLength(newLength);
    getHead()->setPosX(newX);
   // getHead()->setPosY(newY);
}
void RotatingShoot::act()
{
    translate(getSpeed(), 0.0);
    rotateArround((getHead()->getPosX() + getX2())/2,
                    (getHead()->getPosY() + getY2())/2,
                  5);
    //std::cout<<"Tail coord: "<< getX2() << " Head: "<< getHead()->getPosX()<<std::endl;
    getHitbox()->move(getHead(), getDirection(), getSpeed(), 0.0);

}
void RotatingShoot::rotateArround(float x, float y, float angle)
{
    getHead()->rotateArround(x, y, angle);
    setDirection(getDirection()+angle);
}
