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

#define  LOG_TAG    "app.activity (app.cpp)"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


void * load_lib(const char * l)
{

   void * handle = dlopen(l, RTLD_NOW | RTLD_GLOBAL);
	
   if (handle)
	{
	
      LOGI("dlopen(\"%s\"){3}: Library Opened Successfully : %s", l, l);
	
   }
	else
   {

      LOGE("dlopen(\"%s\"): %s", l, strerror(errno));

	}

   return handle;

}


typedef void FN_android_fill_plasma(AndroidBitmapInfo * info, void * pixels, double  t);

typedef FN_android_fill_plasma * PFN_android_fill_plasma;

PFN_android_fill_plasma g_android_fill_plasma = NULL;


void start(int iScreenWidth, int iScreenHeight, const char * pszCommandLine)
{
	
	LOGI("start(%d, %d)", iScreenWidth, iScreenHeight);

   PFN_native_activity_android_start main = NULL;

   {

      void * handle = load_lib("libbase.so");

      if (!handle)
      {

         LOGE("Fatal: Unable to reload shared library libbase.so. It should be already be loaded thorugh Java System.loadLibrary call (explicitly or implicitly)");

         exit(1);

      }

      g_android_fill_plasma = (PFN_android_fill_plasma)dlsym(handle, "android_fill_plasma");

      if (!g_android_fill_plasma)
      {

         LOGE("Fatal: undefined symbol \"android_fill_plasma\" from libbase.so");

         exit(1);

      }

   }

   {

      void * handle = load_lib("liblauncher.so");

      if (!handle)
      {

         LOGE("Fatal: Unable to reload shared library liblauncher.so. It should be already be loaded thorugh Java System.loadLibrary call (explicitly or implicitly)");

         exit(1);

      }


      main = (PFN_native_activity_android_start)dlsym(handle, "native_activity_android_start");

      if (!main)
      {

         LOGE("Fatal: undefined symbol \"native_activity_android_start\" from liblauncher.so");

         exit(1);

      }

   }

   android_init_data initdata;

   initdata.m_iScreenWidth    = iScreenWidth;

   initdata.m_iScreenHeight   = iScreenHeight;

   initdata.m_pszCommandLine  = pszCommandLine;

	main(&initdata);

}



extern "C"
jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
	JNIEnv* env;
	if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
		return -1;
	}

	// Get jclass with env->FindClass.
	// Register methods with env->RegisterNatives.

	return JNI_VERSION_1_6;

}

int g_iScreenW = 0;
int g_iScreenH = 0;
const char * g_pszCommandLine = NULL;


extern "C"
JNIEXPORT void JNICALL Java_com_app_app_configureApp(JNIEnv * env, jobject  obj, jstring strCommandLine, jint iScreenW, jint iScreenH)
{

   const char * nativeString = env->GetStringUTFChars(strCommandLine, NULL);

   g_pszCommandLine = strdup(nativeString);

   env->ReleaseStringUTFChars(strCommandLine, nativeString);

   g_iScreenW = iScreenW;

   g_iScreenH = iScreenH;

}
