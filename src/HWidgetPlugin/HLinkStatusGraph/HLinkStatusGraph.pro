CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(hlinkstatusgraphplugin)
TEMPLATE    = lib

HEADERS     = hlinkstatusgraphplugin.h \

SOURCES     = hlinkstatusgraphplugin.cpp \

RESOURCES   = icons.qrc
LIBS        += -L. 



DESTDIR =   ../../../bin/sysPlugin/function/

INCLUDEPATH += ../../../include/define/
INCLUDEPATH += ../../../include/interface/
INCLUDEPATH += ../../api/HUiHelper/QtAwesome/
INCLUDEPATH += ../../api/HUiHelper/HQss

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../bin/ -lhUiHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../bin/ -lhUiHelper_d
else:unix: CONFIG(release, debug|release) LIBS += -L$$PWD/../../../bin/ -lhUiHelper
else:unix: CONFIG(debug, debug|release) LIBS += -L$$PWD/../../../bin/ -lhUiHelper_d

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target

include(hlinkstatusgraph.pri)






