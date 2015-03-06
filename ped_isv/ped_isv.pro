TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

include(deployment.pri)
qtcAddDeployment()



INCLUDEPATH += /net/cremi/algirard/espaces/travail/PED/glm/

HEADERS += \
    Point.h \
    PointCloud.h \
    RawData.h \
    Scene.h \
    VEFModel.h \
    Packet.h \
    MA_PacketConversion.h

SOURCES += \
    Main.cpp \
    Point.cpp \
    PointCloud.cpp \
    RawData.cpp \
    Scene.cpp \
    VEFModel.cpp
