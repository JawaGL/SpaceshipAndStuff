//
//  HitBox.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 11/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef HitBox_h
#define HitBox_h
#include "Point2D.h"
#include "GeometricalItem.h"
#include <stdio.h>
class HitBox{
    
private:
    Point2D * _center;
    Point2D * _mostExternalPoint;
public:
    HitBox(float x, float y, float x2, float y2): _center(new Point2D (x,y)), _mostExternalPoint(new Point2D(x2,y2)){
        
    }
    virtual ~HitBox(){
        delete _center;
        delete _mostExternalPoint;
    }
    
    Point2D * getCenter();
    void setCenter(float x, float y);
    virtual Point2D * getMostExternalPoint();
    virtual bool operator&(HitBox * item)=0;
};
#endif /* HitBox_h */
