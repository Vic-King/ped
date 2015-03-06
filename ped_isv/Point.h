#ifndef POINT_H
#define POINT_H

#include <glm/glm.hpp>

class Point
{
public:
    Point(glm::vec3 position, glm::vec3 normal);
    
    Point(float x, float y, float z, float nx, float ny, float nz);

private:
    glm::vec3 m_Position, m_Normal;

};

#endif // POINT_H
