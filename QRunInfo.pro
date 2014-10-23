#-------------------------------------------------
#
# Project created by QtCreator 2014-10-23T16:35:17
#
#-------------------------------------------------

QT    += core gui widgets

TARGET = QRunInfo
TEMPLATE = lib

DEFINES += QRUNINFO_LIBRARY

SOURCES += \
    kdlockfile.cpp \ 
    kdrunoncechecker.cpp \
    kdselfrestarter.cpp \
    kdsysinfo.cpp \
    link.cpp




HEADERS +=\
        qruninfo_global.h \
    adminauthorization.h \
    kdlockfile.h \
    kdlockfile_p.h \
    kdrunoncechecker.h \
    kdselfrestarter.h \
    kdsysinfo.h \
    link.h

unix:!mac {
    SOURCES +=  adminauthorization_x11.cpp \
        kdlockfile_unix.cpp \
        kdsysinfo_x11.cpp
}

win32 {
    SOURCES += adminauthorization_win.cpp \
    kdlockfile_win.cpp \
    kdsysinfo_win.cpp \
    sysinfo_win.cpp

    LIBS += -lole32 -lshell32 -lmpr
}

mac {
     SOURCES += kdsysinfo_mac.cpp \
    adminauthorization_mac.cpp \
    kdlockfile_unix.cpp
}
