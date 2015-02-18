#ifndef IRECONSTRUCTION_H
#define IRECONSTRUCTION_H
#include <vector>
#include <glm/glm.hpp>
#include "point.h"

class IReconstruction
{
public:
    IReconstruction() ;
    virtual void reconstruct(std::vector<Point> pointCloud) = 0;

};

#endif // IRECONSTRUCTION_H
