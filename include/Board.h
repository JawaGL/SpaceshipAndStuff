//
//  Board.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef Board_h
#define Board_h
#include "GraphicPrimitives.h"
#include "InterfaceComponent.h"
#include "AsteroidHitBox.h"
#include <stdio.h>


class Board: public InterfaceComponent{
private:
    int _nbCol, _nbRow;
    float _sizeCaseX, _sizeCaseY;
public:
    Board():InterfaceComponent(), _nbCol(10), _nbRow(1)/*, _sizeCaseX(this->getWidth()/_nbCol), _sizeCaseY(this->getHeight()/_nbRow)*/
    {
        calculateSizeCase();
        //std::cout<<__FUNCTION__<< std::endl;
    }
    Board(int col, int row, Point2D const & p, float h, float w):InterfaceComponent(p, h, w),_nbCol(col), _nbRow(row)/*, _sizeCaseX(this->getWidth()/_nbCol), _sizeCaseY(this->getHeight()/_nbRow)*/
    {
        calculateSizeCase();
      //  std::cout<<__FUNCTION__<< std::endl;
    }
    ~Board(){}
    
    //set/get
    void setNbCol(int col);
    void setNbRow(int row);
    void calculateSizeCase();
    
    float getSizeCaseX();
    float getSizeCaseY();
    
    int getNbCol();
    int getNbRow();
    
    //method
    int getColFromX(float x);
    int getRowFromY(float y);
    void draw();
    //operator
    bool operator&(AsteroidHitBox * hitbox);
};
#endif /* Board_h */
