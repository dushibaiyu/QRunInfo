#ifndef QRUNINFO_GLOBAL_H
#define QRUNINFO_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef QRUNINFO
#if defined(QRUNINFO_LIBRARY)
#  define QRUNINFOSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QRUNINFOSHARED_EXPORT Q_DECL_IMPORT
#endif
#else
#define QRUNINFOSHARED_EXPORT
#endif
#endif // QRUNINFO_GLOBAL_H
