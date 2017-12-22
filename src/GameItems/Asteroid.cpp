//
//  Asteroid.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "Asteroid.h"
void Asteroid::setCenter(float x, float y)
{
    _center->setPosX(x);
    _center->setPosY(y);
}
Point2D * Asteroid::getCenter()
{
    return _center;
}
void Asteroid::setLife(int life)
{
    _life=life;
}
int Asteroid::getLife()
{
    return _life;
}
void Asteroid::setKillMoney(int km)
{
    _killMoney=km;
}
int Asteroid::getKillMoney()
{
    return _killMoney;
}
void Asteroid::setSpeed(float s)
{
    _speed=s;
}
float Asteroid::getSpeed()
{
    return _speed;
}
float Asteroid::getWidth()
{
    return _width;
}
void Asteroid::setWidth(float w)
{
    _width=w;
}
float Asteroid::getLength()
{
    return _length;
}
void Asteroid::setLength(float l)
{
    _length=l;
}
AsteroidHitBox * Asteroid::getHitbox()
{
    return _hitbox;
}
bool Asteroid::checkAlive()
{
    return getLife()>0;
}
void Asteroid::damage(int pt)
{
    //std::cout<<"COUCOU"<<std::endl;
    setLife(getLife()-pt);
}


