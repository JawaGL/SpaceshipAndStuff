//
//  MenuSpacecraft.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef MenuSpacecraft_h
#define MenuSpacecraft_h
#include "Spacecraft.h"
#include "GraphicPrimitives.h"
#include <stdio.h>
class MenuSpacecraft: public Spacecraft{
private:
    char * _pName= NULL;
public:
    MenuSpacecraft(): Spacecraft(), _pName(NULL){
       // std::cout<<__FUNCTION__<< std::endl;
    }
    MenuSpacecraft(char * name,float x, float y, float direction, float side, float R, float G, float B, float price):Spacecraft(x,y,direction,side,R,G,B,price), _pName(new char[strlen(name)+1])
    {
        strcpy(_pName, name);
       // std::cout<<__FUNCTION__<< std::endl;
    }
    ~MenuSpacecraft(){
        delete [] _pName;
    }
    MenuSpacecraft(MenuSpacecraft const & ms):Spacecraft(ms)
    {
        //std::cout<<"COPY MenuSpacecraft" << std::endl;

        setName(ms.getName());
    }
    
    //get/set
    char * getName() const;
    void setName(char * name);
    //method
    virtual void draw();
    virtual void translate(float amplitude, float angle);
};
#endif /* MenuSpacecraft_h */
