#pragma once

#if core_level_3
#define IMPLEMENT_VISTA_TOOLS
#endif

#include "and.h"
#include "and_internal.h"

CLASS_DECL_ANDROID void vfxThrowFileException(::ca2::application * papp, int cause, LONG lOsError, const char * lpszFileName = NULL);
