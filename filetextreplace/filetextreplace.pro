#-------------------------------------------------
#
# Project created by QtCreator 2019-04-30T09:48:48
#
#-------------------------------------------------

QT       += core gui \
            widgets

TEMPLATE = lib

CONFIG += c++11 \
          skip_target_version_ext \ # Prevent automatic conversion of dll name
          plugin

VERSION = 1.0.0

DEFINES += FILETEXTREPLACE_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# ExtraPluginInterface
include($$PWD/../AutoBatchTools/src/plugininterface/plugininterface.pri)

TRANSLATIONS += \
        $$PWD/translation/filetextreplace_en.ts \
        $$PWD/translation/filetextreplace_ja.ts

SOURCES += \
        filetextreplace.cpp \
        filetextreplacewidget.cpp

HEADERS += \
        filetextreplace.h \
        filetextreplace_global.h  \
        filetextreplacewidget.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    filetextreplacewidget.ui

DISTFILES += \
    filetextreplace.json
