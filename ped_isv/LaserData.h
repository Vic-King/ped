#ifndef LASERDATA_H
#define LASERDATA_H

#include "Point.h"

class LaserData
{
public:
    LaserData() {}
    Point convert(float dist, glm::vec3 pos, float angle, float initAngle);
};

#endif // LASERDATA_H
