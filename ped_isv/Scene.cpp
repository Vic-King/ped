#include "Scene.h"
#include "PointCloud.h"
#include "Point.h"
#include "LaserData.h"
#include <fstream>
#include <iostream>


using namespace std;

Scene::Scene() {

}

void Scene::init () {

    m_pointCloud = new PointCloud ();
    m_laserdata = new LaserData();
    float initAngle = 270.f;



    //Lecture du fichier
    ifstream fichier("Data/objet1.txt", ios::in);

    if(fichier)
    {
        //string d, px, py, pz, a;
        float dist = 0.0f;
        glm::vec3 pos = glm::vec3(0.0f);
        float angle = 0.f;
        string ligne;

        do{
            fichier >> angle >> dist;
            //fichier >> pos.x >> pos.y >> pos.z >> angle >> dist;
            //std::cout << pos.x << " " << pos.y << " " << pos.z << " " << angle << " " << dist << std::endl;
            //ligne >> pos.x >> pos.y >> pos.z >> angle >> dist;
            Point p = m_laserdata->convert(dist, pos, angle, initAngle);
            m_pointCloud->addPoint(p);

        }while( getline(fichier, ligne));

        fichier.close();
    }
    else
        cerr << "Impossible d'ouvrir le fichier !" << endl;
}



void Scene::draw ()
{

}

//void Scene::update ()
//{
//}
