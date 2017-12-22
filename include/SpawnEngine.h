//
//  SpawnEngine.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 12/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef SpawnEngine_h
#define SpawnEngine_h
#include "Asteroid.h"
#include "WarpingAsteroid.h"
#include "AverageAsteroid.h"
#include "EllipticalAsteroid.h"
#include <stdio.h>
#include <vector>
class SpawnEngine {
private:
    int _cptSpawnAste, _freqSpawnAste, _freqBaseSpawnAste, _nbBaseAste,_nbMaxLane, cptSpawnedAste,  nbTypeAste, cptIncDiff;
    int  cptSpawnedAverage, cptSpawenedStrong;
    std::vector<Asteroid* >* _pAste;
    float _difficultyIncrement;
    float _laneIncrement, _nbSpawnLane;
    float _difficultyLevel;
    bool _start;
    
    float _sizeCaseY, _spawnAncrageX, _beginBoardY;
    
    std::vector<int> * pvRows;
    
public:
    SpawnEngine(int freqSpawn, int nbBaseAste, std::vector<Asteroid*> * pAste, float difficultyIncrement, int nbMaxLane, float sizeCaseY, float spawnAncrageX, float beginBoardY):
    _sizeCaseY(sizeCaseY),
    _spawnAncrageX(spawnAncrageX),
    _beginBoardY(beginBoardY),
    _cptSpawnAste(0),
    _freqSpawnAste(freqSpawn),
    _nbBaseAste(nbBaseAste),
    _pAste(pAste),
    _difficultyIncrement(difficultyIncrement),
    _difficultyLevel(1.),
    _nbSpawnLane(1),
    _nbMaxLane(nbMaxLane),
    _laneIncrement(0.2),
    _start(false),
    cptSpawnedAste(0),
    nbTypeAste(1),
    cptSpawnedAverage(0),
    cptSpawenedStrong(0),
    cptIncDiff(1),
    
    pvRows(new std::vector<int>),
    _freqBaseSpawnAste(freqSpawn)
    {
        int Rownum;
        bool exist=false;
        
        while(_nbSpawnLane> pvRows->size())
        {
            Rownum=rand()%_nbMaxLane;
            
            for(int r: *pvRows)
            {
                if(r==Rownum)
                {
                    exist=true;
                    break;
                }
            }
            if(!exist)
                pvRows->push_back(Rownum);
        }
    }
    SpawnEngine(int freqSpawn, int nbBaseAste, std::vector<Asteroid*> * pAste, float difficultyIncrement, int nbMaxLane, float sizeCaseY, float spawnAncrageX, float beginBoardY, int startwave):
    _sizeCaseY(sizeCaseY),
    _spawnAncrageX(spawnAncrageX),
    _beginBoardY(beginBoardY),
    _cptSpawnAste(0),
    _freqSpawnAste(freqSpawn*(1.+(1-difficultyIncrement))),
    _nbBaseAste(nbBaseAste),
    _pAste(pAste),
    _difficultyIncrement(difficultyIncrement),
    _difficultyLevel(1.),
    _nbSpawnLane(1),
    _nbMaxLane(nbMaxLane),
    _laneIncrement(0.2),
    _start(false),
    cptSpawnedAste(0),
    nbTypeAste(1),
    cptSpawnedAverage(0),
    cptSpawenedStrong(0),
    cptIncDiff(1),
    pvRows(new std::vector<int>),
    _freqBaseSpawnAste(freqSpawn)
    {
        int Rownum;
        bool exist=false;
        
        while(_nbSpawnLane> pvRows->size())
        {
            Rownum=rand()%_nbMaxLane;
            
            for(int r: *pvRows)
            {
                if(r==Rownum)
                {
                    exist=true;
                    break;
                }
            }
            if(!exist)
                pvRows->push_back(Rownum);
        }
        for(int i=0; i<startwave; i++)
        {
            IncDifficulty();
        }
    }
    ~SpawnEngine()
    {
        for(auto it= _pAste->begin(); it!=_pAste->end();)
        {
            
            delete (*it);
            
            
            
        }
      /*  for(Asteroid* a: *_pAste)
        {
            delete a;
        }*/
        delete pvRows;
    }
    //get/set
    int getNbAste();
    ;
    int getRemainingAste();
    //method
    void start();
    void SpawnAste();
    bool CheckSpawnAste();
    void IncDifficulty();
    void act();
    bool isRunning();
    void gameOver();
};
#endif /* SpawnEngine_h */
