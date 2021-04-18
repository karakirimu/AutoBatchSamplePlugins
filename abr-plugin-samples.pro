TEMPLATE = subdirs
CONFIG += ordered

win32-msvc* {
    MSVC_VER = $$(VisualStudioVersion)
    equals(MSVC_VER, 14.0){
        message("msvc 2015")
    }

    equals(MSVC_VER, 14.1){
        message("msvc 2017")
    }

    equals(MSVC_VER, 14.2){
        message("msvc 2019")
    }

    QMAKE_CXXFLAGS += /FS
}

SUBDIRS += \
    clitemplete \
    download \
    guitemplete \
    helloworld \
    takeline \
    bufferedcopy \
    filetextreplace \
    sleep \
    makedirectory \
    removedirectory \
    testwindow
