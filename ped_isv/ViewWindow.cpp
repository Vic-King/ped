#include "ViewWindow.h"
#include "LaserData.h"
#include <iostream>
#include <fstream>
#include <boost/timer.hpp>
#include <cstdlib>
#include <ctime>


void ViewWindow::mouseReleaseEvent(QMouseEvent *releaseEvent)
{
    if(releaseEvent->button() == Qt::LeftButton)
    {
        m_Rotate = false;
        m_UpdateRender = false;
    }
}

void ViewWindow::mouseMoveEvent(QMouseEvent *eventMove)
{
    if(m_Rotate){
        QVector2D vec( eventMove->pos().x() - m_LastPos.x(), eventMove->pos().y() - m_LastPos.y());

        m_MVPMatrix.rotate(m_RotateSpeed * vec.x(), QVector3D(0.f, 1.f, 0.f));
        m_MVPMatrix.rotate(m_RotateSpeed * vec.y(), QVector3D(1.f, 0.f, 0.f));
        m_LastPos = eventMove->pos();
        m_UpdateRender = true;
    }
}

void ViewWindow::mousePressEvent(QMouseEvent *eventPress)
{
    if(eventPress->button() == Qt::LeftButton){
        m_Rotate = true;
    }
    if(eventPress->button() == Qt::RightButton){
        m_RotateSpeed += 0.2f;
    }
    if(eventPress->button() == Qt::MiddleButton){
        float6 val;
        for(unsigned int i = 0; i < m_PointCloud->getSize(); ++i){
            val.x = m_PointCloud->getPoint(i).m_Position.x;
            val.y = m_PointCloud->getPoint(i).m_Position.y;
            val.z = m_PointCloud->getPoint(i).m_Position.z;

            val.r = 1.f;
            val.g = 0.f;
            val.b = 0.f;

            m_Data[i] = val;
        }
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float6) * m_PointCloud->getSize(), m_Data, GL_STATIC_DRAW);
    }
    m_LastPos = eventPress->pos();
}
void ViewWindow::wheelEvent(QWheelEvent *event)
{
    const int degrees = event->delta() / 8;
    const int steps = degrees / 15;

    if(steps > 0) m_ZoomFactor += 0.3f;
    else m_ZoomFactor /= 2.f;

    m_UpdateRender = true;
}

void ViewWindow::initialize()
{

    glPointSize(2.f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);

    m_AngleX = m_AngleY = 0.f;
    m_RotateSpeed = 0.1f;
    srand(time(NULL));
    m_UpdateRender = true;

    m_program = new QOpenGLShaderProgram(this);
    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource.c_str());
    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource.c_str());
    m_program->link();

    m_posAttr = m_program->attributeLocation("posAttr");
    m_colAttr = m_program->attributeLocation("colAttr");
    m_matrixUniform = m_program->uniformLocation("matrix");
    m_zoomUniform = m_program->uniformLocation("zoomFactor");


    m_lookAt = QVector3D(0.f, 0.f, -5.0f);
    m_MVPMatrix.perspective(60.0f, 4.0f/3.0f, 0.1f, 1000.0f);
    m_MVPMatrix.lookAt(m_lookAt, QVector3D(0.f,0.f,0.f), QVector3D(0.f,1.f,0.f));


    m_ZoomFactor = 1.f;

    m_Timer.restart();
    QStringList args = QCoreApplication::arguments();
    testFile(args[1].toStdString().c_str(), args[2].toInt());

    unsigned int cloudSize = m_PointCloud->getSize();

    m_Data = new float6[cloudSize];
    float6 val;

    for(unsigned int i = 0; i < cloudSize; ++i) {
        val.x = m_PointCloud->getPoint(i).m_Position.x;
        val.y = m_PointCloud->getPoint(i).m_Position.y;
        val.z = m_PointCloud->getPoint(i).m_Position.z;

        val.r = 1.f;
        val.g = 0.f;
        val.b = 0.f;

        m_Data[i] = val;
    }



    glGenBuffers(1, &m_VertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float6) * cloudSize, m_Data, GL_DYNAMIC_DRAW);

    if(args[3].toStdString() == "yes"){
        precisionTest();
        testMaxPoint();
    }


    //testFile("objet1.txt");
}


const std::string ViewWindow::vertexShaderSource =
        "#version 330\n \
        in vec3 posAttr;\n \
in vec3 colAttr;\n \
uniform float zoomFactor;\n\
out vec3 col;\n \
uniform mat4 matrix;\n \
void main() { \n\
            col = colAttr;\n \
            gl_Position = matrix * vec4(posAttr*zoomFactor, 1);\n \
            }";

//

const std::string ViewWindow::fragmentShaderSource =
        "#version 330\n \
        in vec3 col;\n \
out vec4 color;\n \
void main() { \n\
            color = vec4(col,1);\n \
            }";

