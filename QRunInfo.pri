
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
    SOURCES +=  $$PWD/adminauthorization_x11.cpp \
        $$PWD/kdlockfile_unix.cpp \
        $$PWD/kdsysinfo_x11.cpp
}

win32 {
    SOURCES += $$PWD/adminauthorization_win.cpp \
    $$PWD/kdlockfile_win.cpp \
    $$PWD/kdsysinfo_win.cpp \
    $$PWD/sysinfo_win.cpp

    LIBS += -lole32 -lshell32 -lmpr
}

mac {
     SOURCES += $$PWD/kdsysinfo_mac.cpp \
    $$PWD/adminauthorization_mac.cpp \
    $$PWD/kdlockfile_unix.cpp
}
