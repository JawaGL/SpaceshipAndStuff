//
//  InterfaceComponent.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include <stdio.h>
#include "InterfaceComponent.h"


void InterfaceComponent::setWidth(float w)
{
    _width=w;
}
void InterfaceComponent::setHeight(float h)
{
    _height=h;
}
void InterfaceComponent::setOrigint(Point2D p)
{
    _origin=p;
}
void InterfaceComponent::calculateEnds()
{
    _endX=_origin.getPosX()+_width;
    _endY=_origin.getPosY()+_height;
   // std::cout<< _endY<<std::endl;
    _beginX=_origin.getPosX();
    _beginY=_origin.getPosY();
}


Point2D InterfaceComponent::getOrigin()
{
    return _origin;
}
float InterfaceComponent::getHeight()
{
    return _height;
}
float InterfaceComponent::getWidth()
{
    return _width;
}
float InterfaceComponent::getEndX()
{
    return _endX;
}
float InterfaceComponent::getEndY()
{
    return _endY;
}
float InterfaceComponent::getBeginX()
{
    return _beginX;
}
float InterfaceComponent::getBeginY()
{
    return _beginY;
}
