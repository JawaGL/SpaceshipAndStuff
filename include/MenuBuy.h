//
//  MenuBuy.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef MenuBuy_h
#define MenuBuy_h
#include "InterfaceComponent.h"
#include "ItemMenuBuy.h"
#include "MenuSpacecraft.h"
#include <stdio.h>
#include <vector>
class MenuBuy : public InterfaceComponent{
private:
    std::vector<ItemMenuBuy*> _vImb;
    bool _lInfo;
public:
    MenuBuy(Point2D p, float h, float w): InterfaceComponent(p, h, w), _lInfo(true){
        //menu directly create the spacecraft type that can be buy. ==> Not generical
        //other solution is to let the environment do so by using reflexion on spacecraft hierarchy
       // Point2D point(getBeginX()+0.5*getWidth(), 0.84f );
       // MenuSpacecraft m("Fire", point, 90., 0.95*getWidth(), 1.0f, 0.0f, 0.0f, 100);
        
        _vImb.push_back(new ItemMenuBuy(MenuSpacecraft("Enterprise", getBeginX()+0.5*getWidth(),  getBeginY()+getHeight(), 90., 0.75*getWidth(), 1.0f, 0.0f, 0.0f, 100),'a', Point2D(getBeginX(), getBeginY()+2*getHeight()/3), getHeight()/3,getWidth()));
        _vImb.push_back(new ItemMenuBuy(MenuSpacecraft("Serenity", getBeginX()+0.5*getWidth(), getBeginY()+2*getHeight()/3, 90.,  0.75*getWidth(), 0.0f, 0.0f, 1.0f, 150),'z', Point2D(getBeginX(), getBeginY()+getHeight()/3),getHeight()/3,getWidth()));
         _vImb.push_back(new ItemMenuBuy(MenuSpacecraft("DeathStar", getBeginX()+0.5*getWidth(), getBeginY()+getHeight()/3, 90.,  0.75*getWidth(), 1.0f, 0.0f, 1.0f, 200),'e', Point2D(getBeginX(), getBeginY()), getHeight()/3,getWidth()));
        
       // std::cout<<__FUNCTION__<< std::endl;
    }
    
    //method
    //change the color of the items menu and return the price of the selected item
    int SelectedMenuItem(unsigned char key);
    void checkBuyable(float score);
    void setLaunchInfo(bool b);

    void draw();
};
#endif /* MenuBuy_h */
