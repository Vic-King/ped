#ifndef LASERDATA_H
#define LASERDATA_H

#include "Point.h"

class LaserData
{
public:
    LaserData();
    Point convert(float dist, glm::vec3 pos, int angle, int initAngle);
};

#endif // LASERDATA_H
