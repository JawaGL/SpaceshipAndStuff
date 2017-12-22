//
//  MenuBuy.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "MenuBuy.h"
int MenuBuy::SelectedMenuItem(unsigned char key)
{
    
    int ret=0;
    for (ItemMenuBuy * im: _vImb)
    {
        float r=1.0,b=1.0;
        if(im->getKey()==key)
        {
            r=0.0;
            b=0.0;
            ret= im->getPrice();
        }
        im->setColorName(r, 1.0, b);
            
    }
    return ret;
}
void MenuBuy::checkBuyable(float score)
{
    for (ItemMenuBuy * im: _vImb)
    {
        if(im->getPrice()<=score)
        {
            im->setBuyable(true);
        }
        else
            im->setBuyable(false);
       
        
    }
}
void MenuBuy::setLaunchInfo(bool b)
{
    _lInfo=b;
}
void MenuBuy::draw()
{
    if(_lInfo)
        GraphicPrimitives::drawText2D("N to launch waves",getBeginX()+0.1*getWidth(),0.90,1.0f,1.0f, 1.0f);
    for(auto& imb:_vImb)
        imb->draw();
}
