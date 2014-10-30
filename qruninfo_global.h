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

#define QRUNINFO_NAMEPASE_BEGIN namespace QRunInfo {

#define QRUNINFO_NAMEPASE_END }

#endif // QRUNINFO_GLOBAL_H
