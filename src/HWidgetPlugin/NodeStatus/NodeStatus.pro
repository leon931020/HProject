CONFIG      += plugin debug_and_release
TARGET      = $$qtLibraryTarget(nodestatusplugin)
TEMPLATE    = lib

HEADERS     += nodestatusplugin.h \
               nodestatus.h
SOURCES     += nodestatusplugin.cpp \
               nodestatus.cpp
RESOURCES   = icons.qrc
LIBS        += -L. 


DESTDIR =   ../../../bin/sysPlugin/function/

INCLUDEPATH += ../../../include/define/
INCLUDEPATH += ../../../include/interface/
INCLUDEPATH += ../../api/HUiHelper/QtAwesome/
INCLUDEPATH += ../../HConfigManage/
INCLUDEPATH += ../../api/HWindowApi/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../bin/ -lhUiHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../bin/ -lhUiHelper_d
else:unix: CONFIG(release, debug|release) LIBS += -L$$PWD/../../../bin/ -lhUiHelper
else:unix: CONFIG(debug, debug|release) LIBS += -L$$PWD/../../../bin/ -lhUiHelper_d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../bin/ -lhConfigManage
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../bin/ -lhConfigManage_d
else:unix: CONFIG(release, debug|release) LIBS += -L$$PWD/../../../bin/ -lhConfigManage
else:unix: CONFIG(debug, debug|release) LIBS += -L$$PWD/../../../bin/ -lhConfigManage_d

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += designer
} else {
    CONFIG += designer
}

target.path = $$[QT_INSTALL_PLUGINS]/designer
INSTALLS    += target


FORMS += \
    nodestatus.ui \

include(nodesinfo.pri)
include(nodeList.pri)


