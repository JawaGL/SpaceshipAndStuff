//
//  Environment.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef Environment_h
#define Environment_h
#include <stdio.h>
#include "CombatSpacecraft.h"
#include "GraphicalInterface.h"
#include "DeathStar.h"
#include "Serenity.h"
#include "Enterprise.h"
#include "Asteroid.h"
#include "AverageAsteroid.h"
#include "WarpingAsteroid.h"
#include "EllipticalAsteroid.h"
#include "SpawnEngine.h"
class Environment{
private:
   static Environment * _pEnvironment;
   
    std::vector <CombatSpacecraft *> *_pSpacecrafts;
    std::vector <Asteroid * > *_pAsteroids;
     //vector <asteroid>
    GraphicalInterface *_gui;
    SpawnEngine * _shIvA;
    int _SpacecraftType=0, _nbAsteroid=0, _nbWaves=0, _Score=200,_currentSelectedPrice=0, refreshCpt=1, _baseScore=200;
    bool _end;

    Environment(){}
public:
    static Environment * instance();
    
    void setSpacraftType(int t);
    void init();
    void draw();
    void act();
    void click(float x, float y);
    void keyPress(unsigned char key);
    bool checkBoard(int col, int row);
    bool checkLos(float x, float y);
    CombatSpacecraft * getShipAhead(int row, int col);
    CombatSpacecraft * stopShipBehind(int row, int col);
    void gameOver();
    std::vector<Asteroid *> * getAsteroidOnLane(int row);
   
};
#endif /* Environement_h */
