//
//  MenuSpacecraft.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "MenuSpacecraft.h"

char * MenuSpacecraft::getName() const
{
    return _pName;
}
void MenuSpacecraft::setName(char *name)
{
    if(_pName !=NULL)
    {
       delete [] _pName;
    }
    _pName=new char [strlen(name)+1];
    strcpy(_pName, name);
}

void MenuSpacecraft::draw()
{
    Spacecraft::draw();
    rotateArround(getGravityX(), getGravityY(), 0.5);
}
void MenuSpacecraft::translate(float amplitude, float angle)
{
    //NOT IMPLEMENTED
}
