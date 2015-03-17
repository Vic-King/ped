#include "LaserData.h"
#include <math.h>
#include "Point.h"

#define M_PI       3.14159265358979323846

Point LaserData::convert(float dist, glm::vec3 pos, float angle, float initAngle)
{
    float phi = initAngle + angle;
    phi *= M_PI / 180.f;
    float x = -(dist * cosf(phi));
    float y = dist * sinf(phi);

    glm::vec3 position(x, y, pos.z);
    glm::vec3 normal(x - pos.x, y - pos.y, position.z - pos.z);

    Point p(position, normal);
    return p;
}
