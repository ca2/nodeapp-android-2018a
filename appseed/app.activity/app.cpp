#include "activity.h"


#define  LOG_TAG    "app.activity (app.cpp)"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


PFN_android_fill_plasma g_android_fill_plasma = NULL;

PFN_mouse l_button_down = NULL;

PFN_mouse mouse_move = NULL;

PFN_mouse l_button_up = NULL;

android_init_data g_initdata;

PFN_key key_down = NULL;

PFN_key key_up = NULL;



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



void start(int iScreenWidth, int iScreenHeight, const char * pszCommandLine, const char * pszCacheDir)
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

      l_button_down = (PFN_mouse)dlsym(handle, "android_l_button_down");

      if (!l_button_down)
      {

         LOGE("Fatal: undefined symbol \"android_l_button_down\" from libbase.so");

         exit(1);

      }

      mouse_move = (PFN_mouse)dlsym(handle, "android_mouse_move");

      if (!mouse_move)
      {

         LOGE("Fatal: undefined symbol \"android_l_button_down\" from libbase.so");

         exit(1);

      }

      l_button_up = (PFN_mouse)dlsym(handle, "android_l_button_up");

      if (!l_button_up)
      {

         LOGE("Fatal: undefined symbol \"android_l_button_up\" from libbase.so");

         exit(1);

      }

      key_down = (PFN_key)dlsym(handle, "android_key_down");

      if (!key_down)
      {

         LOGE("Fatal: undefined symbol \"android_key_down\" from libbase.so");

         exit(1);

      }

      key_up = (PFN_key)dlsym(handle, "android_key_up");

      if (!key_up)
      {

         LOGE("Fatal: undefined symbol \"android_key_up\" from libbase.so");

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

   android_init_data & initdata = g_initdata;

   initdata.m_iScreenWidth    = iScreenWidth;

   initdata.m_iScreenHeight   = iScreenHeight;

   initdata.m_pszCommandLine  = pszCommandLine;

   initdata.m_pszCacheDir     = pszCacheDir;

   initdata.m_bShowKeyboard   = false;

   initdata.m_pszOpenUrl      = NULL;

	main(&initdata);

}



//extern "C"
//jint JNI_OnLoad(JavaVM* vm, void* reserved)
//{
//	JNIEnv* env;
//	if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
//		return -1;
//	}
//
//	// Get jclass with env->FindClass.
//	// Register methods with env->RegisterNatives.
//
//	return JNI_VERSION_1_6;
//
//}

int g_iScreenW = 0;
int g_iScreenH = 0;
const char * g_pszCommandLine = NULL;
const char * g_pszCacheDir = NULL;

const char * jstrdup(JNIEnv * env, jstring jstr)
{
   
   const char * nativeString = env->GetStringUTFChars(jstr, NULL);

   const char * psz = strdup(nativeString);

   env->ReleaseStringUTFChars(jstr, nativeString);

   return psz;

}

extern "C"
JNIEXPORT void JNICALL Java_com_ca2_app_configureApp(JNIEnv * env, jobject  obj, jstring strCommandLine, jstring strCacheDir, jint iScreenW, jint iScreenH)
{

   g_pszCommandLine = jstrdup(env, strCommandLine);

   g_pszCacheDir = jstrdup(env, strCacheDir);

   g_iScreenW = iScreenW;

   g_iScreenH = iScreenH;

}
