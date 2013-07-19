#pragma once


#include "ca2/ca2.h"


#ifdef _VMSANDROID_LIBRARY
    #define CLASS_DECL_ANDROID  CLASS_DECL_EXPORT
#else
    #define CLASS_DECL_ANDROID  CLASS_DECL_IMPORT
#endif


string get_error_message(DWORD dwError);

::ca2::application *     win_instantiate_application(::ca2::application * pappSystem, const char * pszId);

/////////////////////////////////////////////////////////////////////////////
// explicit initialization for general purpose classes

CLASS_DECL_ANDROID BOOL AfxInitialize(BOOL bDLL = FALSE, DWORD dwVersion = _MFC_VER);

/////////////////////////////////////////////////////////////////////////////
// stop on a specific primitive::memory request

// Debugger hook on specified allocation request - Obsolete
CLASS_DECL_ANDROID void AfxSetAllocStop(LONG lRequestNumber);

// Return TRUE if primitive::memory is sane or print out what is wrong
CLASS_DECL_ANDROID BOOL AfxCheckMemory();

// Return TRUE if valid primitive::memory block of nBytes
CLASS_DECL_ANDROID BOOL AfxIsMemoryBlock(const void * p, UINT nBytes,
   LONG* plRequestNumber = NULL);

// helper routines for non-C++ EH implementations
// for THROW_LAST auto-delete backward compatiblity
CLASS_DECL_ANDROID void AfxThrowLastCleanup();

// other out-of-line helper functions
CLASS_DECL_ANDROID void AfxTryCleanup();


/////////////////////////////////////////////////////////////////////////////
// Global implementation helpers

// window creation hooking
CLASS_DECL_ANDROID void AfxHookWindowCreate(::user::interaction * pWnd);
CLASS_DECL_ANDROID BOOL AfxUnhookWindowCreate();
CLASS_DECL_ANDROID void AfxResetMsgCache();

// for backward compatibility to previous versions
#define _AfxHookWindowCreate    AfxHookWindowCreate
#define _AfxUnhookWindowCreate  AfxUnhookWindowCreate

#include "android1.h"
#include "android_implementation.h"
#include "android_state.h"
#include "android_handle.h"
#include "android_dir.h"
#include "android_folder_watch.h"
#include "android_factory_exchange.h"
#include "android_window_draw.h"
#include "android_graphics.h"
#include "android_graphics_object.h"
#include "android_bitmap.h"
#include "android_dib.h"
#include "android_palette.h"
#include "android_pen.h"
#include "android_font.h"
#include "android_brush.h"
#include "android_region.h"
//#include "android_draw_dib.h"
#include "android_thread.h"
#include "android_window.h"
#include "android_os.h"
#include "android_port_forward.h"

#define NULL_REF(class) (*((class *) NULL))
CLASS_DECL_ANDROID WNDPROC AfxGetAfxWndProc();
#define AfxWndProc (*AfxGetAfxWndProc())

#define WIN_THREAD(pthread) (dynamic_cast < ::android::thread * > (dynamic_cast < ::ca2::thread * >(pthread)))
#define WIN_WINDOW(pwnd) (dynamic_cast < ::android::window * > (dynamic_cast < ::ca2::window * >(pwnd)))
#define WIN_DC(pgraphics) (dynamic_cast < ::android::graphics * > (dynamic_cast < ::ca2::graphics * > (pgraphics)))
#define SP_DC(pgraphics) (dynamic_cast < ::android::graphics * > (( ::ca2::graphics * )(pgraphics)))
#define WIN_HDC(pgraphics) ((HDC)*(dynamic_cast < ::android::graphics * > (dynamic_cast < ::ca2::graphics * > (pgraphics))))
#define SP_HDC(pgraphics) ((HDC)*(dynamic_cast < ::android::graphics * > ((::ca2::graphics *)(pgraphics))))
#define WIN_DIB(pdib) (dynamic_cast < ::android::dib * > (dynamic_cast < ::ca2::dib * >(pdib)))



CLASS_DECL_ANDROID void _AfxTraceMsg(const char * lpszPrefix, ::ca2::signal_object * pobj);
CLASS_DECL_ANDROID void _AfxTraceMsg(const char * lpszPrefix, LPMSG lpmsg);

CLASS_DECL_ANDROID BOOL __cdecl AfxIsIdleMessage(::ca2::signal_object * pobj);
CLASS_DECL_ANDROID BOOL __cdecl AfxIsIdleMessage(MSG* pMsg);


CLASS_DECL_ANDROID void AfxProcessWndProcException(base_exception*, ::ca2::signal_object * pobj);
CLASS_DECL_ANDROID void __cdecl AfxPreTranslateMessage(::ca2::signal_object * pobj);


#include "android_application.h"
