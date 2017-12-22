#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Papillon.h"
#include "Board.h"
#include "MenuWarning.h"
#include "MenuScore.h"
#include "MenuBuy.h"
#include "Environment.h"
class MyGraphicEngine:public GraphicEngine {
    
    Environment * _envi;
    std::vector<Papillon * > *paps;
    Board b;
    MenuWarning mw;
    MenuScore ms;
    //MenuBuy mb;
    char * str;
    
public:
    
    MyGraphicEngine(std::vector<Papillon * > * paps_):
        paps(paps_),
    str(new char[13]{'C','l','i','c',' ','&',' ','E','n','j','o','y','\0'}),
        x1(0.5f),
        x2(-0.5f),
        vx1(0.01),
        vx2(-0.02), b(12, 12,Point2D(-0.68, -0.84), 1.68, 1.68), mw("Toto fait du bateau", Point2D(-0.68, -1.0), 0.16,1.68), ms(Point2D(-0.68, 0.84), 0.16,1.68)//,
       // mb(Point2D(-1, -0.86), 1.68,0.32)
        {
            
            
        
        }
    MyGraphicEngine(Environment * envi):_envi(envi)
    {
        
    }
    
    float x1,x2,vx1,vx2;
    
    virtual void Draw();
    
};
