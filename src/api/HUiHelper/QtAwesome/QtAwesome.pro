#-------------------------------------------------
#
# Project created by QtCreator 2013-04-18T13:28:42
#
#-------------------------------------------------


TEMPLATE = lib
CONFIG(debug, debug|release){
    DESTDIR = ../../../bin/
    TARGET = QtAwesome_d
} else {
    DESTDIR = ../../../bin/
    TARGET = QtAwesome
}
QT += widgets

SOURCES += QtAwesome.cpp QtAwesomeAnim.cpp
HEADERS += QtAwesome.h QtAwesomeAnim.h

isEmpty(PREFIX) {
    unix {
        PREFIX = /usr
    } else {
        PREFIX = $$[QT_INSTALL_PREFIX]
    }
}

install_headers.files = QtAwesome.h QtAwesomeAnim.h
install_headers.path = $$PREFIX/include
target.path = $$PREFIX/lib
INSTALLS += install_headers target

RESOURCES += \
    QtAwesome.qrc
