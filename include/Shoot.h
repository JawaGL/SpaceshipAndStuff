//
//  Shoot.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 09/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef Shoot_h
#define Shoot_h
#include "GeometricalItem.h"
#include "Point2D.h"
#include "GraphicPrimitives.h"
#include "ShootHitBox.h"
#include "Asteroid.h"
#include <stdio.h>


class Shoot: public GeometricalItem {
private:
    Point2D * _head=NULL;
    float _length, _speed, _power ,_direction;
protected:
    ShootHitBox * _hitbox;

public:
    //constructors
    Shoot(float x, float y, float length, float speed, float power, float direction):_head(new Point2D (x,y)),_length(length), _speed(speed), _power(power), _direction(direction),
    //ShootHitBox(float xHead, float yHead, float length)
    _hitbox(new ShootHitBox(x, y, length))
    {
    //    std::cout<<__FUNCTION__<< std::endl<< cpt<< std::endl;
        
    }
    virtual ~Shoot(){
        //std::cout<<"DESTRUCTION SHOOT"<<std::endl;
        delete _head;
        delete _hitbox;
    }
    
    //getSet
    Point2D * getHead() const;
    void setHead(float x, float y);
    
    float getLength() const;
    void setLength(float l);
    
    float getSpeed() const;
    void setSpeed(float s);
    
    float getPower() const;
    void setPower(float p);
    
    float getDirection() const;
    void setDirection(float d);
    
    float getX2() const;
    float getY2() const;
    
    ShootHitBox* getHitbox();
    bool checkAlive() const;
    //method
   // void translate(float amplitude, float angle);
    virtual void draw();
    virtual void act()=0;
    virtual void die();
    int operator&(std::vector<Asteroid * > * pVecAst);
    
    
    
};
#endif /* Shoot_h */
