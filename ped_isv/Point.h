#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point(float x, float y, float z, float nx, float ny, float nz) : m_X(x), m_Y(y), m_Z(z),
                                                                     m_NX(nx), m_NY(ny), m_NZ(nz)


private:
    float m_X, m_Y, m_Z;
    float m_NX, m_NY, m_NZ;
};

#endif // POINT_H
