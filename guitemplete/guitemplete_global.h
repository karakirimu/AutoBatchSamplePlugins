#ifndef GUITEMPLETE_GLOBAL_H
#define GUITEMPLETE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GUITEMPLETE_LIBRARY)
#  define GUITEMPLETE_EXPORT Q_DECL_EXPORT
#else
#  define GUITEMPLETE_EXPORT Q_DECL_IMPORT
#endif

#endif // GUITEMPLETE_GLOBAL_H