#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include "Point.h"
#include <vector>

class PointCloud
{
public:
    PointCloud();
    void addPoint(Point p);
    void addPoint(Point p, int pos);
    void delPoint();
    void delPoint(int pos);
    Point getPoint(int pos) const;
    unsigned int getSize() const;

private:
    std::vector<Point> listPoints;
};

#endif // POINTCLOUD_H
