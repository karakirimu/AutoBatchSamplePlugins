QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
VERSION = 1.0.0

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# ExtraPluginInterface
include($$PWD/../AutoBatchTools/src/plugininterface/plugininterface.pri)

SOURCES += \
    dummytable.cpp \
    main.cpp \
    receivelistdialog.cpp \
    testwindow.cpp

HEADERS += \
    dummytable.h \
    receivelistdialog.h \
    testwindow.h

FORMS += \
    receivelistdialog.ui \
    testwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
