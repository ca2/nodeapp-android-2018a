#include <android/native_activity.h>
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

#define  LOG_TAG    "libapp"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


//#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "Porkholt", __VA_ARGS__))
//#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, "Porkholt", __VA_ARGS__))
//typedef struct {
//	const char *dli_fname;  /* Pathname of shared object that
//							contains address */
//	void       *dli_fbase;  /* Address at which shared object
//							is loaded */
//	const char *dli_sname;  /* Name of nearest symbol with address
//							lower than addr */
//	void       *dli_saddr;  /* Exact address of symbol named
//							in dli_sname */
//} Dl_info;
Dl_info dl_info;

__attribute__((constructor))
void on_load(void) {
	dladdr((void *)on_load, &dl_info);
}

char szDir[1024];




void * load_lib(const char * l)
{
	//char szFile[2048];

	//
	//strcpy(szFile, "/lib/x86/");
	//strcat(szFile, l);
	//void * handle = dlopen(szFile, RTLD_LAZY);
	//if (handle)
	//{
	//	LOGI("dlopen(\"%s\"): Library Opened Successfully : %s", l, szFile);
	//}
	//else
	//{
	//	strcpy(szFile, szDir);
	//	strcat(szFile, "/lib/x86/");
	//	strcat(szFile, l);
	//	handle = dlopen(szFile, RTLD_LAZY);
	//	if (handle)
	//	{
	//		LOGI("dlopen(\"%s\"){2}: Library Opened Successfully : %s", l, szFile);
	//	}
	//	else
	//	{
			void * handle = dlopen(l, RTLD_NOW | RTLD_GLOBAL);
			if (handle)
			{
				LOGI("dlopen(\"%s\"){3}: Library Opened Successfully : %s", l, l);
			}
			else
			{
				LOGE("dlopen(\"%s\"): %s", l, strerror(errno));
			}
	//	}
	//}
	return handle;
}


extern "C"
JNIEXPORT void JNICALL Java_com_app_view_start(JNIEnv * env, jobject  obj)
{
	
	LOGI("Java_com_app_view_start");
	
	//void * handle = load_lib("/data/app-lib/com.app/liblauncher.so");

	/*PFN_ANativeActivity_onCreate main = (PFN_ANativeActivity_onCreate)dlsym(handle, "android_start_activity");

	if (!main)
	{

		LOGE("undefined symbol ANativeActivity_onCreate");

		exit(1);

	}

	android_start_activity();*/

}


