#include "framework.h"


// Note: in separate module so it can be replaced if needed

void CLASS_DECL_ANDROID __abort()
{
//   TRACE(::ca2::trace::category_AppMsg, 0, "AfxAbort called.\n");

   __android_term();
   abort();
}

/////////////////////////////////////////////////////////////////////////////
