HEADERS += \
    hwindowapi.h

SOURCES += \
    hwindowapi.cpp
QT       += core widgets
TEMPLATE = lib
CONFIG(debug, debug|release){
    DESTDIR = ../../../bin/
    TARGET = hWindowApi_d
} else {
    DESTDIR = ../../../bin/
    TARGET = hWindowApi
}
