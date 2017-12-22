//
//  AsteroidHitBox.hpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 11/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef AsteroidHitBox_h
#define AsteroidHitBox_h
#include "GeometricalItem.h"
#include "HitBox.h"
#include <stdio.h>
//AsteroidHitboxes are rectangular
class AsteroidHitBox: public HitBox{
private:
    float _width, _length;
    Point2D * _leftBotCorner,* _leftUpCorner,* _rightUpCorner,* _rightBotCorner;
public:
    AsteroidHitBox(float x, float y, float w, float l):HitBox(x,y,x-l/2, y), _width(w), _length(l)
    , _leftBotCorner(new Point2D(getCenter()->getPosX()-l/2, getCenter()->getPosY()-w/2))
    , _leftUpCorner(new Point2D(getCenter()->getPosX()-l/2, getCenter()->getPosY()+w/2))
    , _rightUpCorner(new Point2D(getCenter()->getPosX()+l/2, getCenter()->getPosY()+w/2))
    , _rightBotCorner(new Point2D(getCenter()->getPosX()+l/2, getCenter()->getPosY()-w/2))
    
    {
        
    }
    virtual ~AsteroidHitBox()
    {
        delete _leftUpCorner;
        delete _leftBotCorner;
        delete _rightUpCorner;
        delete _rightBotCorner;
    }
    float getWidth() const;
    float getLength() const;
    //for normal moving asteroid
    void move(float amplitude, float angle);
    //for warping asteroid
    void move(Point2D * center);
    Point2D * getLeftBotCorner();
    Point2D * getLeftUpCorner();
    Point2D * getRightBotCorner();
    Point2D * getRightUpCorner();
    
    virtual bool operator&(HitBox* hitbox);
    
};
#endif /* AsteroidHitBox_h */
