#include "LaserData.h"
#include <math.h>
#include "Point.h"

#define M_PI       3.14159265358979323846

LaserData::LaserData()
{
}

Point LaserData::convert(float dist, glm::vec3 pos, float angle, float initAngle){

    //float theta = 90.f;
    float phi = initAngle + angle;
    phi *= M_PI / 180.f;
    float x = (0.1*dist) * cosf(phi);
    float y = (0.1*dist) * sinf(phi);

    glm::vec3 position(x, y, pos.z);

    glm::vec3 normal(x - pos.x, y - pos.y, position.z - pos.z);


    Point p(position, normal);
    return p;
}
