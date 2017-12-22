//
//  Asteroid.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 10/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef Asteroid_h
#define Asteroid_h
#include "GeometricalItem.h"
#include "Point2D.h"
#include "AsteroidHitBox.h"
#include <stdio.h>
class Asteroid: public GeometricalItem{
private:
    Point2D * _center;
    AsteroidHitBox * _hitbox;
    int _life;
    int _killMoney;
    float _speed;
    float _width;
    float _length;
    
public:
    Asteroid(float x, float y, int life, int killMoney, float speed, float w, float l): _center(new Point2D(x,y)), _life(life), _killMoney(killMoney), _speed(speed), _width(w),_length(l),_hitbox(new AsteroidHitBox(x, y, w, l))
    {
    }
	Asteroid(const Asteroid & a) = delete;
    virtual ~Asteroid()
    {
        delete _center;
        delete _hitbox;
    }
    void setCenter(float x, float y);
    Point2D * getCenter();
    void setLife(int life);
    int getLife();
    void setKillMoney(int km);
    int getKillMoney();
    void setSpeed(float s);
    float getSpeed();
    float getWidth();
    void setWidth(float w);
    float getLength();
    void setLength(float l);
    AsteroidHitBox * getHitbox();
    bool checkAlive();
    virtual void damage(int pt);
    
    //method
    virtual void rotateArround(float x, float y, float angle)=0;
    virtual void draw()=0;
    virtual void translate(float amplitude, float angle)=0;
    virtual void act()=0;
    
};
#endif /* Asteroid_h */
