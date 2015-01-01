#include "app-core/appseed/hellomultiverse/hellomultiverse.h"
#include "aura/aura/node/android/android.h"

// thank you (casey) - non explicit global initialization is zero initialization
::core::system * g_psystem;

int32_t core_system_start();

int32_t android_start()
{
   
   if(!defer_core_init())
      return -1;

   int iRet = core_system_start();

   return iRet;

}


int32_t core_system_start()
{

   ::core::system * psystem = new ::core::system();

   g_psystem = psystem;

   psystem->m_durationRunLock = millis(1);

   //psystem->::exception::translator::attach();

   int32_t nReturnCode = 0;

   ::android::main_init_data * pinitmaindata  = new ::android::main_init_data;

   pinitmaindata->m_hInstance             = NULL;

   pinitmaindata->m_hPrevInstance         = NULL;

   //if(argc > 0)
   {

     // pinitmaindata->m_vssCommandLine     = argv[0];
      pinitmaindata->m_vssCommandLine     = "app : app=app-core/hellomultiverse";

   }

   pinitmaindata->m_nCmdShow              = SW_SHOW;

   psystem->init_main_data(pinitmaindata);

   bool bOk = true;

   try
   {

      if(psystem->pre_run())
      {

         bOk = true;

      }

   }
   catch(...)
   {

   }

   try
   {

      if(!bOk)
      {

         if(psystem->m_iReturnCode == 0)
         {

            return -1;

         }

         return psystem->m_iReturnCode;

      }


   }
   catch(...)
   {

      return -1;

   }

   __start_core_system_main(psystem);

}



void android_stop()
{

   ::core::system * psystem = g_psystem;

   if(psystem == NULL)
   {

      return;

   }


   try
   {

      psystem->m_signala.remove_all();

   }
   catch(...)
   {

   }


   try
   {

      psystem->m_pthreadimpl->m_signala.remove_all();

   }
   catch(...)
   {

   }

   try
   {

      delete psystem;

   }
   catch(...)
   {

   }

   g_psystem = NULL;

   defer_core_term();


}