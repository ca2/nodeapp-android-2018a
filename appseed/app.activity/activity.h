#pragma once

//#include <android/native_activity.h>
#include <android/log.h>
#include <dlfcn.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <jni.h>
#include <time.h>
#include <android/log.h>
#include <android/bitmap.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "aura/aura/os/android/android_init_data.h"




typedef void FN_android_fill_plasma(AndroidBitmapInfo * info, void * pixels, double  t);

typedef FN_android_fill_plasma * PFN_android_fill_plasma;

extern PFN_android_fill_plasma g_android_fill_plasma;




typedef void FN_mouse(float x, float y);

typedef FN_mouse * PFN_mouse;

extern PFN_mouse l_button_down;

extern PFN_mouse mouse_move;

extern PFN_mouse l_button_up;




typedef void FN_key(int keyCode);

typedef FN_key * PFN_key;

extern PFN_key key_down;

extern PFN_key key_up;




extern int g_iScreenW;

extern int g_iScreenH;

extern const char * g_pszCommandLine;

extern const char * g_pszCacheDir;

extern android_init_data g_initdata;



