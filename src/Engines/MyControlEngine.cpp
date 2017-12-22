
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
       // paps->push_back(new Papillon((x-400) / 400.f, (y-300)/ -300.f ));
        _envi->click((x-375)/375.f, (y-375)/-375.f);
        
    }
}
void MyControlEngine::KeyboardReleaseCallback(unsigned char key,int x, int y)
{
    _envi->keyPress(key);
}
