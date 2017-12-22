//
//  Spacecraft.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "Spacecraft.h"

//get/set
Point2D * Spacecraft::getOrigin() const
{
    return _pOrigin;
}
float Spacecraft::getDirection() const
{
    return _direction;
}
void Spacecraft::setDirection(float angle)
{
    float newAngle=angle;
    if(angle> 360.)
    {
        newAngle-=360.;
    }
    if(angle < 0)
    {
        newAngle=360+angle;
    }
    
    _direction=newAngle;
}

float Spacecraft::getSide() const
{
    return _side;
}
void Spacecraft::setSide(float side)
{
    _side=side;
}

float Spacecraft::getRed() const
{
    return _R;
}
float Spacecraft::getGreen() const
{
    return _G;
}
float Spacecraft::getBlue() const
{
    return _B;
}
void Spacecraft::setColor(float r, float g, float b)
{
    _R=r;
    _G=g;
    _B=b;
}

float Spacecraft::getPrice() const
{
    return _price;
}
void Spacecraft::setPrice(float price)
{
    _price=price;
}

float Spacecraft::getGravityX()
{
    return _pGravity->getPosX();
}
float Spacecraft::getGravityY()
{
    return _pGravity->getPosY();
}
//methods
void Spacecraft::calculateP1()
{
    if(_pP1!=NULL)
        delete _pP1;
    float tmpX, tmpY;
    
    tmpX=cos (getRad(_direction-150.))*_side;
    tmpY= sin(getRad(_direction-150.))*_side;
    _pP1=new Point2D(_pOrigin->getPosX()+tmpX, _pOrigin->getPosY()+tmpY);
}
void Spacecraft::calculateP2()
{
    if(_pP2!=NULL)
        delete _pP2;
    float tmpX, tmpY;
    
    tmpX=cos (getRad(_direction-210.))*_side;
    tmpY= sin(getRad(_direction-210.))*_side;
    _pP2=new Point2D(_pOrigin->getPosX()+tmpX, _pOrigin->getPosY()+tmpY);
}
void Spacecraft::calculatePoints()
{
    calculateP1();
    calculateP2();
}
void Spacecraft::calculateGravity()
{
    if(_pGravity!=NULL)
        delete _pGravity;
    float gravX, gravY;
    gravX=(_pOrigin->getPosX()+_pP1->getPosX()+_pP2->getPosX())/3;
    gravY=(_pOrigin->getPosY()+_pP1->getPosY()+_pP2->getPosY())/3;
    //_pGravity= new Point2D(((*_pOrigin)+(*_pP1)+(*_pP2))/3.);
    _pGravity=new Point2D(gravX, gravY);
}
void Spacecraft::rotateArround(float x, float y, float angle)
{
    _pOrigin->rotateArround(x, y, angle);
    
    
    setDirection(getDirection()+angle);
    calculatePoints();
    calculateGravity();
    

}

void Spacecraft::draw()
{
    GraphicPrimitives::drawFillTriangle2D(_pOrigin->getPosX(),_pOrigin->getPosY(), _pP1->getPosX(),_pP1->getPosY(),_pP2->getPosX(), _pP2->getPosY(),getRed(),getGreen(),getBlue());
}
/*void Spacecraft::translate(float amplitude, float angle)
{
    //NOT IMPLEMENTED SINCE SPACECRAFT DO NOT NEED TO MOVE
}*/
