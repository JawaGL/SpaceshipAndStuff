//
//  MenuScore.c
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "MenuScore.h"
//private getter/setter
char* MenuScore::getmsgWaves()
{
    return _msgWave;

}

char* MenuScore::getmsgAsteroids()
{
    return _msgAsteroid;
    
}
char* MenuScore::getmsgScore()
{
    return _msgScore;
    
}

void MenuScore::setWaves(char* nbWaves)
{
    if(_msgWave!=NULL)
        delete[] _msgWave;
    _msgWave=nbWaves;
    
}
void MenuScore::setAsteroids(char* nbAsteroids)
{
    if(_msgAsteroid!=NULL)
        delete[] _msgAsteroid;
    _msgAsteroid=nbAsteroids;
    
}
void MenuScore::setScore(char* score)
{
    if(_msgScore!=NULL)
        delete [] _msgScore;
    _msgScore=score;
    
}

//public getter setter:

int MenuScore::getWaves()
{
    return _nbWave;
}
int MenuScore::getAsteroids()
{
    return _nbAsteroid;
}
int MenuScore::getScore()
{
    return _score;
}


void MenuScore::setWaves(int nbWaves)
{
    _nbWave=nbWaves;
    std::string  msg ("Wave: ");
    
    msg+=std::to_string(_nbWave);
    
    char * wave=new char[msg.length()+1];
    strcpy(wave, msg.c_str());
    setWaves(wave);
    
}
void MenuScore::setAsteroids(int nbAsteroids)
{
    _nbAsteroid=nbAsteroids;
    std::string  msg ("Asteroid: ");
    
    msg+=std::to_string(_nbAsteroid);
    
    char * ast=new char[msg.length()+1];
    strcpy(ast, msg.c_str());
    setAsteroids(ast);
}
void MenuScore::setScore(int score)
{
    _score=score;
    std::string  msg ("Credits: ");
    
    msg+=std::to_string(_score);
    
    char * sco=new char[msg.length()+1];
    strcpy(sco, msg.c_str());
    setScore(sco);
}
void MenuScore::asteroidDestroy()
{
    setAsteroids(getAsteroids()-1);
}
void MenuScore::modifyScore(int points)
{
    setScore(getScore()+points);
}
void MenuScore::draw()
{
    GraphicPrimitives::drawText2D(getmsgWaves(),getBeginX()+0.1*getWidth(),getBeginY()+getHeight()/3,1.0f,1.0f, 1.0f);
    GraphicPrimitives::drawText2D(getmsgAsteroids(),getBeginX()+0.4*getWidth(),getBeginY()+getHeight()/3,1.0f,1.0f, 1.0f);
    GraphicPrimitives::drawText2D(getmsgScore(),getBeginX()+0.8*getWidth(),getBeginY()+getHeight()/3,1.0f,1.0f, 1.0f);
}

