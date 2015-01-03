#pragma once



#define __BSD_VISIBLE         1
#define BSD_STYLE_SOCKETS
#if !defined VARIADIC_TEMPLATE
#define VARIADIC_TEMPLATE
#endif


//typedef short index;


#if defined(_DEBUG) || defined(NDEBUG)
#define DEBUG
#endif

#ifdef __clang__
#define VSNORD // Visual Studio Nor-droid (Android)
#endif

#ifndef ANDROID
#define ANDROID
#endif

#undef _GNU_SOURCE
#define __STRICT_ANSI__ 1
#define _POSIX_SOURCE 1
#define _POSIX_C_SOURCE 200809L
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE 700
#endif
#ifndef _XOPEN_SOURCE_EXTENDED
#define _XOPEN_SOURCE_EXTENDED 1
#endif
#ifndef _LARGEFILE64_SOURCE
#define _LARGEFILE64_SOURCE
#endif
#ifndef _SVID_SOURCE
#define _SVID_SOURCE 1
#endif

#include <features.h>
#undef _GNU_SOURCE
#define _GNU_SOURCE 1
#define __USE_GNU 1


#define __WINESRC__


#define CLASS_DECL_EXPORT
#define CLASS_DECL_IMPORT
#define CLASS_DECL_THREAD __thread

#ifdef _LP64
#define OS64BIT
#endif




typedef int int_bool;


#define index system_index
#define lconv system_lconv
#define localeconv system_localeconv






