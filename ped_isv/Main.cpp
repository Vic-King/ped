#include <iostream>
#include <QtGui/QGuiApplication>
#include "ViewWindow.h"


int main(int argc, char* argv[])
{
    if(argc < 4){
        std::cerr << "Usage : ./ped_isv [pointFile] [fromPrototype(0|1)] [launchTest(\"yes\"|\"no\")]" << std::endl;
        exit(1);
    }

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
