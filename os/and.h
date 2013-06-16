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

#include "and1.h"
#include "and_implementation.h"
#include "and_state.h"
#include "and_handle.h"
#include "and_dir.h"
#include "and_folder_watch.h"
#include "and_factory_exchange.h"
#include "and_window_draw.h"
#include "and_graphics.h"
#include "and_graphics_object.h"
#include "and_bitmap.h"
#include "and_dib.h"
#include "and_palette.h"
#include "and_pen.h"
#include "and_font.h"
#include "and_brush.h"
#include "and_region.h"
//#include "and_draw_dib.h"
#include "and_thread.h"
#include "and_window.h"
#include "and_os.h"
#include "and_port_forward.h"

#define NULL_REF(class) (*((class *) NULL))
CLASS_DECL_ANDROID WNDPROC AfxGetAfxWndProc();
#define AfxWndProc (*AfxGetAfxWndProc())

#define WIN_THREAD(pthread) (dynamic_cast < ::win::thread * > (dynamic_cast < ::ca2::thread * >(pthread)))
#define WIN_WINDOW(pwnd) (dynamic_cast < ::win::window * > (dynamic_cast < ::ca2::window * >(pwnd)))
#define WIN_DC(pgraphics) (dynamic_cast < ::win::graphics * > (dynamic_cast < ::ca2::graphics * > (pgraphics)))
#define SP_DC(pgraphics) (dynamic_cast < ::win::graphics * > (( ::ca2::graphics * )(pgraphics)))
#define WIN_HDC(pgraphics) ((HDC)*(dynamic_cast < ::win::graphics * > (dynamic_cast < ::ca2::graphics * > (pgraphics))))
#define SP_HDC(pgraphics) ((HDC)*(dynamic_cast < ::win::graphics * > ((::ca2::graphics *)(pgraphics))))
#define WIN_DIB(pdib) (dynamic_cast < ::win::dib * > (dynamic_cast < ::ca2::dib * >(pdib)))



CLASS_DECL_ANDROID void _AfxTraceMsg(const char * lpszPrefix, ::ca2::signal_object * pobj);
CLASS_DECL_ANDROID void _AfxTraceMsg(const char * lpszPrefix, LPMSG lpmsg);

CLASS_DECL_ANDROID BOOL __cdecl AfxIsIdleMessage(::ca2::signal_object * pobj);
CLASS_DECL_ANDROID BOOL __cdecl AfxIsIdleMessage(MSG* pMsg);


CLASS_DECL_ANDROID void AfxProcessWndProcException(base_exception*, ::ca2::signal_object * pobj);
CLASS_DECL_ANDROID void __cdecl AfxPreTranslateMessage(::ca2::signal_object * pobj);


#include "and_application.h"
