//
//  ShootHitBox.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 11/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef ShootHitBox_h
#define ShootHitBox_h
#include "HitBox.h"
#include "AsteroidHitBox.h"
#include "GeometricalItem.h"
#include <stdio.h>
class ShootHitBox: public HitBox{
private:
    Point2D * _head;
    Point2D * _tail;
    float _length;
public:
    //float x, float y, float x2, float y2): _center(new Point2D (x,y)), _mostExternalPoint(new Point2D(x2,y2))
    //shoots are first created in a straight line
    ShootHitBox(float xHead, float yHead, float length):HitBox(xHead-length/2, yHead, xHead, yHead),
    _head(new Point2D (xHead, yHead)),
    _tail (new Point2D(xHead - length, yHead)),
    _length(length)
    {
        
    }
    virtual ~ShootHitBox()
    {
        delete _head;
        delete _tail;
    }
    void move(Point2D * head, float direction,float amplitude, float angle);
    void setHead(float x, float y);
    void setTail(float x, float y);
    Point2D * getHead();
    Point2D * getTail();
    
    bool operator&(HitBox * hitbox);
};
#endif /* ShootHitBox_h */
