//
//  GraphicalInterface.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "GraphicalInterface.h"
//get/set
float GraphicalInterface::getBoardBeginX()
{
    return _b.getBeginX();
}
float GraphicalInterface::getBoardBeginY()
{
    return _b.getBeginY();
}
float GraphicalInterface::getBoardEndX()
{
    return _b.getEndX();
}
float GraphicalInterface::getBoardEndY()
{
    return _b.getEndY();
}
void GraphicalInterface::setWarning(char *w)
{
    _mw.setWarning(w);
}
void GraphicalInterface::setLaunchInfo(bool b)
{
    _mb.setLaunchInfo(b);
}
int GraphicalInterface::getColFromX(float x)
{
    return (int)((1 +x -(2.-_b.getWidth()))/_b.getSizeCaseX());
   // return _b.getColFromX(x);
}
int GraphicalInterface::getRowFromY(float y)
{
    return (int)((y+1 - (2.-_b.getHeight())/2.)/_b.getSizeCaseY());
    //return _b.getRowFromY(y);
}
float GraphicalInterface::getSpacecraftAncrageX(int col)
{
    return _b.getBeginX()+ (col+1)* _b.getSizeCaseX();
}
float GraphicalInterface::getSpacecraftAncrageY(int row)
{
    return _b.getBeginY()+row*_b.getSizeCaseY() + 0.5*_b.getSizeCaseY();
}
float GraphicalInterface::getSizeCaseY()
{
    return _b.getSizeCaseY();
}
float GraphicalInterface::getSizeCaseX()
{
	return _b.getSizeCaseX();
}

void GraphicalInterface::createSpacecraft(int row, int col)
{
    _pMapBoard[row][col]=true;
    //for(int i=0; i<_b.getNbRow(); i++)
   // {
        //for(int j=0; j<_b.getNbCol();j++)
             //   std::cout<< _pMapBoard[i][j]<< " ";
        //std::cout<<"\n";
    //}
}
void GraphicalInterface::removeSpacecraft(int row, int col)
{
    //std::cout<<"Removing spacecraft on "<< row <<" : "<< col<<std::endl;
    _pMapBoard[row][col]=false;
    //std::cout<<"Map: "<<std::endl;
    /*  for(int i=0; i<_b.getNbRow(); i++)
     {
     for(int j=0; j<_b.getNbCol();j++)
    // std::cout<<_pMapBoard[i][j]<< " ";
     std::cout<<"\n";
     }*/
}
//Check if a spacecraft is present in front of these coord
bool GraphicalInterface::checkLoS(int row, int col)
{
   // std::cout<<"ROw = "<< row <<"  Col= "<<col<<std::endl;
    for(int i=col+1; i<_b.getNbCol(); i++)
    {
        if(_pMapBoard[row][i])
            return false;
    }
    return true;
}
bool GraphicalInterface::checkShipBehind(int row, int col)
{
    for(int i=col-1; i>=0; i--)
        if(_pMapBoard[row][i])
            return true;
    return false;
}
void GraphicalInterface::draw()
{
    _b.draw();
    _mw.draw();
    _ms.draw();
    _mb.draw();
}

int GraphicalInterface::selectMenuItem(unsigned char key)
{
   return _mb.SelectedMenuItem(key);
}
void GraphicalInterface::setWaves(int w)
{
    _ms.setWaves(w);
}
void GraphicalInterface::setNbAste(int a)
{
    _ms.setAsteroids(a);
}
void GraphicalInterface::setScore(int s)
{
    _ms.setScore(s);
    checkBuyable(s);
}
void GraphicalInterface::checkBuyable(float score)
{
    _mb.checkBuyable(score);
}
bool GraphicalInterface::checkGameOver(AsteroidHitBox * hitbox)
{
    return _b&(hitbox);
}
