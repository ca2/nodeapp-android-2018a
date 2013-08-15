#pragma once

#define AfxDeferRegisterClass(fClass) AfxEndDeferRegisterClass(fClass)

CLASS_DECL_ANDROID BOOL AfxEndDeferRegisterClass(LONG fToRegister, const char ** ppszClass);


// Temporary ::collection::map management (locks temp ::collection::map on current thread)
//CLASS_DECL_ANDROID void AfxLockTempMaps(::ca2::application * papp);
//CLASS_DECL_ANDROID BOOL AfxUnlockTempMaps(::ca2::application * papp, BOOL bDeleteTemps = TRUE);



// from wincore.cpp
extern CLASS_DECL_ANDROID const char _afxWnd[];           // simple child windows/controls
extern CLASS_DECL_ANDROID const char _afxWndControlBar[]; // controls with gray backgrounds
extern CLASS_DECL_ANDROID const char _afxWndMDIFrame[];
extern CLASS_DECL_ANDROID const char _afxWndFrameOrView[];
extern CLASS_DECL_ANDROID const char _afxWndOleControl[];


/////////////////////////////////////////////////////////////////////////////
// Special helpers

CLASS_DECL_ANDROID void AfxCancelModes(oswindow hWndRcvr);
CLASS_DECL_ANDROID BOOL AfxHelpEnabled();  // determine if ID_HELP handler exists
CLASS_DECL_ANDROID BOOL AfxCustomLogFont(UINT nIDS, LOGFONT* pLogFont);
CLASS_DECL_ANDROID BOOL AfxGetPropSheetFont(string & strFace, WORD& wSize, BOOL bWizard);

CLASS_DECL_ANDROID BOOL _AfxIsComboBoxControl(oswindow hWnd, UINT nStyle);
CLASS_DECL_ANDROID BOOL _AfxCheckCenterDialog(const char * lpszResource);
CLASS_DECL_ANDROID BOOL _AfxCompareClassName(oswindow hWnd, const char * lpszClassName);
CLASS_DECL_ANDROID oswindow _AfxChildWindowFromPoint(oswindow, POINT);

// for determining version of COMCTL32.DLL
#define VERSION_WIN4    MAKELONG(0, 4)
#define VERSION_IE3             MAKELONG(70, 4)
#define VERSION_IE4             MAKELONG(71, 4)
#define VERSION_IE401   MAKELONG(72, 4)
#define VERSION_6      MAKELONG(0, 6)
extern int _afxComCtlVersion;
DWORD _AfxGetComCtlVersion();
