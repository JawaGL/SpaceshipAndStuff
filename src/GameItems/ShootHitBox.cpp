//
//  ShootHitBox.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 11/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "ShootHitBox.h"
void ShootHitBox::setHead(float x, float y)
{
    _head->setPosX(x);
    _head->setPosY(y);
}
void ShootHitBox::setTail(float x, float y)
{
    _tail->setPosX(x);
    _tail->setPosY(y);
}
Point2D * ShootHitBox::getHead()
{
    if(getCenter()->getPosX()< _head->getPosX())
        return _head;
    else
        return _tail;
}
Point2D * ShootHitBox::getTail()
{
    if(getCenter()->getPosX()>= _head->getPosX())
        return _head;
    else
        return _tail;
}
void ShootHitBox::move(Point2D *head, float direction,float amplitude, float angle)
{
   setHead(head->getPosX(), head->getPosY());
   setTail(head->getPosX() - cos(GeometricalItem::getRad(direction))*_length,
            head->getPosY() - sin(GeometricalItem::getRad(direction))*_length);
    getCenter()->setPosX(getCenter()->getPosX() + cos(GeometricalItem::getRad(angle)) * amplitude);
    getCenter()->setPosY(getCenter()->getPosY() + sin(GeometricalItem::getRad(angle)) * amplitude);
    //std::cout<< "X tail: "<< getTail()->getPosX()<< "Direction : "<<direction<<std::endl;
    
}
bool ShootHitBox::operator&(HitBox * hitbox)
{
    //downcast of the hitbox object to Asteroidhitbox for the test
  /*  if(//Lower than the top of the hitbox
       getHead()->getPosY() <= ((AsteroidHitBox*)hitbox)->getLeftUpCorner()->getPosY() &&
       //farther than the left side of the hitbox
       getHead()->getPosX() >= ((AsteroidHitBox*)hitbox)->getLeftUpCorner()->getPosX() &&
       //higher than the bottom of the hitbox
       getHead()->getPosY() >= ((AsteroidHitBox*)hitbox)->getLeftBotCorner()->getPosY() &&
       //earlier than the right side of the hitbox
       getTail()->getPosX() <= ((AsteroidHitBox*)hitbox)->getRightUpCorner()->getPosX() &&
       //tail must also be lower than the top of the hitbox
       getTail()->getPosY() <= ((AsteroidHitBox*)hitbox)->getLeftUpCorner()->getPosY() &&
       //tail must also be higher than the top of the hitbox
       getTail()->getPosY() >= ((AsteroidHitBox*)hitbox)->getLeftBotCorner()->getPosY()
       )
        return true;*/
        if(((getHead()->getPosX() <= ((AsteroidHitBox*)hitbox)->getLeftUpCorner()->getPosX() ||
       getTail()->getPosX() >= ((AsteroidHitBox*)hitbox)->getRightUpCorner()->getPosX()))||
          ! (
           (int)(this->getCenter()->getPosY()*100)+7> (int)(hitbox->getCenter()->getPosY()*100)
            &&
            (int)(this->getCenter()->getPosY()*100)-7< (int)(hitbox->getCenter()->getPosY()*100)))
    {
        /*std::cout<<"Condition: "
        <<( getHead()->getPosX() >= ((AsteroidHitBox*)hitbox)->getLeftUpCorner()->getPosX())
        << (getTail()->getPosX() <= ((AsteroidHitBox*)hitbox)->getRightUpCorner()->getPosX())
        << ((this->getCenter()->getPosY()*100)!= (int)(hitbox->getCenter()->getPosY()*100))<<std::endl;*/

       /* if(getHead()->getPosX() >= ((AsteroidHitBox*)hitbox)->getLeftUpCorner()->getPosX() &&
           getTail()->getPosX() <= ((AsteroidHitBox*)hitbox)->getRightUpCorner()->getPosX())
        {std::cout<<"Shoot y: "<<(int)(100*getCenter()->getPosY())<<std::endl;
            std::cout<< "Aste y: "<<(int)(100*hitbox->getCenter()->getPosY())<<std::endl;}*/
        

        return false;
    }
    
    return true;
}
