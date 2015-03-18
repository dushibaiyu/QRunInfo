
CONFIG += C++11

HEADERS +=\
    $$PWD/qruninfo_global.h \
    $$PWD/adminauthorization.h \
    $$PWD/kdlockfile.h \
    $$PWD/kdlockfile_p.h \
    $$PWD/kdrunoncechecker.h \
    $$PWD/kdselfrestarter.h \
    $$PWD/kdsysinfo.h \
    $$PWD/link.h

SOURCES += \
    $$PWD/kdlockfile.cpp \
    $$PWD/kdrunoncechecker.cpp \
    $$PWD/kdselfrestarter.cpp \
    $$PWD/kdsysinfo.cpp \
    $$PWD/link.cpp

unix:!mac {
    SOURCES +=  \
        $$PWD/adminauthorization_x11.cpp \
        $$PWD/kdlockfile_unix.cpp \
        $$PWD/kdsysinfo_x11.cpp
}

win32 {
    HEADERS += $$PWD/win32path.h

    SOURCES += \
        $$PWD/adminauthorization_win.cpp \
        $$PWD/kdlockfile_win.cpp \
        $$PWD/kdsysinfo_win.cpp \
        $$PWD/sysinfo_win.cpp \
        $$PWD/win32path.cpp

    LIBS += -lole32 -lshell32 -lmpr -lAdvapi32

    win32-g++*:LIBS += -luuid
    win32-g++*:QMAKE_CXXFLAGS += -Wno-missing-field-initializers
}

mac {
     SOURCES += \
        $$PWD/kdsysinfo_mac.cpp \
        $$PWD/adminauthorization_mac.cpp \
        $$PWD/kdlockfile_unix.cpp
     LIBS += -framework Carbon -framework Security
}

INCLUDEPATH += $$PWD/
