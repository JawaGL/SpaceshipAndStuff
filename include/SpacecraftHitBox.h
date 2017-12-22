//
//  SpacecraftHitBox.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 11/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef SpacecraftHitBox_h
#define SpacecraftHitBox_h
#include "HitBox.h"
#include <stdio.h>

//A spacecraft has a Circular HitBox
class SpacecraftHitBox: public HitBox{
private:
    float _radius;
public:
    SpacecraftHitBox(float x, float y, float radius):HitBox(x,y, x+radius/2, y), _radius(radius/2)
    {
        
    }
    virtual ~SpacecraftHitBox()
    {
        
    }
    
    float getRadius();

    bool operator&(HitBox * item);
};
#endif /* SpacecraftHitBox_h */
