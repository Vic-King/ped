#include <iostream>

#include "Scene.h"

using namespace std;


int main() {

    Scene *scene = new Scene ();
    scene->init();
    scene->update();

    return 0;
}
