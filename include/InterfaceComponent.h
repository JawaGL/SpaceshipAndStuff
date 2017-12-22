//
//  InterfaceComponent.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef InterfaceComponent_h
#define InterfaceComponent_h

#include "Point2D.h"
class InterfaceComponent{
private:
    Point2D _origin;
    float _height;
    float _width;
    float _endX;
    float _endY;
    float _beginX;
    float _beginY;
    
public:
    //c**onstructor
    InterfaceComponent(): _origin(),_height(0),_width(0), _endX(0), _endY(0), _beginX(0), _beginY(0){
   // std::cout<<__FUNCTION__<< std::endl;
	}
    InterfaceComponent(Point2D const & p, float height, float width): _origin(p), _height(height), _width(width), _endX(p.getPosX()+width), _endY(p.getPosY()+width), _beginX(p.getPosX()), _beginY(p.getPosY()){
   // std::cout<<__FUNCTION__<< std::endl;
    }
    virtual ~InterfaceComponent(){
        
    }
    //get and set
    void setOrigint(Point2D p);
    void setHeight(float h);
    void setWidth(float w);
    //no need of setters these can be calculate directly from Height/width/orgin
    void calculateEnds();
    
    
    Point2D getOrigin();
    float getHeight();
    float getWidth();
    float getEndX();
    float getEndY();
    float getBeginX();
    float getBeginY();
    //method
    virtual void draw() =0;
    
    
    
};
#endif /* InterfaceComponent_h */
