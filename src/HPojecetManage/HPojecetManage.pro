#-------------------------------------------------
#
# Project created by QtCreator 2019-12-05T19:36:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HPojecetManage
DESTDIR = ../../bin/
TEMPLATE = app
INCLUDEPATH += ../../include/interface/
INCLUDEPATH += ../HPluginManage/
INCLUDEPATH += ../../include/define/
INCLUDEPATH += ../api/HUiHelper/HQss/
INCLUDEPATH += ../api/HWindowApi/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bin/ -lhUiHelper
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bin/ -lhUiHelper_d
else:unix: CONFIG(release, debug|release) LIBS += -L$$PWD/../../bin/ -lhUiHelper
else:unix: CONFIG(debug, debug|release) LIBS += -L$$PWD/../../bin/ -lhUiHelper_d

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bin/ -lhWindowApi
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bin/ -lhWindowApi_d
else:unix: CONFIG(release, debug|release) LIBS += -L$$PWD/../../bin/ -lhWindowApi
else:unix: CONFIG(debug, debug|release) LIBS += -L$$PWD/../../bin/ -lhWindowApi_d


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../bin/ -lhWidgetLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../bin/ -lhWidgetLibrary_d
else:unix: CONFIG(release, debug|release) LIBS += -L$$PWD/../../bin/ -lhWidgetLibrary
else:unix: CONFIG(debug, debug|release) LIBS += -L$$PWD/../../bin/ -lhWidgetLibrary_d

SOURCES += main.cpp \
    hprojectwindow.cpp

HEADERS  += \
    hprojectwindow.h

FORMS    += \
    hprojectmanage.ui \
    hprojectwindow.ui
