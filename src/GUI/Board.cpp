//
//  Board.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 02/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "Board.h"

void Board::setNbCol(int col)
{
    _nbCol=col;
}
void Board::setNbRow(int row)
{
    _nbRow=row;
}
void Board::calculateSizeCase()
{
    _sizeCaseX=getWidth()/getNbCol();
    _sizeCaseY=getHeight()/getNbRow();
}

float Board::getSizeCaseX()
{
    return _sizeCaseX;
}
float Board::getSizeCaseY()
{
    return _sizeCaseY;
}

int Board::getNbCol()
{
    return _nbCol;
}
int Board::getNbRow()
{
    return _nbRow;
}

//method
int Board::getColFromX(float x)
{
    return (int)((1 +x -(2.-getWidth()))/getSizeCaseX());
}
int Board::getRowFromY(float y)
{
    return (int)((y+1 - (2.-getHeight())/2.)/getSizeCaseY());
}

void Board::draw()
{
    for(int i=0; i<=getNbRow(); i++)
    {
        GraphicPrimitives::drawLine2D(getBeginX(),getBeginY()+(i)*getSizeCaseY(),getEndX(),getBeginY()+(i)*getSizeCaseY(),0.3f,0.3f,0.3f);
        for(int j=0; j<=getNbCol(); j++)
        {
            GraphicPrimitives::drawLine2D(getBeginX()+j*getSizeCaseX(),getBeginY(),getBeginX()+j*getSizeCaseX(),getEndY(),0.3f,0.3f,0.3f);
        }
    }
}
//Operator
bool Board::operator&(AsteroidHitBox * hitbox)
{
    float x= hitbox->getLeftBotCorner()->getPosX();
    //std::cout<<"LeftBotCornerHitbox: "<< x<< std::endl;
    if(this->getBeginX()>= x)
        return true;
    return false;
}

