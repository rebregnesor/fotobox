######################################################################
# Automatically generated by qmake (2.01a) Wed Mar 23 18:44:57 2016
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .


# Input
HEADERS += \
    gui.h \
    PhotoBooth.h \
    Countdown.h \
    gpio.h
SOURCES += \
    LeftColumn.cpp \
    Countdown.cpp \
    LivePreview.cpp \
    RightColumn.cpp \
    PhotoBooth.cpp \
    gpio.cpp


LIBS += -lgphoto2 -lopencv_core -lopencv_highgui -lopencv_imgproc -lwiringPi
