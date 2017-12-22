

#include <iostream>
#include "Engine.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Environment.h"


int main(int argc, char * argv[])
{
    
    Engine e(argc,argv);
    
    std::vector<Papillon *> paps;
    (Environment::instance())->init();
    GraphicEngine * ge = new MyGraphicEngine(Environment::instance());
    GameEngine * gme = new MyGameEngine(Environment::instance());
    ControlEngine * ce = new MyControlEngine(Environment::instance());
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    e.start();
    return 0;
}
