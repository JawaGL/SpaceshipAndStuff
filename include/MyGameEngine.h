#pragma once

#include "Engine.h"
#include "Papillon.h"
#include "Environment.h"
class MyGameEngine:public GameEngine {
    std::vector<Papillon * > *paps;
    Environment * _envi;
public:
    
    MyGameEngine(std::vector<Papillon * > * paps_):paps(paps_){}
    MyGameEngine(Environment * env): _envi(env){}
    virtual void idle();
    
};
