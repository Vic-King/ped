#include <iostream>

#include "IDataConversion.h"
#include "DisplayModel.h"
#include "Point.h"
#include "VEFModel.h"

#include <glm/glm.hpp>

using namespace std;

void raytrace(glm::vec3 ori, glm::vec3 dir);
bool move(glm::vec3 position, glm::vec3 orientation, glm::vec3 direction);

struct robot {
    glm::vec3 position;
    glm::vec3 orientation;
    glm::vec3 direction;
};

int main() {
    // CONFIG
    unsigned int nbRay = 180;
    robot WallE;

    bool stop = false;
    std::vector<Point> pointCloud;

   //Point curPoint;

    // TEST MODE
    VEFModel obj;
    obj.load("Objects/couloirPED.obj");

    while (!stop) {

        for (unsigned int i = 0; i < nbRay; ++i) {

            // TEST MODE
            //raytrace();

            // NORMAL MODE
            // get drone data

            //WallE.move(glm::vec3 accPos, glm::vec3 accOri, glm::vec3 accDir);
        }

        //stop = !move(position, direction);
    }

    return 0;
}

void raytrace(glm::vec3 ori, glm::vec3 dir) {

}

bool move(glm::vec3 accPos, glm::vec3 accOri, glm::vec3 accDir) {
    /*position += accPos;
    orientation += accOri;
    direction += accDir;*/

    return true;
}
