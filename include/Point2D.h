//
//  Point2D.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef Point2D_h
#define Point2D_h
#include "GeometricalItem.h"
#include <iostream>



class Point2D : public GeometricalItem{
private:
    float _posX, _posY;

public:
    //Constructor
    Point2D(): GeometricalItem(), _posX(0.f), _posY(0.f){
    //std::cout<<__FUNCTION__<< std::endl;
    }
    Point2D(float posX_, float posY_):_posX(posX_), _posY(posY_){
      //  std::cout<<__FUNCTION__<< std::endl;
    }
    ~Point2D(){
     //   std::cout<<__FUNCTION__<< std::endl;

    }
    Point2D(Point2D const& p);
    //getter/setter
    float getPosX()const ;
    float getPosY()const ;
    void setPosX(float x) ;
    void setPosY(float y) ;
    //method
    void draw();
    void rotateArround(float x, float y, float angle);
    void translate(float amplitude, float angle);
    //Operator
 /*   bool operator==(Point2D& p);
    Point2D& operator=( Point2D& p);
    Point2D& operator+(Point2D& p);
    Point2D& operator/(float divisor);
    Point2D& operator-(Point2D& p);*/
};
#endif /* Point2D_h */
