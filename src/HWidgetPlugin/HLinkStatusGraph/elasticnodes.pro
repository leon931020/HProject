QT += widgets core gui



HEADERS += \
        edge.h \
        node.h \
        graphwidget.h \
    hconnectionstatus.h \
    hdefine.h \
    descriptionwidget.h \
    rightpanelwidget.h

SOURCES += \
        edge.cpp \
        main.cpp \
        node.cpp \
        graphwidget.cpp \
    hconnectionstatus.cpp \
    descriptionwidget.cpp \
    rightpanelwidget.cpp

# install
TEMPLATE = app
TARGET = elasticnodes

RESOURCES += \
    font.qrc

FORMS += \
    hconnectionstatus.ui



