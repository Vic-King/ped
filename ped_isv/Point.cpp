#include "Point.h"



Point::Point(glm::vec3 position, glm::vec3 normal) :
    m_Position(position),
    m_Normal(normal)
{
}


 Point::Point(float x, float y, float z, float nx, float ny, float nz) :
     m_Position(x,y,z),
     m_Normal(nx,ny,nz)
 {
 }
