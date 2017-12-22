//
//  GeometricalItem.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <math.h>
#define PI 3.14159265

//Purely abstact class defining attributes and methods that geometrical object should have
class GeometricalItem{
private:
public:
    //constructors
    GeometricalItem(){}
    virtual ~GeometricalItem(){}
    
    
    
    //methods
    static float getRad(float angle) ;
    virtual void rotateArround(float x, float y, float angle)=0; //purely virtual method
    virtual void translate(float amplitude, float angle)=0;
    virtual void draw()=0;
    
};

#endif /* Header_h */
