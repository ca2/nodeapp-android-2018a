#pragma once


#include "base/base/base/base.h"


#ifdef _VMSANDROID_LIBRARY
    #define CLASS_DECL_ANDROID  CLASS_DECL_EXPORT
#else
    #define CLASS_DECL_ANDROID  CLASS_DECL_IMPORT
#endif




string get_error_message(DWORD dwError);

::ca2::application *     win_instantiate_application(::ca2::application * pappSystem, const char * pszId);

/////////////////////////////////////////////////////////////////////////////
// explicit initialization for general purpose classes

//CLASS_DECL_ANDROID BOOL AfxInitialize(BOOL bDLL = FALSE, DWORD dwVersion = _MFC_VER);
CLASS_DECL_ANDROID BOOL AfxInitialize(BOOL bDLL = FALSE, DWORD dwVersion = 0);

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
#include "android_dir.h"
#include "android_factory_exchange.h"
#include "android_window_draw.h"
#include "android_thread.h"
#include "android_window.h"
#include "android_os.h"
#include "android_port_forward.h"
#include "android_copydesk.h"
#include "android_crypt.h"
#include "android_ip_enum.h"

#define NULL_REF(class) (*((class *) NULL))
// xxx CLASS_DECL_ANDROID WNDPROC AfxGetAfxWndProc();
#define AfxWndProc (*AfxGetAfxWndProc())

#define ANDROID_THREAD(pthread) (dynamic_cast < ::android::thread * > (dynamic_cast < ::ca2::thread * >(pthread)))
#define ANDROID_WINDOW(pwnd) (dynamic_cast < ::android::window * > (((sp(::ca2::window))(pwnd)).m_p))
#define ANDROID_DC(pgraphics) (dynamic_cast < ::android::graphics * > (dynamic_cast < ::draw2d::graphics * > (pgraphics)))
#define SP_DC(pgraphics) (dynamic_cast < ::android::graphics * > (( ::draw2d::graphics * )(pgraphics)))
#define ANDROID_HDC(pgraphics) ((HDC)*(dynamic_cast < ::android::graphics * > (dynamic_cast < ::draw2d::graphics * > (pgraphics))))
#define SP_HDC(pgraphics) ((HDC)*(dynamic_cast < ::android::graphics * > ((::draw2d::graphics *)(pgraphics))))
#define ANDROID_DIB(pdib) (dynamic_cast < ::android::dib * > (dynamic_cast < ::draw2d::dib * >(pdib)))

#include "android_shell.h"

CLASS_DECL_ANDROID void __trace_message(const char * lpszPrefix, ::ca2::signal_object * pobj);
CLASS_DECL_ANDROID void __trace_message(const char * lpszPrefix, LPMESSAGE lpmsg);

CLASS_DECL_ANDROID WINBOOL __cdecl __is_idle_message(::ca2::signal_object * pobj);
CLASS_DECL_ANDROID WINBOOL __cdecl __is_idle_message(MESSAGE* pMsg);


CLASS_DECL_ANDROID void AfxProcessWndProcException(base_exception*, ::ca2::signal_object * pobj);
CLASS_DECL_ANDROID void __cdecl __pre_translate_message(::ca2::signal_object * pobj);


#include "android_application.h"



WINBOOL PeekMessage(
    LPMESSAGE lpMsg,
    oswindow hWnd,
    UINT wMsgFilterMin,
    UINT wMsgFilterMax,
    UINT wRemoveMsg);

WINBOOL GetMessage(
    LPMESSAGE lpMsg,
    oswindow hWnd,
    UINT wMsgFilterMin,
    UINT wMsgFilterMax);



int32_t CLASS_DECL_ANDROID __android_main(int32_t argc, char * argv[]);


CLASS_DECL_ANDROID void vfxThrowFileException(sp(::ca2::application) papp, int32_t cause, LONG lOsError, const char * lpszFileName = NULL);
