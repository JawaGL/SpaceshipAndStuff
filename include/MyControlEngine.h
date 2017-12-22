#pragma once
#include "Engine.h"
#include "Papillon.h"
#include "Environment.h"
class MyControlEngine:public ControlEngine {
    std::vector<Papillon * > *paps;
    Environment * _envi=0;
public:
    MyControlEngine(std::vector<Papillon * > * paps_):paps(paps_){}
    MyControlEngine(Environment * envi_):_envi(envi_){}
   
    virtual void MouseCallback(int button, int state, int x, int y) ;
    virtual void KeyboardReleaseCallback(unsigned char key,int x, int y);
};
