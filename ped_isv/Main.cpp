#include <iostream>
#include <QtGui/QGuiApplication>
#include "ViewWindow.h"


int main(int argc, char* argv[])
{
    QGuiApplication app(argc, argv);
    QSurfaceFormat glFormat;
    glFormat.setVersion( 3, 3 );
    glFormat.setSamples(16);

    QSurfaceFormat format;
    format.setSamples(16);

    ViewWindow window;
    window.setFormat(glFormat);
    window.resize(640, 480);
    window.show();
    window.setAnimating(true);
    return app.exec();

}
