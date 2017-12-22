//
//  MenuWarning.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "MenuWarning.h"

char * MenuWarning::getWarning()
{
    return _pwarning;
}

void MenuWarning::setWarning(const char  * war)
{
    if(_pwarning != NULL)
    {
        delete[] _pwarning;
    }
    _pwarning=new char[strlen(war)+1];
    strcpy(_pwarning, war);
}


void MenuWarning::draw()
{
    

    GraphicPrimitives::drawText2D(_pwarning,getBeginX()+0.1*getWidth(),getBeginY()+getHeight()/3,1.0f,0.0f, 0.0f);
}
