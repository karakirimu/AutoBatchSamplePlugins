QT += widgets

TEMPLATE = lib
DEFINES += GUITEMPLATE_LIBRARY

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
    guitemplate.cpp \
    guitemplatewidget.cpp

HEADERS += \
    guitemplate_global.h \
    guitemplate.h \
    guitemplatewidget.h

TRANSLATIONS += \
    guitemplate_en_US.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    guitemplate.json

FORMS += \
    guitemplatewidget.ui
