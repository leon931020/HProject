CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(hlinkstatusgraphplugin)
TEMPLATE    = lib

HEADERS     = hlinkstatusgraphplugin.h
SOURCES     = hlinkstatusgraphplugin.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 



DESTDIR =   ../../../bin/sysPlugin/function/

INCLUDEPATH += ../../../include/define/
INCLUDEPATH += ../../../include/interface/
INCLUDEPATH += ../../api/QtAwesome/


greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(hlinkstatusgraph.pri)
