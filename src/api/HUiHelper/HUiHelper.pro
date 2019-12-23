include(./QtAwesome/QtAwesome.pri)
include(./HQss/hqss.pri)
QT       += core widgets


TEMPLATE = lib
CONFIG(debug, debug|release){
    DESTDIR = ../../../bin/
    TARGET = hUiHelper_d
} else {
    DESTDIR = ../../../bin/
    TARGET = hUiHelper
}
