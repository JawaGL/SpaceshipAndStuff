//
//  Point2D.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "Point2D.h"


float Point2D::getPosX()const
{
    return _posX;
}
float Point2D::getPosY()const
{
    return _posY;
}
void Point2D::setPosX(float x)
{
    _posX=x;
    
}
void Point2D::setPosY(float y)
{
    _posY=y;
}

Point2D::Point2D(Point2D const& p)
{
    //std::cout<<"COPY POINT2D" << std::endl;
    setPosX(p.getPosX());
    setPosY(p.getPosY());
}


//method
void Point2D::draw()
{
    //not implemented: can't draw a point
}
void Point2D::rotateArround(float x, float y, float angle)
{
    float tmpPosX, tmpPosY;
    float posX= getPosX();
    float posY=getPosY();
    tmpPosX=posX -x;
    tmpPosY=posY -y;
    
    posX=(tmpPosX*cos(getRad(angle)) - tmpPosY*sin(getRad(angle)))+x;
    posY=(tmpPosY*cos(getRad(angle)) + tmpPosX*sin(getRad(angle))) +y;
    
    setPosY(posY);
    setPosX(posX);
    
}
void Point2D::translate(float amplitude, float angle)
{
    setPosX(getPosX()+cos(getRad(angle))*amplitude);
    setPosY(getPosY()+sin(getRad(angle))*amplitude);
}
/*//Operator
bool Point2D::operator==(Point2D& p){
    return (p.getPosY()==getPosY() && p.getPosX() == getPosX());
}
Point2D& Point2D::operator=( Point2D& p){
    if(this!=&p)
    {
        setPosX(p.getPosX());
        setPosY(p.getPosY());
    }
    
    return *this;
}
//return point2D so it can be a left operand operation
Point2D& Point2D::operator+(Point2D &p)
{
    Point2D *tmp= new Point2D(getPosX(), getPosY());
    tmp->setPosX(tmp->getPosX()+p.getPosX());
    tmp->setPosY(tmp->getPosY()+p.getPosY());
    
    return *tmp;
}
Point2D& Point2D::operator-(Point2D &p)
{
    Point2D *tmp= new Point2D(getPosX(), getPosY());
    tmp->setPosX(tmp->getPosX()-p.getPosX());
    tmp->setPosY(tmp->getPosY()-p.getPosY());
    
    return *tmp;
}
Point2D& Point2D::operator/(float d)
{
    Point2D *tmp= new Point2D(getPosX(), getPosY());
    tmp->setPosX(tmp->getPosX()/d);
    tmp->setPosY(tmp->getPosY()/d);
    
    return *tmp;
}*/
