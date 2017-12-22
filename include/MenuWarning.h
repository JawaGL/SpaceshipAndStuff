//
//  MenuWarning.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef MenuWarning_h
#define MenuWarning_h
#include "InterfaceComponent.h"
#include "GraphicPrimitives.h"

#include <string>
#include <stdio.h>


class MenuWarning: public InterfaceComponent{
private:
    char * _pwarning=NULL;
public:
	MenuWarning() : InterfaceComponent(), _pwarning(new char[2]{' ', '\0'}) {
   // std::cout<<__FUNCTION__<< std::endl;
    }
    MenuWarning(char * war, Point2D const & p, float h, float w): InterfaceComponent(p,h,w), _pwarning(new char [strlen(war)+1]){
        strcpy(_pwarning, war);
    //    std::cout<<__FUNCTION__<< std::endl;
    
    }
    ~MenuWarning(){
        delete[] _pwarning;
    }
    
    //get /set
    char * getWarning();
    
    void setWarning(char const * war);
    
    //method
    
    void draw();
};
#endif /* MenuWarning_h */
