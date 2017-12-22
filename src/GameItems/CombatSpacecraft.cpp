//
//  CombatSpacecraft.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "CombatSpacecraft.h"
#include "DeathStar.h"
#include "Enterprise.h"
#include "Serenity.h"
float CombatSpacecraft::getRadius()const
{
    return _radius;
}
float CombatSpacecraft::getShootSpeed() const
{
    return _shootSpeed;
}
int CombatSpacecraft::getShootFreq() const
{
    return _shootFreq;
}
int CombatSpacecraft::getCptHeat() const
{
    return _cptHeatDispertion;
}
int CombatSpacecraft::getShootPower() const
{
    return _shootPower;
}
void CombatSpacecraft::setShootPower(const int sp)
{
    _shootPower=sp;
}
void CombatSpacecraft::setShootFreq(const int sf)
{
    _shootFreq=sf;
}
void CombatSpacecraft::rstCptHeat(){
    _cptHeatDispertion=1;
}
void CombatSpacecraft::IncCptHeat(){
    _cptHeatDispertion++;
}
bool CombatSpacecraft::isAlive()
{
    return _alive;
}
void CombatSpacecraft::kill()
{
    _alive=false;
}
SpacecraftHitBox * CombatSpacecraft::getHitbox()
{
    return _hitbox;
}
void CombatSpacecraft::translate(float amplitude, float angle)
{
    //NOT IMPLEMENTED
}
int CombatSpacecraft::operator&(std::vector<Asteroid *> *pvast)
{
    int gain=0;
    gain+= collidingShoot(pvast);
    for(Asteroid * a: *pvast)
    {
        if(*getHitbox()&a->getHitbox())
        {
            kill();
        }
        
    }
    return gain;
}
void CombatSpacecraft::operator+( CombatSpacecraft* cs)
{
    if(dynamic_cast<DeathStar*>(cs)!=NULL)
    {
        _shootPower*=2;
        return;
    }
    if(dynamic_cast<Enterprise*>(cs)!=NULL)
    {
        _shootFreq=(_shootFreq*2)/3;
        return;
    }
    if(dynamic_cast<Serenity*>(cs)!=NULL)
    {
        _shootPower+=2;
        _shootFreq-=20;
        return;
    }
}
void CombatSpacecraft::operator-( CombatSpacecraft* cs)
{
    if(dynamic_cast<DeathStar*>(cs)!=NULL)
    {
        _shootPower/=2;
        return;
    }
    if(dynamic_cast<Enterprise*>(cs)!=NULL)
    {
        _shootFreq=(_shootFreq*3)/2;
        return;
    }
    if(dynamic_cast<Serenity*>(cs)!=NULL)
    {
        _shootPower-=2;
        _shootFreq+=20;
        return;
    }
    
}
void CombatSpacecraft::unbuff()
{
    _shootFreq=_baseshootFreq;
    _shootPower=_baseshootPower;
}
/*
void CombatSpacecraft::operator+( DeathStar* d)
{
    d->setShootPower(d->getShootPower()*2);
}
void CombatSpacecraft::operator+( Enterprise* e)
{
    //avoiding round down since its an int...
    e->setShootFreq((e->getShootFreq()*2)/3);
}
void CombatSpacecraft::operator+( Serenity* s)
{
    s->setShootFreq(s->getShootFreq()-20);
    s->setShootPower(s->getShootPower()+2);
   
}
void CombatSpacecraft::operator-( DeathStar* d)
{
     d->setShootPower(d->getShootPower()/2);

}
void CombatSpacecraft::operator-( Enterprise* e)
{
    e->setShootFreq((e->getShootFreq()*3)/2);
}
void CombatSpacecraft::operator-( Serenity* s)
{
    s->setShootFreq(s->getShootFreq()+20);
    s->setShootPower(s->getShootPower()-2);
}
 */

