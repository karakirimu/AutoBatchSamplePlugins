QT += widgets

TEMPLATE = lib
DEFINES += GUITEMPLETE_LIBRARY

CONFIG += c++11 \
          skip_target_version_ext \ # Prevent automatic conversion of dll name
          plugin

VERSION = 1.0.0

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# ExtraPluginInterface
include($$PWD/../AutoBatchTools/src/plugininterface/plugininterface.pri)

SOURCES += \
    guitemplete.cpp \
    guitempletewidget.cpp

HEADERS += \
    guitemplete_global.h \
    guitemplete.h \
    guitempletewidget.h

TRANSLATIONS += \
    guitemplete_en_US.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    guitemplete.json

FORMS += \
    guitempletewidget.ui
