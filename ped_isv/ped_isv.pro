TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    DisplayModel.cpp \
    DistanceToPoint.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    DisplayModel.h \
    DistanceToPoint.h \
    IDataConversion.h \
    IReconstruction.h

