//
//  Shoot.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 09/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "Shoot.h"
Point2D * Shoot::getHead() const
{
    return _head;
}
void Shoot::setHead(float x, float y)
{
    if(_head!=NULL)
        delete _head;
    _head=new Point2D(x,y);
}

float Shoot::getLength() const
{
    return _length;
}
void Shoot::setLength(float l)
{
    _length=l;
}

float Shoot::getSpeed() const
{
    return _speed;
}
void Shoot::setSpeed(float s)
{
    _speed=s;
}

float Shoot::getPower() const
{
    return _power;
}
void Shoot::setPower(float p)
{
    _power=p;
}

float Shoot::getDirection() const
{
    return _direction;
}
void Shoot::setDirection(float direction)
{
    _direction=direction;
}
float Shoot::getX2() const
{
    return getHead()->getPosX() - cos(getRad(getDirection()))*getLength();
}
float Shoot::getY2() const
{
    return getHead()->getPosY() - sin(getRad(getDirection()))*getLength();

}
ShootHitBox* Shoot::getHitbox()
{
    return _hitbox;
}
bool Shoot::checkAlive() const
{
    return getLength()>0;
}
//method
/*void Shoot::translate(float amplitude, float angle)
{
    float newX =getHead()->getPosX()+cos(getRad(angle))*amplitude;
    float newY=getHead()->getPosY()+sin(getRad(angle))*amplitude;
    if(newX>1.0f || newX<1.0f)
    {
        setLenght(0);
    }
    _head->setPosX(newX);
    _head->setPosY(newY);
}*/
void Shoot::die()
{
    setLength(0);
}
void Shoot::draw()
{
    GraphicPrimitives::drawLine2D(getHead()->getPosX(), getHead()->getPosY(), getX2(), getY2(), 1.0f, 1.0f, 1.0f);
}
int Shoot::operator&(std::vector<Asteroid * > * pVecAst)
{
    int gain=0;
    ShootHitBox * pshb = getHitbox();
    //std::cout<<"Aste vector size" <<pVecAst->size()<<std::endl;
    int i=0;
    if(this->getLength()!=0)
    {
        for(Asteroid * a: *pVecAst)
        {
       // std::cout<<"Item" <<i<<std::endl;

            i++;
       
        if( *pshb&(a->getHitbox()))
        {
           // std::cout<<"Asteroid "<<a<<"life: "<<a->getLife()<<std::endl;
            a->damage(getPower());
            this->die();
            if(!a->checkAlive())
                gain+=a->getKillMoney();
        }
       
        }
    }
    return gain;
}
