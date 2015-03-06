#include "laserdata.h"
#include <math.h>
#include "Point.h"

LaserData::LaserData()
{
}

Point convert(float dist, glm::vec3 pos, int angle, int initAngle){


    float x = dist * cos(initAngle - angle) * cos(0);
    float y = dist * sin(initAngle - angle);
    float z = dist * cos(initAngle - angle) * sin(0);

    glm::vec3 position = (x, y, z);

    glm::vec3 normal = (pos.x - position.x, pos.y - position.y, pos.z - position.z);


    Point p = new Point(position, normal);
}