void ViewWindow::render()
{
    m_Timer.restart();
    const qreal retinaScale = devicePixelRatio();
    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_program->bind();

    glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float6) * m_PointCloud->getSize(), m_Data, GL_DYNAMIC_DRAW);
    m_program->enableAttributeArray("posAttr");
    quintptr offset = 0;
    glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, sizeof(float6), (const void*)offset);
    m_program->enableAttributeArray("colAttr");
    offset += sizeof(float)*3;
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, sizeof(float6), (const void*)offset);
    m_program->setUniformValue(m_matrixUniform, m_MVPMatrix);
    m_program->setUniformValue(m_zoomUniform, m_ZoomFactor);
    glDrawArrays(GL_POINTS, 0, m_PointCloud->getSize());
    //glDrawArrays(GL_POINTS, 0, 3);

    m_program->disableAttributeArray("colAttr");
    m_program->disableAttributeArray("posAttr");
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    m_program->release();

}

void
ViewWindow::testFile(const std::string filename, int fromPrototype)
{

    //Lecture du fichier
    std::string path(filename);
    std::ifstream fichier(path.c_str(), std::ios::in);

    if(fichier)
    {
        float initAngle = 180.f;
        float dist = 0.0f;
        glm::vec3 pos = glm::vec3(0.0f);
        float angle = 0.f;
        std::string ligne;

        unsigned int cpt = 0;
        do{
            if(!fromPrototype){
                fichier >> angle >> dist;
            }else{
                fichier >> pos.x >> pos.y >> pos.z >> angle >> dist;
            }

            Point p = m_LaserData.convert(dist, pos, angle, initAngle);
            m_PointCloud->addPoint(p);
            ++cpt;
        }while( getline(fichier, ligne));

        std::cerr << "N° of points : " << cpt << std::endl;
        fichier.close();
    }else
    {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
    }
}

bool
ViewWindow::testMaxPoint()
{
    m_Data = new float6[70000000];
    float6 val;
    val.r = 1.f;
    val.g = 0.f;
    val.b = 0.f;

    const unsigned int pointPerFor = 100000;

    float initAngle = 180.f;
    float dist = 0.f;
    glm::vec3 pos = glm::vec3(0.0f);
    float angle = 0.f;

    dist = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
    angle = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/360.f));

    m_Timer.restart();
    unsigned int i = 0;

    for(; m_Timer.elapsed() < 0.1; ++i){

        #pragma omp parallel for
        for(int j = 0; j < pointPerFor; ++j)
        {
            Point p = m_LaserData.convert(dist, pos, angle, initAngle);
            //m_PointCloud->addPoint(p);
            val.x = p.m_Position.x;
            val.y = p.m_Position.y;
            val.z = p.m_Position.z;
            m_Data[i*pointPerFor+j] = val;
            dist = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/100.f));
            angle = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/360.f));
        }


        m_Timer.restart();

        const qreal retinaScale = devicePixelRatio();
        glViewport(0, 0, width() * retinaScale, height() * retinaScale);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_program->bind();
        glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float6) * i * pointPerFor, m_Data, GL_DYNAMIC_DRAW);
        m_program->enableAttributeArray("posAttr");
        quintptr offset = 0;
        glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, sizeof(float6), (const void*)offset);
        m_program->enableAttributeArray("colAttr");
        offset += sizeof(float)*3;
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, sizeof(float6), (const void*)offset);
        m_program->setUniformValue(m_matrixUniform, m_MVPMatrix);
        m_program->setUniformValue(m_zoomUniform, m_ZoomFactor);
        glDrawArrays(GL_POINTS, 0, i * pointPerFor);

        m_program->disableAttributeArray("colAttr");
        m_program->disableAttributeArray("posAttr");
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        m_program->release();
    }

    std::cerr << "[PASSED] Max number of points in 100ms : " << i*pointPerFor << std::endl;


    render();
}

bool
ViewWindow::precisionTest()
{
    const unsigned int maxTest = 100;
    const float LowX = -50.f;
    const float LowY = -50.f;
    const float HighX = 50.f;
    const float HighY = 50.f;

    float x,y;
    float dist, angle;
    for(unsigned int i = 0; i < maxTest; ++i)
    {
        x = LowX + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(HighX-LowX)));
        y = LowY + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/(HighY-LowY)));

        dist = sqrtf((x*x)+(y*y));
        angle = atanf(y/x);
        if(x < 0.f) angle += M_PI;

        angle = angle * (180.f / M_PI);

        Point p = m_LaserData.convert(dist, glm::vec3(0,0,0), angle, 0.f);
        float absX, absY;
        absX = (x-p.m_Position.x);
        absY = (y-p.m_Position.y);
        absX = absX < 0.f ? -absX : absX;
        absY = absY < 0.f ? -absY : absY;

        if(absX > 0.0001 || absY > 0.0001){
            std::cerr << std::setprecision(9) << "[FAILED] Precision test failed at x = " << x << " & y = " << y << " || i = " << i << std::endl;
            std::cerr << std::setprecision(9) << "Computed x = " << p.m_Position.x << " & y = " << p.m_Position.y << std::endl;
            return false;
        }
    }
    std::cerr << "[PASSED] Precision test passed successfully" << std::endl;
    return true;
}
