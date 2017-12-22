//
//  Environment.cpp
//  yBleyfuesz_projetCPP
//
//  Created by Yonathan Bleyfuesz on 03/11/17.
//  Copyright © 2017 Yonathan Bleyfuesz. All rights reserved.
//

#include "Environment.h"
#include <ctime>

#define STARTCREDITS 200;
#define STARTWAVE 0;
Environment * Environment::_pEnvironment=0;
 Environment* Environment::instance()
{
    if(!Environment::_pEnvironment)
     Environment::_pEnvironment=new Environment();

    return _pEnvironment;
}

void Environment::init()
{

	std::srand(std::time(0));
    _end=false;
    _gui=new GraphicalInterface(
    /*board    */            Point2D(-0.68, -0.84), 12, 12,1.68, 1.68,
    /*MenuWarn */            Point2D(-0.68, -1.0), 0.16,1.68,
    /*MenuScore*/            Point2D(-0.68, 0.84), 0.16,1.68,
    /*MenuBuy  */            Point2D(-1, -0.86), 1.68,0.32
                               );
    _gui->setWaves(_nbWaves);
    _gui->setNbAste(_nbAsteroid);
    _gui->setScore(_Score);
    _gui->checkBuyable(_Score);
    _pSpacecrafts= new std::vector<CombatSpacecraft* >();
    _pAsteroids=new std::vector<Asteroid *> ();
	_Score = STARTCREDITS;
	_gui->setScore(_Score);
    int WaveStart=STARTWAVE;
    _nbWaves=WaveStart;
    _shIvA=new SpawnEngine(200, 5, _pAsteroids, 0.1, 12, _gui->getSizeCaseY(), _gui->getBoardEndX() - _gui->getSizeCaseY()/2, _gui->getBoardBeginY(), WaveStart);
	setSpacraftType(1);
	_currentSelectedPrice = _gui->selectMenuItem('a');
   // SpawnEngine(int freqSpawn, int nbBaseAste, std::vector<Asteroid*> * pAste, float difficultyIncrement, int nbMaxLane, float sizeCaseY, float spawnAncrageX, float beginBoardY):
    //float x, float y, int life, int killMoney, float speed, float w, float l
   // _pAsteroids->push_back(new AverageAsteroid(1-0.14/2, -0.84 + 0.14/2, 200, 10, 0.0005, 0.13,0.07));
   // float x, float y, int life, int killMoney, float speed, float w, float l, int freqWarp, float sizeCase
    //_pAsteroids->push_back(new WarpingAsteroid(1-0.14/2, _gui->getBoardEndY() - 0.14/2, 100, 200, 0.0005, 0.13,0.07, 200, _gui->getSizeCaseY(),_gui->getBoardBeginY(), _gui->getBoardEndY()));
    //_pAsteroids->push_back(new EllipticalAsteroid(1-0.14/2, -0.84 + 0.14/2, 200, 10, 0.0005, 0.13,0.07));
}

