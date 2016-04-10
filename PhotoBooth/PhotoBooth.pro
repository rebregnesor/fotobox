######################################################################
# Automatically generated by qmake (2.01a) Wed Mar 23 18:44:57 2016
######################################################################

TEMPLATE = app
TARGET = PhotoBooth
DEPENDPATH += .
INCLUDEPATH += .


# Input
HEADERS += \
    src/PhotoBooth.h \
    src/Countdown.h \
    src/SerialPort.h \
    src/livepreview.h \
    src/infopanel.h \
    src/thumbnailview.h \
    src/gridimagecompositor.h
SOURCES += \
    src/InfoPanel.cpp \
    src/Countdown.cpp \
    src/LivePreview.cpp \
    src/ThumbnailView.cpp \
    src/PhotoBooth.cpp \
    src/SerialPort.cpp \
    src/gridimagecompositor.cpp


LIBS += -lgphoto2 -lopencv_core -lopencv_highgui -lopencv_imgproc

CONFIG += serialport