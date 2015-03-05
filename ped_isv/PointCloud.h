#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include "Point.h"
#include <vector>

class PointCloud
{
public:
    PointCloud();
    void addPoint(Point p);
    void delPoint(Point p);

private:
    std::vector<Point> listPoints;
};

#endif // POINTCLOUD_H
