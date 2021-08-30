QT += core gui \
       widgets network

TEMPLATE = lib
DEFINES += DOWNLOAD_LIBRARY

CONFIG += c++11 \
          skip_target_version_ext \ # Prevent automatic conversion of dll name
          plugin

VERSION = 1.0.0

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# ExtraPluginInterface
include($$PWD/../AutoBatchTools/src/plugininterface/plugininterface.pri)

# If you want to perform a download that includes https in Windows,
# you need to download and install OpenSSL.
# When setting OpenSSL, uncomment the following win32 block.
#win32 {
#    contains(QMAKE_TARGET.arch, "x86_64"){
#        # 64 bit
#        DEFINES  += "OPENSSL_DEFINED=\"1\""
#        INCLUDEPATH += "C:/Program Files/OpenSSL-Win64/include"
#        LIBS += -L"C:/Program Files/OpenSSL-Win64/lib" -llibcrypto \
#                -L"C:/Program Files/OpenSSL-Win64/lib" -llibssl
#    }
#}

SOURCES += \
    download.cpp \
    downloadwidget.cpp

HEADERS += \
    download_global.h \
    download.h \
    downloadwidget.h

TRANSLATIONS += \
    download_en_US.ts

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    download.json

FORMS += \
    downloadwidget.ui
