//
//  SpacecraftHitBox.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 11/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "SpacecraftHitBox.h"
float SpacecraftHitBox::getRadius()
{
    return _radius;
}

bool SpacecraftHitBox::operator&(HitBox * hitbox)
{
  /*  float dist=0;
    dist= sqrtf(pow((getCenter()->getPosX()- hitbox->getMostExternalPoint()->getPosX()),2)
                +pow((getCenter()->getPosY()- hitbox->getMostExternalPoint()->getPosY()),2));
    if(dist<getRadius())
    {
        std::cout<<"HITTED\n";
        return true;
    }*/
    float xTarget= hitbox->getMostExternalPoint()->getPosX();
    
    if(xTarget<getMostExternalPoint()->getPosX() &&
       getCenter()->getPosX() < xTarget &&
        (
          (int)(this->getCenter()->getPosY()*100)+2> (int)(hitbox->getCenter()->getPosY()*100)
          &&
          (int)(this->getCenter()->getPosY()*100)-2< (int)(hitbox->getCenter()->getPosY()*100))
       
       )
    { /*  std::cout<<"Pos spacecraft: "<<(int)(getCenter()->getPosY()*100)<<std::endl;
        std::cout<<"Pos aste: "<<(int)(hitbox->getCenter()->getPosY()*100)<<std::endl;*/
        return true;}
    return false;
}