void Environment::setSpacraftType(int t)
{
    _SpacecraftType=t;
}
void Environment::act()
{
    _shIvA->act();
    //_gui->setNbAste(_shIvA->getRemainingAste());
    int i=0;
	int index = 0;
    //Spacecrafts shoot and Shoots act
	const int size = _pSpacecrafts->size();
	int * toRemove= new int[size];
    for(auto it= _pSpacecrafts->begin(); it!=_pSpacecrafts->end(); index ++)
    {
        
        if((*it)->isAlive())
        {
            if(checkLos((*it)->getGravityX(),(*it)->getGravityY()))
                (*it)->shoot();
           
        }
        else
        {
            
            int col = _gui->getColFromX((*it)->getGravityX());
            int row= _gui->getRowFromY((*it)->getGravityY());
            CombatSpacecraft* csAhead=getShipAhead(row, col);
            if(csAhead!=NULL)
                csAhead->unbuff();
            _gui->removeSpacecraft(row, col);
			toRemove[i] = index;
            //delete (*it);
            
            //_pSpacecrafts->erase(it);
            i++;
        }
        
		++it;
        
    }
	int j = 0;
	for (j = i-1; j >= 0; j--)
	{
		delete _pSpacecrafts->operator[](toRemove[j]);
		_pSpacecrafts->erase(_pSpacecrafts->begin()+toRemove[j]);

	}
    /*for(CombatSpacecraft * cs: *_pSpacecrafts)
    {
        if(cs->isAlive())
        {
            if(checkLos(cs->getGravityX(),cs->getGravityY()))
                cs->shoot();
        }
        else
        {
            
            int col = _gui->getColFromX(cs->getGravityX());
            int row= _gui->getRowFromY(cs->getGravityY());
            CombatSpacecraft* csAhead=getShipAhead(row, col);
            if(csAhead!=NULL)
                csAhead->unbuff();
            _gui->removeSpacecraft(row, col);
            delete cs;
            
            _pSpacecrafts->erase(_pSpacecrafts->begin()+i);
            i--;
        }
        i++;
       
        
    }*/
    //Asteroid move
    i=0;
    const int sizeA= _pAsteroids->size();
    delete toRemove;
    toRemove = new int[size];
	index = 0;
    for(auto it= _pAsteroids->begin(); it!=_pAsteroids->end();index ++)
    {
        
        if((*it)->checkAlive())
        {    (*it)->act();
            if(!_end )
                _end=_gui->checkGameOver((*it)->getHitbox());
           
        }
        else
        {
          //  delete (*it);
            
            //_pAsteroids->erase(it);
            
            _nbAsteroid--;
            _gui->setNbAste(_nbAsteroid);
			toRemove[i] = index;
            i++;
        }
        
		++it;
        
        
    }
	j = 0;
	for (j = i - 1; j >= 0; j--)
	{
		delete _pAsteroids->operator[](toRemove[j]);
		_pAsteroids->erase(_pAsteroids->begin() + toRemove[j]);

	}
	delete toRemove;
    /*for(Asteroid * a:*_pAsteroids)
    {
        if(a->checkAlive())
        {    a->act();
            if(!_end )
                _end=_gui->checkGameOver(a->getHitbox());
        }
        else
        {
            delete a;

            _pAsteroids->erase(_pAsteroids->begin()+i);
            
            _nbAsteroid--;
            _gui->setNbAste(_nbAsteroid);
            
            i--;
        }
        
        i++;
    }*/
    //check for colision
    //if(refreshCpt%5 ==0)
    //{
    int gain=0;
    std::vector<Asteroid*> * pAstBuf=NULL;
    for(CombatSpacecraft * cs: *_pSpacecrafts)
    {
        pAstBuf=getAsteroidOnLane(_gui->getRowFromY(cs->getGravityY()));
        if(pAstBuf->size()!=0)
            gain+=*cs&pAstBuf;
      
        pAstBuf->clear();
        delete pAstBuf;
    }
    
   //     refreshCpt=1;
  //  }
   // refreshCpt++;
    if(_nbAsteroid==0)
        _gui->setLaunchInfo(true);
    if(_end)
        this->gameOver();
    else
    {
        _Score+=gain;
        _gui->setScore(_Score);
    }
}
void Environment::draw()
{
    _gui->draw();
    
    for(CombatSpacecraft * cs: *_pSpacecrafts)
    {
        //std::cout<<(( DeathStar *)(_pSpacecrafts->operator[](0)))->_shoots->size()<<"\n";
        cs->draw();
    }
    for(Asteroid * a: *_pAsteroids)
    {
        a->draw();
    }
}
void Environment::keyPress(unsigned char key)
{
    switch(key)
    {
        case 'a': setSpacraftType(1);
            _currentSelectedPrice=_gui->selectMenuItem(key);

            break;
        case 'z':setSpacraftType(2);
            _currentSelectedPrice=_gui->selectMenuItem(key);

            break;
        case 'e':setSpacraftType(3);
            _currentSelectedPrice=_gui->selectMenuItem(key);

            break;
        case 'n':
            
                if(_end)
                {
                    _end=false;
                    _Score+=1;
                }
                if(!_shIvA->isRunning() && _nbAsteroid==0)
                 {
                     _gui->setLaunchInfo(false);
                     _nbWaves++;
                     _gui->setWaves(_nbWaves);
                     _nbAsteroid=_shIvA->getRemainingAste();
                     _gui->setNbAste(_nbAsteroid);
                     _shIvA->start();
                 }
                else
                {
                    _gui->setWarning("Cannot start a wave during a wave!");
                    return;
                }
            break;
        default: _gui->setWarning("Key not recognised");
            return;
    }
    _gui->setWarning("");
    
}
void Environment::click(float x, float y)
{   if(!(_Score==_baseScore-1))
    {
    if(x> _gui->getBoardBeginX() && x< _gui->getBoardEndX() && y> _gui->getBoardBeginY() && y<_gui->getBoardEndY())
    {
        if(_SpacecraftType!=0)
        {
            int col = _gui->getColFromX(x);
            int row= _gui->getRowFromY(y);
        
            if(checkBoard(col, row))
            {
                if(_Score >= _currentSelectedPrice)
                {
                    _gui->createSpacecraft(row, col);
                    CombatSpacecraft * csBehind=stopShipBehind(row, col);
                    CombatSpacecraft * csCrea=NULL;
                    if(_SpacecraftType==1)
                    {
                        //create spacecraft Enterprise
                        csCrea=new Enterprise(_gui->getSpacecraftAncrageX(col),_gui->getSpacecraftAncrageY(row), _gui->getSizeCaseY());
                       
                        
                    }
                    if(_SpacecraftType==2)
                    {
                        //create spacecraft Serenity
                        csCrea=new Serenity(_gui->getSpacecraftAncrageX(col),_gui->getSpacecraftAncrageY(row), _gui->getSizeCaseY());
                    }
                    if(_SpacecraftType==3)
                    {
                        //create spacecraft DeathStar
                        csCrea=new DeathStar(_gui->getSpacecraftAncrageX(col),_gui->getSpacecraftAncrageY(row), _gui->getSizeCaseY());
                        
                    }
                    if(csBehind!=NULL)
                        *csCrea+csBehind;
                    
                    else
                    {
                        CombatSpacecraft * csAhead = getShipAhead(row, col);
                        if(csAhead!=NULL)
                            *csAhead+csCrea;
                       
                    }
                     _pSpacecrafts->push_back(csCrea);
                    _Score-=_currentSelectedPrice;
                    _gui->setScore(_Score);
                    _gui->setWarning("");
                }
                else
                    _gui->setWarning("Not enough Credits");
            }
            else
            {
                _gui->setWarning("Can only create 1 spacecraft per case and 2 per row.");
            }
        }
        else
            _gui->setWarning("Select a spacecraft type please.");
        
    }
    else
    {
        _gui->setWarning("Please click on the board");
    }
    }
    else
    {
        _gui->setWarning("Please press N to launch a wave");
    }
}
//check the board for other object (asteroid or spacecraft) that could obstruct
//the creation of a spacecraft
bool Environment::checkBoard(int col, int row)
{
    int cptScOnRow=0;
    for(CombatSpacecraft * cs:*_pSpacecrafts)
    {
        if(_gui->getRowFromY(cs->getGravityY()) ==row)
        {
            cptScOnRow++;
            if(_gui->getColFromX(cs->getGravityX()) ==col)
            {
                return false;
            }
            if(cptScOnRow>1)
                return false;
        }
    }
    //parcour asteroids
    return true;
}
bool Environment::checkLos(float x, float y)
{
    int row= _gui->getRowFromY(y);
    int col= _gui->getColFromX(x);
    return _gui->checkLoS(row, col);
}
CombatSpacecraft* Environment::getShipAhead(int row, int col)
{
   
    for(CombatSpacecraft * cs:*_pSpacecrafts)
    {
        if(_gui->getRowFromY(cs->getGravityY()) ==row && _gui->getColFromX(cs->getGravityX()) >col)
        {
            return cs;
        }
    }
    return NULL;
    
}
CombatSpacecraft * Environment::stopShipBehind(int row, int col)
{
   
    if(_gui->checkShipBehind(row, col))
    {
        for(CombatSpacecraft * cs:*_pSpacecrafts)
        {
           //std::cout << "Row = "<< row << " Col " << col << std::endl;
            if(_gui->getRowFromY(cs->getGravityY()) ==row && _gui->getColFromX(cs->getGravityX()) <col)
            {
                //std::cout<<"Found!\n";
                cs->stopShoots();
                return cs;
            }
        }
    }
    return NULL;
}
std::vector<Asteroid *> * Environment::getAsteroidOnLane(int row)
{
    std::vector <Asteroid *>  * pAstBuf= new std::vector<Asteroid *>();
    
    for(Asteroid * a: *_pAsteroids)
    {
        int asteRow=_gui->getRowFromY( a->getCenter()->getPosY());
        if(asteRow==row || asteRow==row-1 || asteRow==row+1)
            pAstBuf->push_back(a);
    }
    return pAstBuf;
}
void Environment::gameOver()
{
    _gui->setWarning("GAME OVER");
    int i=_pSpacecrafts->size();
    for(int k=0; k<i; k++)
    {
    //    std::cout<<"Spacecraft State: "<< k<<"Size "<< _pSpacecrafts->size()<<std::endl;

        int col = _gui->getColFromX(_pSpacecrafts->at(i-1-k)->getGravityX());
        int row= _gui->getRowFromY(_pSpacecrafts->at(i-1-k)->getGravityY());
        _gui->removeSpacecraft(row, col);
        delete _pSpacecrafts->back();
        
        _pSpacecrafts->pop_back();
    }
    for(auto it= _pSpacecrafts->begin(); it!=_pSpacecrafts->end();)
    {
        
        int col = _gui->getColFromX((*it)->getGravityX());
        int row= _gui->getRowFromY((*it)->getGravityY());
        _gui->removeSpacecraft(row, col);
        
        
        delete (*it);
         _pSpacecrafts->erase(it);
        
        
        
    }
    /*
     
    for(CombatSpacecraft * cs: *_pSpacecrafts)
    {
            int col = _gui->getColFromX(cs->getGravityX());
            int row= _gui->getRowFromY(cs->getGravityY());
            _gui->removeSpacecraft(row, col);
            delete cs;
            _pSpacecrafts->erase(_pSpacecrafts->begin()+i);
       // std::cout<<"Nb item _pSpacecraft: "<< _pSpacecrafts->size()<<std::endl;


    }*/
    
    
 

    i=0;
    
    for(auto it=_pAsteroids->begin(); it !=_pAsteroids->end();)
    {
        delete (*it);
		++it;
       // _gui->setNbAste(_nbAsteroid);
        
    }
   /* for(Asteroid * a:*_pAsteroids)
    {
      //  _pAsteroids->erase(_pAsteroids->begin()+i);
        delete a;

       // _nbAsteroid--;
        _gui->setNbAste(_nbAsteroid);
            
    }*/
    _pAsteroids->clear();
   // _end=false;
    _nbAsteroid=0;
    _nbWaves=0;
    _Score=_baseScore-1;
    _shIvA->gameOver();
    delete _shIvA;
    _shIvA=new SpawnEngine(200, 5, _pAsteroids, 0.1, 12, _gui->getSizeCaseY(), _gui->getBoardEndX() - _gui->getSizeCaseY()/2, _gui->getBoardBeginY(),0);
    
    _gui->setLaunchInfo(true);

    //destroy every element on the board!
}
