#pragma once




// define portable types for 32-bit / 64-bit OS
typedef int32_t BOOL;
typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int32_t LONG;


#undef FAR
#undef  NEAR
#define FAR
#define NEAR
#ifndef CONST
#define CONST               const
#endif

struct hthread;




struct oswindow_data;


typedef struct oswindow_data * oswindow;




#define HWND_MESSAGE ((::oswindow_data *) (int_ptr) 1)

CLASS_DECL_c int_bool IsChild(oswindow windowParent, oswindow windowCandidateChildOrDescendant);
CLASS_DECL_c oswindow GetParent(oswindow window);
CLASS_DECL_c oswindow SetParent(oswindow window, oswindow windowNewParent);
CLASS_DECL_c int_bool ShowWindow(oswindow window, int32_t nCmdShow);
CLASS_DECL_c LONG GetWindowLongA(oswindow window, int32_t nIndex);
CLASS_DECL_c LONG SetWindowLongA(oswindow window, int32_t nIndex, LONG l);
CLASS_DECL_c int_bool ClientToScreen(oswindow window, LPPOINT lppoint);
CLASS_DECL_c int_bool ScreenToClient(oswindow window, LPPOINT lppoint);
CLASS_DECL_c int32_t IsIconic(oswindow window);
CLASS_DECL_c int32_t IsWindowVisible(oswindow window);

#define GetWindowLong GetWindowLongA
#define SetWindowLong SetWindowLongA



CLASS_DECL_c int_bool IsWindow(oswindow oswindow);





