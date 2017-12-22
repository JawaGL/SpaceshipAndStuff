//
//  SpawnEngine.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 12/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "SpawnEngine.h"
int SpawnEngine::getNbAste()
{
	int nbA = (int)(_nbBaseAste*(1 + cptIncDiff * _difficultyIncrement));
	if (nbA > 4 * _nbBaseAste)
		nbA = 4 * _nbBaseAste;
    return nbA;
}
int SpawnEngine::getRemainingAste()
{
	int nbA = (int)(_nbBaseAste*(1 + cptIncDiff * _difficultyIncrement));
	if (nbA > 4 * _nbBaseAste)
		nbA = 4 * _nbBaseAste;
    return nbA-cptSpawnedAste;
}
//method
void SpawnEngine::start()
{
    _start=true;
}
void SpawnEngine::SpawnAste()
{
    int typeAste= rand()%nbTypeAste;
    int indexrow = rand()%(int)(_nbSpawnLane);
    if(nbTypeAste==3 &&getRemainingAste()==1 && cptSpawenedStrong==0)
        typeAste=2;
    //float x, float y, int life, int killMoney, float speed, float w, float l
    // _pAsteroids->push_back(new AverageAsteroid(1-0.14/2, -0.84 + 0.14/2, 200, 10, 0.0005, 0.13,0.07));
    // float x, float y, int life, int killMoney, float speed, float w, float l, int freqWarp, float sizeCase
    //_pAsteroids->push_back(new WarpingAsteroid(1-0.14/2, -0.84 + 0.14/2, 100, 200, 0.0005, 0.13,0.07, 200, _gui->getSizeCaseY()));
    //_pAsteroids->push_back(new EllipticalAsteroid(1-0.14/2, -0.84 + 0.14/2, 200, 10, 0.0005, 0.13,0.07));
    float y =_beginBoardY + (*pvRows)[indexrow] * _sizeCaseY+0.5*_sizeCaseY;
    if(typeAste==2)
    {
        //create elliptical aste
        if(cptSpawenedStrong <= (int)(getNbAste()*0.1))
        {
            _pAste->push_back(new EllipticalAsteroid(_spawnAncrageX,
                                                  y,
                                                  (int) _difficultyLevel*120,
                                                  35,
                                                   (int)_difficultyLevel*0.0005,
                                                  _sizeCaseY-0.01,
                                                  _sizeCaseY/2
                                                  ));
            cptSpawenedStrong++;
        }
        else
            typeAste=1;
    }
    if(typeAste==1 )
    {
        //create Warping aste
        if(cptSpawnedAverage< (int)(getNbAste() * 0.30))
        {
            WarpingAsteroid * test=new WarpingAsteroid(_spawnAncrageX,
                                                       y,
                                                       (int) _difficultyLevel*100,
                                                       20,
                                                       (int )_difficultyLevel*0.0005,
                                                       _sizeCaseY-0.01,
                                                       _sizeCaseY/2,
                                                       200,
                                                       _sizeCaseY, _beginBoardY,_beginBoardY+(_nbMaxLane*_sizeCaseY));
            
            _pAste->push_back(test);
            
            cptSpawnedAverage++;
        }
        else
        {
            typeAste=0;
        }
    }
   
    
    
    if(typeAste==0)
    {
        //create average aste with correcti factors
        _pAste->push_back(new AverageAsteroid(_spawnAncrageX,
                                                 y,
                                                 (int) _difficultyLevel*75,
                                                 10,
                                                 (int )_difficultyLevel*0.0005,
                                                 _sizeCaseY-0.01,
                                                 _sizeCaseY/2
                                                 ));
        /*_pAste->push_back(new WarpingAsteroid(_spawnAncrageX,
                                              y,
                                              (int) _difficultyLevel*100,
                                              (int) (0.5+_difficultyLevel)*20,
                                               (int)0.001,
                                              _sizeCaseY-0.01,
                                              _sizeCaseY/2,
                                              200,
                                              _sizeCaseY, _beginBoardY,_beginBoardY+(_nbMaxLane*_sizeCaseY)));
       /* _pAste->push_back(new EllipticalAsteroid(_spawnAncrageX,
                                                 y,
                                                 (int) _difficultyLevel*400,
                                                 (int) _difficultyLevel*10,
                                                 (int) _difficultyLevel*0.001,
                                                 _sizeCaseY-0.01,
                                                 _sizeCaseY/2
                                                 ));*/
    }
    cptSpawnedAste++;
}
bool SpawnEngine::CheckSpawnAste()
{
    return _cptSpawnAste%_freqSpawnAste==0;
}
void SpawnEngine::IncDifficulty()
{
    _difficultyLevel+=_difficultyIncrement;
    if(cptIncDiff%5 ==0)
        _difficultyIncrement*=1.5;
    
    if(_nbSpawnLane<_nbMaxLane)
    {
        if(cptIncDiff%2==0)
            _nbSpawnLane+=1;
       // _nbSpawnLane+=(int)(1.-_laneIncrement);
       // _laneIncrement+=0.5;
    }
    if(_nbSpawnLane> _nbMaxLane)
        _nbSpawnLane=_nbMaxLane;
    int Rownum;
    bool exist;
    
    while(_nbSpawnLane> pvRows->size())
    {
        exist=false;
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
    
    if(1-_difficultyIncrement >=-0.5)
        _freqSpawnAste=_freqBaseSpawnAste*(1+(1-_difficultyIncrement));
    else
        _freqSpawnAste=_freqBaseSpawnAste*0.5;
    
    cptIncDiff++;
    if(_difficultyLevel>=1.9)
    {
        nbTypeAste=3;
        return;
    }

    if(_difficultyLevel>= 1.4)
    {
        nbTypeAste=2;
        return;
    }
    
}

void SpawnEngine::act()
{
    if(_start)
    {
        if(cptSpawnedAste < (int)(getNbAste()))
        {    if(CheckSpawnAste())
            {
                SpawnAste();
            }
        }
        else
        {
            _start=false;
            cptSpawnedAverage=0;
            cptSpawenedStrong=0;
            cptSpawnedAste=0;
            _cptSpawnAste=0;
            IncDifficulty();
        }
        _cptSpawnAste++;
    }
    
}
bool SpawnEngine::isRunning()
{
    return _start;
}
void SpawnEngine::gameOver()
{
    _start=false;
    cptSpawnedAverage=0;
    cptSpawenedStrong=0;
    cptSpawnedAste=0;
    _cptSpawnAste=1;
}
