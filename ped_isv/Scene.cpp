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

    m_continue = true;

    while (continue){

        doEvent ();

        //WaitPacket

        Point p = m_rawData->convertPacket(/*packet*/);

        m_pointCloud->addPoint(p);
    }
}

void doEvent () {

}

//void ViewWindow::initialize()
//{
//    mesh.load("FantomeLite.obj");
//    data = new float*[mesh.faces.size()*3];
//    for(unsigned int i = 0; i < mesh.faces.size(); ++i)
//    {
//        for(int v = 0; v < 3; v++)
//        {
//            data[i*3+v] = new float[3];
//            data[i*3+v][0] = mesh.faces[i].vertices[v]->x;
//            data[i*3+v][1] = mesh.faces[i].vertices[v]->y;
//            data[i*3+v][2] = mesh.faces[i].vertices[v]->z;
//        }
//    }

//    const unsigned int shaderAttribute = 0;

//    glGenBuffers(1, &vbo);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
//    glVertexAttribPointer(shaderAttribute, 3, GL_FLOAT, GL_FALSE, 0, 0);
//    glEnableVertexAttribArray(shaderAttribute);
//    glBindBuffer(GL_ARRAY_BUFFER, vbo);

//    m_program = new QOpenGLShaderProgram(this);
//    m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource.c_str());
//    m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource.c_str());
//    m_program->link();
//    m_posAttr = m_program->attributeLocation("posAttr");
//    m_colAttr = m_program->attributeLocation("colAttr");
//    m_matrixUniform = m_program->uniformLocation("matrix");
//}


//const std::string ViewWindow::vertexShaderSource =
//    "attribute highp vec4 posAttr; \
//    attribute lowp vec4 colAttr; \
//    varying lowp vec4 col; \
//    uniform highp mat4 matrix; \
//    void main() { \
//       col = colAttr; \
//       gl_Position = matrix * posAttr; \
//    }";

//const std::string ViewWindow::fragmentShaderSource =
//    "varying lowp vec4 col; \
//    void main() { \
//       gl_FragColor = col; \
//    }";

//void ViewWindow::render()
//{
//    const qreal retinaScale = devicePixelRatio();
//    glViewport(0, 0, width() * retinaScale, height() * retinaScale);

//    glClear(GL_COLOR_BUFFER_BIT);

//    m_program->bind();

//    QMatrix4x4 matrix;
//    matrix.perspective(60.0f, 4.0f/3.0f, 0.1f, 100.0f);
//    //matrix.translate(m_camera.position.x(), m_camera.position.y(), m_camera.position.z());
//    //matrix.rotate(50.0f * m_frame / screen()->refreshRate(), 0, 1, 0);

//    m_program->setUniformValue(m_matrixUniform, matrix);

//    //glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, vertices);
//    //glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colors);

//    //glEnableVertexAttribArray(0);
//    //glEnableVertexAttribArray(1);

//    glDrawArrays(GL_TRIANGLES, 0, mesh.faces.size()*3);

//    //glDisableVertexAttribArray(1);
//    //glDisableVertexAttribArray(0);

//    m_program->release();
//    ++m_frame;
//}
//int main(int argc, char **argv)
//{
//    QGuiApplication app(argc, argv);
//    QSurfaceFormat format;
//    format.setSamples(16);
//    ViewWindow window;
//    window.setFormat(format);
//    window.resize(640, 480);
//    window.show();
//    window.setAnimating(true);
//    return app.exec();
//}
