//
//  ItemMenuBuy.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "ItemMenuBuy.h"
#include <string>
//get/set
void ItemMenuBuy::setPrice(int price)
{
    _price=price;
}
void ItemMenuBuy::setBuyable(bool b)
{
    _buyable=b;
}
void ItemMenuBuy::setKey(unsigned char k)
{
    _key=k;
}


int ItemMenuBuy::getPrice()
{
    return _price;
}

bool ItemMenuBuy::isBuyable()
{
    return _buyable;
}

unsigned char ItemMenuBuy::getKey()
{
    return _key;
}

//method
void ItemMenuBuy::updateBuyable(int score)
{
    setBuyable((score>getPrice()));
}
void ItemMenuBuy::setColorName(float r, float g, float b)
{
    R=r;
    G=g;
    B=b;
}
void ItemMenuBuy::draw()
{
    _ms.draw();
    std::string  name (_ms.getName());
    std::string price(std::to_string(getPrice()));
	char keyc = getKey();
    char * pKey= new char[2];
	pKey[0] = keyc;
	pKey[1] = '\0';
    char * pName=new char[name.length()+1];
    strcpy(pName, name.c_str());
    char * pPrice=new char[price.length()+1];
    strcpy(pPrice, price.c_str());
    float g=0.0,b=0.0;
    if(isBuyable())
    {
        g=1.0;
        b=1.0;
    }
    GraphicPrimitives::drawText2D(pName,getBeginX()+0.25*getWidth(),getBeginY()+getHeight()/3,R,G, B);
    GraphicPrimitives::drawText2D(pPrice,getBeginX()+0.45*getWidth(),getBeginY()+getHeight()/3-0.1*getHeight(),1.0f,g, b);
    GraphicPrimitives::drawText2D(pKey,getBeginX()+0.5*getWidth(),getBeginY()+getHeight()/3-0.2*getHeight(),1.0f,1.0f, 1.0);
	delete pKey;
}
