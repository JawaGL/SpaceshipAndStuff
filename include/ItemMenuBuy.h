//
//  ItemMenuBuy.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef ItemMenuBuy_h
#define ItemMenuBuy_h
#include "InterfaceComponent.h"
#include "GraphicPrimitives.h"
#include "MenuSpacecraft.h"
#include <stdio.h>
class ItemMenuBuy: public InterfaceComponent{
private:
    MenuSpacecraft _ms;
    int _price;
    bool _buyable;
    unsigned char _key;
    float R=1.0,G=1.0,B=1.0;
public:
    ItemMenuBuy():InterfaceComponent(),/*ms(),*/ _price(/*ms.getPrice()*/0), _buyable(false),_key('K'){
    //std::cout<<__FUNCTION__<< std::endl;
	}
    ItemMenuBuy(MenuSpacecraft const & ms,char k, Point2D p,float h,float w): InterfaceComponent(p,h,w),_ms(ms),_price(_ms.getPrice()), _buyable (false), _key(k){
   // std::cout<<__FUNCTION__<< std::endl;
    }
    ~ItemMenuBuy(){}
    
    //get/set
    void setPrice(int price);
    void setBuyable(bool b);
    void setKey(unsigned char k);
    
    int getPrice();
    bool isBuyable();
    unsigned char getKey();
    void setColorName(float r, float g, float b);
    //method
    void updateBuyable(int score);
    void draw();
    
};
#endif /* ItemMenuBuy_h */
