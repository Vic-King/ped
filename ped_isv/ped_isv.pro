OTHER_FILES += \
    deployment.pri \
    ped_isv.pro.user

HEADERS += \
    MA_PacketConversion.h \
    Point.h \
    VEFModel.h \
    Scene.h \
    RawData.h \
    PointCloud.h

SOURCES += \
    VEFModel.cpp \
    Point.cpp \
    Main.cpp \
    Scene.cpp \
    RawData.cpp \
    PointCloud.cpp

INCLUDEPATH += /net/cremi/vfrancoi/espaces/travail/M2/S4/ped/glm
