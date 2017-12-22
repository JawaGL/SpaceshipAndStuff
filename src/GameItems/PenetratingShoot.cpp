//
//  PenetratingShoot.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 09/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "PenetratingShoot.h"
//get/set
float PenetratingShoot::getOriginX() const
{
    return  _origin->getPosX();
}
float PenetratingShoot::getOriginY() const
{
    return _origin->getPosY();
}


void PenetratingShoot::die()
{
    //REDIFINITION SO THAT PENETRATING SHOOTS DO NOT DIE ON IMPACT
}
//methods
void PenetratingShoot::translate(float amplitude, float angle)
{
   /* float newX =getHead()->getPosX()+cos(getRad(angle))*amplitude;
    float newY=getHead()->getPosY()+sin(getRad(angle))*amplitude;*/
    //This shoot goes only from left to right in a straight line
    float newX= getHead()->getPosX()+amplitude;
    float newLength= getLength()+ amplitude;
    if(newX>1.0f || newX<-1.0f)
    {
        newLength=0;
        newX=(int)  1;
    }
    
    setLength(newLength);
    getHead()->setPosX(newX);
  //  getHead()->setPosY(newY);
}
void PenetratingShoot::act()
{
    translate(getSpeed(), 0.0);
    //getHitbox()->move(getHead(), getDirection(), getSpeed(), 0.0);
    delete  getHitbox();
    _hitbox=new ShootHitBox(getHead()->getPosX(), getHead()->getPosY(), getLength());

}
void PenetratingShoot::rotateArround(float x, float y, float angle)
{
    //NOT IMPLEMENTED, PENETRATING SHOOT CAN'T ROTATE
}
