#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point(glm::vec3 position, glm::vec3 normal) : m_position(position), m_normal(normal);


private:
    glm::vec3 m_position, m_normal;
};

#endif // POINT_H
