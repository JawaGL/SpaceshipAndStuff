//
//  GraphicalInterface.h
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#ifndef GraphicalInterface_h
#define GraphicalInterface_h

#include <stdio.h>
#include "Board.h"
#include "MenuWarning.h"
#include "MenuScore.h"
#include "MenuBuy.h"

class GraphicalInterface {
private:
    //buy value since created only one time and the menus can't exist without the graphical interface
    Board _b;
    MenuWarning _mw;
    MenuScore _ms;
    MenuBuy _mb;
    bool **  _pMapBoard;
public:
    
    GraphicalInterface(
                Point2D const & pBoard, int nbCol, int nbRow,float boardHeight,float  boardWidth,
                Point2D const & pMenuWarn, float mwHeight, float mwWidth,
                Point2D const & pMenuScore, float msHeight, float msWidth,
                Point2D const & pMenuBuy, float mbHeight, float mbWidth )
    :
                _b(nbCol, nbRow, pBoard, boardHeight, boardWidth),
                _mw("", pMenuWarn, mwHeight, mwWidth),
                _ms(pMenuScore, msHeight,msWidth),
                _mb(pMenuBuy, mbHeight, mbWidth),
                _pMapBoard(new bool * [_b.getNbRow()])
        {
            for (int i=0; i<_b.getNbRow(); i++)
            {    _pMapBoard[i]= new bool[_b.getNbCol()];
                for(int j=0; j<_b.getNbCol(); j++)
                    _pMapBoard[i][j]=false;
            
            }
          //  std::cout<<__FUNCTION__<< std::endl;
        }
    //get/set
    float getBoardBeginX();
    float getBoardBeginY();
    float getBoardEndX();
    float getBoardEndY();
    void setWarning(char * w);
    void setLaunchInfo(bool b);
    int getColFromX(float x);
    int getRowFromY(float y);
    float getSpacecraftAncrageX(int col);
    float getSpacecraftAncrageY(int row);
    float getSizeCaseY();
	float getSizeCaseX();
	
    //method
    void createSpacecraft(int row, int col);
    void removeSpacecraft(int row, int col);
    bool checkShipBehind(int row, int col);
    bool checkLoS(int row, int col);
    void draw();
    int selectMenuItem(unsigned char key);
    void setWaves(int w);
    void setNbAste(int a);
    void setScore(int s);
    void checkBuyable(float score);
    bool checkGameOver(AsteroidHitBox * hitbox);
    
};
#endif /* GraphicalInterface_h */
