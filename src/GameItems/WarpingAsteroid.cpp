//
//  WarpingAsteroid.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "WarpingAsteroid.h"

Point2D* WarpingAsteroid::getInferiorLeftCorner()
{
    return _ilC;
}
void WarpingAsteroid::setInferiorLeftCorner(float x, float y)
{
    _ilC->setPosX(x);
    _ilC->setPosY(y);
}
void WarpingAsteroid::rotateArround(float x, float y, float angle)
{
    //NOT IMPLEMENTED
}
void WarpingAsteroid::translate(float amplitude, float angle)
{
    
    if(_cptWarp%_freqWarp==0)
    {
        if(getCenter()->getPosY()+_sizeCase> _endBoardY || getCenter()->getPosY()+_sizeCase< _beginBoardY)
        {
            _sizeCase=-_sizeCase;
        }
        getCenter()->setPosY(getCenter()->getPosY()+_sizeCase);
        getInferiorLeftCorner()->setPosY(getInferiorLeftCorner()->getPosY()+_sizeCase);
        _sizeCase=-_sizeCase;
        //std::cout<<"WARP\n"<<_cptWarp<< " "<<_freqWarp<<" "<<_sizeCase<< " Pos Y"<< getInferiorLeftCorner()->getPosY()<<std::endl;
    }
    _cptWarp++;
    setCenter(getCenter()->getPosX()+amplitude*cos(getRad(angle)), getCenter()->getPosY()+amplitude*sin(getRad(angle)));
    setInferiorLeftCorner(getInferiorLeftCorner()->getPosX()+amplitude*cos(getRad(angle)), getInferiorLeftCorner()->getPosY()+amplitude*sin(getRad(angle)));
    getHitbox()->move(getCenter());
    
}
void WarpingAsteroid::draw()
{
    GraphicPrimitives::drawFillRect2D(getInferiorLeftCorner()->getPosX(), getInferiorLeftCorner()->getPosY(), getWidth(), getLength(), R, G, B);
}
void WarpingAsteroid::act()
{
    translate(getSpeed(), 180.);
}
