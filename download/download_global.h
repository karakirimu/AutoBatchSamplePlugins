#ifndef DOWNLOAD_GLOBAL_H
#define DOWNLOAD_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DOWNLOAD_LIBRARY)
#  define DOWNLOAD_EXPORT Q_DECL_EXPORT
#else
#  define DOWNLOAD_EXPORT Q_DECL_IMPORT
#endif

#endif // DOWNLOAD_GLOBAL_H
