//
//  EllipticalAsteroid.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 11/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "EllipticalAsteroid.h"
void EllipticalAsteroid::rotateArround(float x, float y, float angle)
{
    //NOT IMPLEMENTED
}
void EllipticalAsteroid::draw()
{
    if(! _protected)
        GraphicPrimitives::drawFillConvexPolygoneP2D(*_pX, *_pY, R, G, B);
    else
        GraphicPrimitives::drawFillConvexPolygoneP2D(*_pX, *_pY, 0., 1., 1.);
}
void EllipticalAsteroid::translate(float amplitude, float angle)
{
    for(float * x: *_pX)
    {
        //Always translate in a straight lane
        *x-=amplitude;
        
    }
    
    //Y stays
    //center X move
    getCenter()->setPosX(getCenter()->getPosX()-amplitude);
    //hitbox also move:
    getHitbox()->move(getCenter());
}
void EllipticalAsteroid::act()
{
    translate(getSpeed(), 180.);
}
void EllipticalAsteroid::damage(int pt)
{
    if(!_protected)
    {
        setLife(getLife()-pt);
        _cptShield++;
        if(_cptShield%6==0)
        {
            _protected=true;
            _cptShield=3;
        }
    }
    else
    {
        _cptShield--;
        if(_cptShield==1)
        {
            _protected=false;
        }
    }
}
