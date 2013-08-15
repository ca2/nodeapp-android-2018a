#pragma once

namespace android
{
   class thread;

   class android
   {
      int function();
   };

/* 
   CLASS_DECL_ANDROID HINSTANCE   LoadLibrary(const char * lpsz);
   CLASS_DECL_ANDROID BOOL        SHGetSpecialFolderPath(oswindow hwnd, string &str, int csidl, BOOL fCreate);
   CLASS_DECL_ANDROID DWORD       GetFileAttributes(const char * lpFileName);
   CLASS_DECL_ANDROID BOOL        CreateDirectory(const char * lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes);
   CLASS_DECL_ANDROID DWORD       GetCurrentDirectory(string & str);
   CLASS_DECL_ANDROID DWORD       GetTempPath(string & str);
   CLASS_DECL_ANDROID LONG        RegQueryValue(HKEY hkey, const char * lpszSubKey, string & str);
   CLASS_DECL_ANDROID HICON       ExtractIcon(HINSTANCE hInst, const char * lpszExeFileName, UINT nIconIndex);
   CLASS_DECL_ANDROID BOOL        DeleteFile(const char * lpFileName);
   CLASS_DECL_ANDROID int         GetMenuStringW(HMENU hMenu, UINT uIDItem, string & str, UINT flags);
   CLASS_DECL_ANDROID void        TimeToFileTime(::ca2::application * papp, const class time& time, LPFILETIME pFileTime);

*/

} // namespace android



// Placed on frame for EXCEPTION linkage, or base_exception cleanup
struct CLASS_DECL_ANDROID __EXCEPTION_LINK
{
   __EXCEPTION_LINK* m_pLinkPrev;    // previous top, next in handler chain
   base_exception* m_pException;   // current exception (NULL in try block)

   __EXCEPTION_LINK();       // for initialization and linking
   ~__EXCEPTION_LINK()       // for cleanup and unlinking
      { AfxTryCleanup(); };
};

// Exception global state - never access directly
struct CLASS_DECL_ANDROID __EXCEPTION_CONTEXT
{
   __EXCEPTION_LINK* m_pLinkTop;

   // Note: most of the exception context is now in the __EXCEPTION_LINK
};

#ifndef _PNH_DEFINED
typedef int (__cdecl * _PNH)( size_t );
#define _PNH_DEFINED
#endif

_PNH CLASS_DECL_ANDROID AfxGetNewHandler();
_PNH CLASS_DECL_ANDROID AfxSetNewHandler(_PNH pfnNewHandler);
CLASS_DECL_ca int __CDECL AfxNewHandler(size_t nSize);

void CLASS_DECL_ANDROID AfxAbort();


// helpers for registering your own WNDCLASSes
CLASS_DECL_ANDROID const char * AfxRegisterWndClass(UINT nClassStyle,
   HCURSOR hCursor = 0, HBRUSH hbrBackground = 0, HICON hIcon = 0);

// xxx CLASS_DECL_lnx bool __register_class(WNDCLASS* lpWndClass);

// helper to initialize rich edit 1.0 control
CLASS_DECL_ANDROID BOOL AfxInitRichEdit();
// helper to initialize rich edit 2.0 control
CLASS_DECL_ANDROID BOOL AfxInitRichEdit2();

CLASS_DECL_ANDROID LRESULT CALLBACK AfxWndProc(oswindow hWnd, UINT nMsg, WPARAM wParam, LPARAM lParam);
// xxx CLASS_DECL_lnx WNDPROC __get_window_procedure();
// xxx #define __window_procedure (*__get_window_procedure())

typedef void (__MSG_CALL ::ca2::window::*__PMSGW)(void);
   // like '__PMSG' but for ::ca2::window derived classes only

typedef void (__MSG_CALL ::ca2::thread::*__PMSGT)(void);
   // like '__PMSG' but for thread-derived classes only




CLASS_DECL_ANDROID LONG AfxDelRegTreeHelper(HKEY hParentKey, const string & strKeyName);


// Advanced initialization: for overriding default diagnostics
CLASS_DECL_ANDROID BOOL AfxDiagnosticInit(void);


CLASS_DECL_ANDROID ::android::thread * AfxGetThread();
CLASS_DECL_ANDROID void AfxSetThread(::ca2::thread * pthread);
CLASS_DECL_ANDROID MSG* AfxGetCurrentMessage();

CLASS_DECL_ANDROID void AfxEndThread(::ca2::application * papp, UINT nExitCode, BOOL bDelete = TRUE);

CLASS_DECL_ANDROID void AfxInitThread();
CLASS_DECL_ANDROID void AfxTermThread(::ca2::application * papp, HINSTANCE hInstTerm = NULL);

/////////////////////////////////////////////////////////////////////////////
// Global functions for access to the one and only application

#define afxCurrentWinApp    AfxGetModuleState()->m_pCurrentWinApp
#define afxCurrentInstanceHandle    AfxGetModuleState()->m_hCurrentInstanceHandle
#define afxCurrentResourceHandle    AfxGetModuleState()->m_hCurrentResourceHandle
#define afxCurrentAppName   AfxGetModuleState()->m_lpszCurrentAppName
#define afxContextIsDLL     AfxGetModuleState()->m_bDLL
#define afxRegisteredClasses    AfxGetModuleState()->m_fRegisteredClasses
#define afxAmbientActCtx    AfxGetModuleState()->m_bSetAmbientActCtx

#ifndef _AFX_NO_OCC_SUPPORT
#define afxOccManager   AfxGetModuleState()->m_pOccManager
#endif

//Fusion: Access macros for WinSxS dynamic wrappers.
#ifndef _AFX_NO_AFXCMN_SUPPORT
#define _AFX_COMCTL32_ISOLATION_WRAPPER_INDEX 0
#define afxComCtlWrapper static_cast<CComCtlWrapper*>(AfxGetModuleState()->m_pDllIsolationWrappers[_AFX_COMCTL32_ISOLATION_WRAPPER_INDEX])
#endif

#define _AFX_COMMDLG_ISOLATION_WRAPPER_INDEX 1
#define afxCommDlgWrapper static_cast<CCommDlgWrapper*>(AfxGetModuleState()->m_pDllIsolationWrappers[_AFX_COMMDLG_ISOLATION_WRAPPER_INDEX])

// Advanced initialization: for overriding default WinMain
//CLASS_DECL_ANDROID BOOL AfxWinInit(__in HINSTANCE hInstance, __in HINSTANCE hPrevInstance,
  // __in_z LPTSTR lpCmdLine, __in int nCmdShow);
CLASS_DECL_ANDROID void AfxWinTerm();

CLASS_DECL_ANDROID ::ca2::application* AfxGetApp();
CLASS_DECL_ANDROID ::user::interaction* AfxGetMainWnd();
//CLASS_DECL_ANDROID HINSTANCE CLASS_DECL_ANDROID System.m_hInstance;
CLASS_DECL_ANDROID HINSTANCE AfxGetResourceHandle();
CLASS_DECL_ANDROID void AfxSetResourceHandle(HINSTANCE hInstResource);
CLASS_DECL_ANDROID const char * AfxGetAppName();

CLASS_DECL_ANDROID HINSTANCE AfxGetResourceHandle();
CLASS_DECL_ANDROID HINSTANCE AfxFindStringResourceHandle(UINT nID);

CLASS_DECL_ANDROID void AfxDeleteObject(HGDIOBJ* pObject);

void CLASS_DECL_ANDROID AfxGlobalFree(HGLOBAL hGlobal);
