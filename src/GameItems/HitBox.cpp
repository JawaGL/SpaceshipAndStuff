//
//  HitBox.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 11/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "HitBox.h"
Point2D * HitBox::getCenter()
{
    return  _center;
}
void HitBox::setCenter(float x, float y)
{
    _center->setPosX(x);
    _center->setPosY(y);
}
Point2D * HitBox::getMostExternalPoint()
{
    return _mostExternalPoint;
}
