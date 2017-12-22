//
//  MenuScore.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef MenuScore_h
#define MenuScore_h
#include "InterfaceComponent.h"
#include "GraphicPrimitives.h"

#include <stdio.h>
#include <string>

class MenuScore: public InterfaceComponent {
private:
    int _nbWave;
    int _nbAsteroid;
    int _score;
    char * _msgWave;
    char * _msgAsteroid;
    char * _msgScore;
    
    //these methods are private since they need to be only used inside this class
    char* getmsgWaves();
    char* getmsgAsteroids();
    char* getmsgScore();
    
    void setWaves(char* nbWaves);
    void setAsteroids(char* nbAsteroids);
    void setScore(char* score);
    
public:
    MenuScore(): InterfaceComponent(), _nbWave(0), _nbAsteroid(0), _score(0) {
        std::string  msg1 ("Wave: ");
        std::string msg2 ("Asteroids: ");
        std::string msg3 ("Score: ");
        
        
        msg1+=std::to_string(_nbWave);
        msg2+=std::to_string(_nbAsteroid);
        msg3+=std::to_string(_score);
        
        
        _msgWave = new char[msg1.length()+1];
        strcpy(_msgWave, msg1.c_str());
        _msgAsteroid = new char[msg2.length()+1];
        strcpy(_msgAsteroid, msg2.c_str());
        _msgScore = new char[msg3.length()+1];
        strcpy(_msgScore, msg3.c_str());
     //   std::cout<<__FUNCTION__<< std::endl;
    
    }
    MenuScore(Point2D const& p, float h, float w): InterfaceComponent(p,h,w), _nbWave(0), _nbAsteroid(0), _score(0) {
        /*std::string  msg1 ("Wave: ");
        std::string msg2 ("Asteroids: ");
        std::string msg3 ("Score: ");
        
        
        msg1+=std::to_string(_nbWave);
        msg2+=std::to_string(_nbAsteroid);
        msg3+=std::to_string(_score);
        
        
        _msgWave = new char[msg1.length()+1];
        strcpy(_msgWave, msg1.c_str());
        _msgAsteroid = new char[msg2.length()+1];
        strcpy(_msgAsteroid, msg2.c_str());
        _msgScore = new char[msg3.length()+1];
        strcpy(_msgScore, msg3.c_str());*/
        _msgScore=NULL;
        _msgAsteroid=NULL;
        _msgWave=NULL;
        setScore(_score);
        setWaves(_nbWave);
        setAsteroids(_nbAsteroid);
     //   std::cout<<__FUNCTION__<< std::endl;
        
    }
    
    ~MenuScore(){
        delete [] _msgWave;
        delete [] _msgAsteroid;
        delete [] _msgScore;
        
        
    }
    
    // get/ set
    int getWaves();
    int getAsteroids();
    int getScore();
    
    
    void setWaves(int nbWaves);
    void setAsteroids(int nbAsteroids);
    void setScore(int score);
    //method
    void asteroidDestroy();
    void modifyScore(int points);
    void draw();
    
};
#endif /* MenuScore_h */
