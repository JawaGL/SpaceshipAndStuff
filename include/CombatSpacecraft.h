//
//  CombatSpacecraft.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//


#ifndef CombatSpacecraft_h

#define CombatSpacecraft_h
#include "Spacecraft.h"
#include "SpacecraftHitBox.h"
#include "Asteroid.h"


#include <stdio.h>
//Forward declaration (not working solution)
/*
class DeathStar;
class Enterprise;
class Serenity;*/

class CombatSpacecraft: public Spacecraft{
private:
    SpacecraftHitBox * _hitbox;
    float _radius, _shootSpeed;
    int _shootFreq,_baseshootFreq,
    //cpt of cycle where we canot shoot, cycling between 1 and _shootFreq
    _cptHeatDispertion,
    _shootPower, _baseshootPower;
    bool _alive;
public:
    CombatSpacecraft(float x, float y, float direction, float side, float R, float G, float B, float price, float shootSpeed, int shootPower, int shootFreq):
    Spacecraft(x,y, direction, side, R,G,B,price),
    _shootSpeed(shootSpeed),
    _shootPower(shootPower),
    _baseshootPower(shootPower),
    _shootFreq(shootFreq),
    _baseshootFreq(shootFreq),
    _cptHeatDispertion(0),
    _hitbox(new SpacecraftHitBox(getGravityX(), getGravityY(), side)),
    _alive(true)
    {
        //std::cout<<__FUNCTION__<< std::endl;
    }
	//Copy constructor not usable
	CombatSpacecraft(const CombatSpacecraft  & cs) = delete;
    virtual ~CombatSpacecraft()
    {
        delete _hitbox;
    }
   //get /set
    float getRadius()const;
    float getShootSpeed() const;
    int getShootFreq() const;
    int getCptHeat() const;
    int getShootPower() const;
    void setShootPower(const int);
    void setShootFreq(const int);
    SpacecraftHitBox * getHitbox();
    void rstCptHeat();
    void IncCptHeat();
    bool isAlive();
    void kill(); 
    virtual void stopShoots()=0;
    //method
    virtual void shoot()=0;
    virtual int collidingShoot(std::vector<Asteroid *> * pvast)=0;
    void translate(float amplitude, float angle);
    
    int operator&(std::vector<Asteroid *> * pvast);
    //Not working without heavy down cast in the environment or template
    /*void operator+( DeathStar* d);
    void operator+( Enterprise* e);
    void operator+( Serenity* s);
    void operator-( DeathStar* d);
    void operator-( Enterprise* e);
    void operator-( Serenity* s);*/
    void operator+(CombatSpacecraft* cs);
    void operator-(CombatSpacecraft* cs);
    void unbuff();
    
};
#endif /* CombatSpacecraft_h */
