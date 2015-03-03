TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    DisplayModel.cpp \
    DistanceToPoint.cpp \
    VEFModel.cpp \
    scannerdata.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    DisplayModel.h \
    DistanceToPoint.h \
    IDataConversion.h \
    IReconstruction.h \
    point.h \
    MA_PacketConversion.h \
    VEFModel.h \
    Point.h \
    scannerdata.h

INCLUDEPATH += /net/cremi/algirard/espaces/travail/PED/glm/
