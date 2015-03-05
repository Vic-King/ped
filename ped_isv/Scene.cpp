#include "Scene.h"
#include "PointCloud.h"
#include "Point.h"

Scene::Scene() {

}

void Scene::init () {

    m_pointCloud = new PointCloud ();
    m_rawData = new RawData ();
}

void Scene::draw () {

}

void Scene::update () {

    //WaitPacket

    Point p = m_rawData->convertPacket(/*packet*/);

    m_pointCloud->addPoint(p);
}
