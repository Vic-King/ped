#include "Point.h"

class Point
{

//glm::vec3 m_Position;
//hlm::vec3 m_Normal;


Point::Point(glm::vec3 position, glm::vec3 normal)
{
    m_Position = (position);
    m_Normal = (normal);
}


 Point::Point(float x, float y, float z, float ny, float ny, float nz)
 {
     m_Position = (x, y ,z);
     m_Normal = (nx, ny, nz);
 }

 };
