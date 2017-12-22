//
//  AsteroidHitBox.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 11/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "AsteroidHitBox.h"
float AsteroidHitBox::getWidth() const
{
    return _width;
}
float AsteroidHitBox::getLength() const
{
    return _length;
}
void AsteroidHitBox::move(float amplitude, float angle)
{
    _leftBotCorner->setPosX(_leftBotCorner->getPosX()+cos(GeometricalItem::getRad(angle))*amplitude);
    _leftBotCorner->setPosY(_leftBotCorner->getPosY()+sin(GeometricalItem::getRad(angle))*amplitude);
    _leftUpCorner->setPosX(_leftUpCorner->getPosX()+cos(GeometricalItem::getRad(angle))*amplitude);
    _leftUpCorner->setPosY(_leftUpCorner->getPosY()+sin(GeometricalItem::getRad(angle))*amplitude);
    _rightBotCorner->setPosX(_rightBotCorner->getPosX()+cos(GeometricalItem::getRad(angle))*amplitude);
    _rightBotCorner->setPosY(_rightBotCorner->getPosY()+sin(GeometricalItem::getRad(angle))*amplitude);
    _rightUpCorner->setPosX(_rightUpCorner->getPosX()+cos(GeometricalItem::getRad(angle))*amplitude);
    _rightUpCorner->setPosY(_rightUpCorner->getPosY()+sin(GeometricalItem::getRad(angle))*amplitude);
    setCenter(getCenter()->getPosX()+cos(GeometricalItem::getRad(angle))*amplitude,
              getCenter()->getPosY()+sin(GeometricalItem::getRad(angle))*amplitude);
}
void AsteroidHitBox::move(Point2D *center)
{
    setCenter(center->getPosX(), center->getPosY());
   
    
    _leftBotCorner->setPosX(getCenter()->getPosX()-_length/2);
    _leftBotCorner->setPosY(getCenter()->getPosY()-_width/2);
    _leftUpCorner->setPosX(getCenter()->getPosX()-_length/2);
    _leftUpCorner->setPosY(getCenter()->getPosY()+_width/2);
    _rightBotCorner->setPosX(getCenter()->getPosX()+_length/2);
    _rightBotCorner->setPosY(getCenter()->getPosY()-_width/2);
    _rightUpCorner->setPosX(getCenter()->getPosX()+_length/2);
    _rightUpCorner->setPosY(getCenter()->getPosY()+_width/2);
    getMostExternalPoint()->setPosX(getCenter()->getPosX()-_length/2);
    getMostExternalPoint()->setPosY(getCenter()->getPosY());
}
Point2D * AsteroidHitBox::getLeftBotCorner()
{
    return _leftBotCorner;
}
Point2D * AsteroidHitBox::getLeftUpCorner()
{
    return _leftUpCorner;
}
Point2D * AsteroidHitBox::getRightBotCorner()
{
    return _rightBotCorner;
}
Point2D * AsteroidHitBox::getRightUpCorner()
{
    return _rightUpCorner;
}
bool AsteroidHitBox::operator&(HitBox* hitbox)
{
    float xTarget= hitbox->getMostExternalPoint()->getPosX();
    float yTarget=hitbox->getMostExternalPoint()->getPosY();
    
    if(//incoming item must be farther than the left side
       xTarget>getLeftBotCorner()->getPosX() &&
       //incoming item must be before the righside
       xTarget< getRightBotCorner()->getPosX() &&
       //incoming item must be higher than the bot side
       yTarget> getLeftBotCorner()->getPosY()  &&
       //incoming item must be lower than the top side
       yTarget< getLeftUpCorner()->getPosY()
    )
        return true;
    return false;
}
