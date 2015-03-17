#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <iostream>
#include <QtGui/QGuiApplication>
#include <QtGui/QMatrix4x4>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QScreen>
#include <QtCore/qmath.h>
#include <QtGui/QWheelEvent>
#include <QtGui/QMouseEvent>
#include <ctime>
#include <iomanip>
#include <QtOpenGL//QGLFormat>
#include <QtGui/QOpenGLVertexArrayObject>
#include <QtGui/QOpenGLBuffer>

#include "openglwindow.hpp"

#include "Scene.h"

class ViewWindow : public OpenGLWindow
{
public:
    ViewWindow() : m_VertexBuffer(QOpenGLBuffer::VertexBuffer), m_Scene(new Scene()) {}
    ~ViewWindow(){delete m_Data;}

    void initialize();
    void render();
    void updatePoints(bool drawDecVertices);

private:
    struct float6{
        float x,y,z;
        float r,g,b;
    };

    GLuint loadShader(GLenum type, const char *source)
    {
        GLuint shader = glCreateShader(type);
        glShaderSource(shader, 1, &source, 0);
        glCompileShader(shader);
        return shader;
    }


    void mouseMoveEvent(QMouseEvent *eventMove);
    void mousePressEvent(QMouseEvent *eventPress);
    void mouseReleaseEvent(QMouseEvent *releaseEvent);
    void wheelEvent(QWheelEvent *event);

    static const std::string vertexShaderSource;
    static const std::string fragmentShaderSource;

    Scene* m_Scene;

    GLuint m_posAttr;
    GLuint m_colAttr;
    GLuint m_matrixUniform;
    GLuint m_zoomUniform;

    QMatrix4x4 m_MVPMatrix;

    float6* m_Data;

    QOpenGLShaderProgram *m_program;

    QOpenGLVertexArrayObject m_VAO;
    GLuint m_VertexBuffer;
    GLuint vbo;

    QPoint m_LastPos;
    QVector3D m_lookAt;
    bool m_Rotate;
    bool m_UpdateRender;
    float m_AngleX, m_AngleY;
    float m_RotateSpeed;
    float m_ZoomFactor;

    GLfloat* vertices;
    GLfloat* colors;
    float m_scale;
    float mx, my, mz;

};

#endif // VIEWWINDOW_H