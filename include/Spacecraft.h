//
//  Spacecraft.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef Spacecraft_h
#define Spacecraft_h
#include "GeometricalItem.h"
#include "InterfaceComponent.h"
#include "GraphicPrimitives.h"
#include <stdio.h>
class Spacecraft: public GeometricalItem{
private:
    //points by reference to avoid the creation en destruction of instances when we call the copy
    //constructor since spacecrafts will be created and destructed very often
    Point2D* _pOrigin=NULL;
    Point2D* _pP1=NULL;
    Point2D* _pP2=NULL;
    Point2D* _pGravity=NULL;
    float _direction,/*lenght of 1 side of the equilateral triangle*/_side, _R, _G,_B, _price;
    //private methods only used inside the class
    void calculateP1();
    void calculateP2();
    void calculatePoints();
    void calculateGravity();
public:
    Spacecraft():_pOrigin(new Point2D()),_pP1(new Point2D()),_pP2(new Point2D()), _direction(0), _side(0), _R(0), _G(0),_B(0), _price(0){
        calculatePoints();
        calculateGravity();
      //  std::cout<<__FUNCTION__<< std::endl;
    }
    
    Spacecraft(float x, float y, float direction, float side, float R, float G, float B, float price):_pOrigin(new Point2D(x,y)), _direction(direction), _side(side), _R(R), _G(G),_B(B), _price(price)
    {
    
        calculatePoints();
        calculateGravity();
     //   std::cout<<__FUNCTION__<< std::endl;
    }
    Spacecraft(Spacecraft const & s)
    {
        //std::cout<<"COPY SpaceCraft" << std::endl;

        if(_pOrigin!=NULL)
            delete _pOrigin;
               
        _pOrigin= new Point2D(s._pOrigin->getPosX(),s._pOrigin->getPosY());
        _direction=s.getDirection();
        _side=s.getSide();
        _R=s.getRed();
        _G=s.getGreen();
        _B=s.getBlue();
        _price=s.getPrice();
        
        calculatePoints();
        calculateGravity();
        //std::cout<<__FUNCTION__<< std::endl;
    }
    virtual ~Spacecraft(){
        delete _pOrigin;
        delete _pP1;
        delete _pP2;
        delete _pGravity;
        
        
    }
    //get/set
    Point2D * getOrigin() const ;
    float getDirection() const;
    void setDirection(float angle);
    
    float getSide() const;
    void setSide(float side);
    
    float getRed() const;
    float getGreen() const;
    float getBlue() const;
    void setColor(float r, float g, float b);
    
    float getPrice() const;
    void setPrice(float price);
    
    float getGravityX();
    float getGravityY();
    //method
    
    void rotateArround(float x, float y, float angle);
    virtual void translate(float amplitude, float angle)=0;
    virtual void draw();

    
};
#endif /* Spacecraft_h */
