#include "PointCloud.h"

PointCloud::PointCloud()
{
}

void PointCloud::addPoint(Point p) {
    listPoints.push_back(p);
}

void PointCloud::addPoint(Point p, int pos) {
    listPoints.insert(listPoints.begin() + pos, p);
}

void PointCloud::delPoint() {
    listPoints.pop_back();
}

void PointCloud::delPoint(int pos) {
    listPoints.erase(listPoints.begin() + pos);
}

Point PointCloud::getPoint(int pos) const {
    return listPoints.at(pos);
}

unsigned int PointCloud::getSize() const {
    return listPoints.size();
}
