#ifndef SCENE_H
#define SCENE_H

#include "PointCloud.h"
#include "RawData.h"

class Scene
{
public:
    Scene();
    void init ();
    void draw ();
    void update ();

private:
    PointCloud *m_pointCloud;
    RawData *m_rawData;
};

#endif // SCENE_H
