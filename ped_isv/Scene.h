#ifndef SCENE_H
#define SCENE_H

#include "PointCloud.h"
#include "RawData.h"
#include "LaserData.h"


class Scene
{
public:
    Scene();
    void init ();
    void draw ();
    void update ();

    const PointCloud* getPointCloud() {return m_pointCloud;}

private:
    PointCloud *m_pointCloud;
    RawData *m_rawData;
    LaserData *m_laserdata;
};

#endif // SCENE_H
