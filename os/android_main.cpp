#include "framework.h"


CLASS_DECL_ca int32_t ca2_main();

//CLASS_DECL_ca extern fixed_alloc_array * g_pfixedallocaWstring;

//CLASS_DECL_ca fixed_alloc_array * new_wstring_manager();

void CLASS_DECL_ANDROID __cdecl _ca2_purecall()
{
    throw simple_exception(::ca2::get_thread_app());
}


void __cdecl _null_se_translator(uint32_t uiCode, EXCEPTION_POINTERS * ppointers);




//sp(::ca2::application)     win_application_create(sp(::ca2::application) pappSystem, const char * pszId);
//sp(::ca2::application)     win_instantiate_application(sp(::ca2::application) pappSystem, const char * pszId);
//int32_t                     win_application_procedure(sp(::ca2::application) pappSystem)
//UINT c_cdecl          win_application_thread_proc(LPVOID);
/////////////////////////////////////////////////////////////////////////////
// Standard WinMain implementation
//  can be replaced as long as '::ca2::WinInit' is called first

extern char gen_InitAppState;

CLASS_DECL_ANDROID bool __initialize(bool bDLL, DWORD dwVersion);

int32_t CLASS_DECL_ANDROID __android_main(int32_t argc, char * argv[])
{

   //if(!XInitThreads())
     // return -1;


   gen_InitAppState = (char)(__initialize(FALSE, 1));

//   UNREFERENCED_PARAMETER(lpCmdLine);

   c_xstart();



   ///XSetErrorHandler(xlib_error_handler);


//   ::CoInitialize(NULL);
//{
//int * pi = NULL;
//*pi = 0;
//}

//throw todo(::ca2::get_thread_app());

   if(!main_initialize())
      return -1;


//   _set_purecall_handler(_ca2_purecall);

   ::plane::system * psystem = new ::plane::system();

    //psystem->::exception::translator::attach();

           //sigset_t set;
           //sigemptyset(&set);
           //sigaddset(&set, SIGSEGV);
           //sigprocmask(SIG_BLOCK, &set, ::null());

//{
//int * pi = NULL;
//*pi = 0;
//}


//   ASSERT(hPrevInstance == NULL);

   int32_t nReturnCode = 0;


   ::android::main_init_data * pinitmaindata  = new ::android::main_init_data;


   pinitmaindata->m_hInstance             = NULL;
   pinitmaindata->m_hPrevInstance         = NULL;
   if(argc > 0)
   {
      pinitmaindata->m_vssCommandLine     = argv[0];
   }
   bool bColon = false;
   for(int32_t i = 1; i < argc; i++)
   {
      if(bColon || (bColon = (strcmp(argv[i], ":") == 0)))
      {
         pinitmaindata->m_vssCommandLine     += " ";
         pinitmaindata->m_vssCommandLine     += argv[i];

      }
      else
      {
         pinitmaindata->m_vssCommandLine     += " \"";
         pinitmaindata->m_vssCommandLine     += argv[i];
         pinitmaindata->m_vssCommandLine     += "\"";
      }
   }
   pinitmaindata->m_nCmdShow              = SW_SHOW;


   psystem->init_main_data(pinitmaindata);

   //MessageBox(NULL, "box1", "box1", MB_ICONINFORMATION);

   nReturnCode = psystem->main();

   try
   {
      main_finalize();
   }
   catch(...)
   {
   }

   try
   {
      __android_term();
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

   psystem = NULL;


   try
   {
//      delete __get_module_state()->m_pmapHWND;
   }
   catch(...)
   {
   }
/*   try
   {
      delete __get_module_state()->m_pmapHDC;
   }
   catch(...)
   {
   }*/
/*   try
   {
      delete __get_module_state()->m_pmapHGDIOBJ;
   }
   catch(...)
   {
   }*/
//      delete __get_module_state()->m_pmapHMENU;

   try
   {
      __get_module_state()->m_pmapHWND     = NULL;
   }
   catch(...)
   {
   }
/*   try
   {
      __get_module_state()->m_pmapHDC      = NULL;
   }
   catch(...)
   {
   }*/
/*   try
   {
      __get_module_state()->m_pmapHGDIOBJ  = NULL;
   }
   catch(...)
   {
   }*/


   set_heap_mutex(NULL);

   return nReturnCode;


}


int32_t CLASS_DECL_ANDROID ca2_main(HINSTANCE hInstance, HINSTANCE hPrevInstance, const char * lpCmdLine, int32_t nCmdShow)
{
   try
   {

//      _set_purecall_handler(_ca2_purecall);

      ::plane::system * psystem = new ::plane::system();


      //Sleep(30 * 1000);


      ASSERT(hPrevInstance == NULL);

      int32_t nReturnCode = 0;

      ::android::main_init_data * pinitmaindata  = new ::android::main_init_data;

      pinitmaindata->m_hInstance             = hInstance;
      pinitmaindata->m_hPrevInstance         = hPrevInstance;
      pinitmaindata->m_vssCommandLine        = lpCmdLine;
      pinitmaindata->m_nCmdShow              = nCmdShow;


      psystem->init_main_data(pinitmaindata);


      nReturnCode = psystem->main();


      __android_term();


      try
      {
         delete psystem;
      }
      catch(...)
      {
      }

      psystem = NULL;

      try
      {
//         delete __get_module_state()->m_pmapHWND;
      }
      catch(...)
      {
      }
/*      try
      {
         delete __get_module_state()->m_pmapHDC;
      }
      catch(...)
      {
      }*/
/*      try
      {
         delete __get_module_state()->m_pmapHGDIOBJ;
      }
      catch(...)
      {
      }*/
//      delete __get_module_state()->m_pmapHMENU;
      try
      {
         __get_module_state()->m_pmapHWND     = NULL;
      }
      catch(...)
      {
      }
/*      try
      {
         __get_module_state()->m_pmapHDC      = NULL;
      }
      catch(...)
      {
      }
      try
      {
         __get_module_state()->m_pmapHGDIOBJ  = NULL;
      }
      catch(...)
      {
      }*/

      set_heap_mutex(NULL);


      return nReturnCode;
   }
   catch(...)
   {
   }
   return -1;
}



void __cdecl _null_se_translator(uint32_t uiCode, EXCEPTION_POINTERS * ppointers)
{
   UNREFERENCED_PARAMETER(uiCode);
   UNREFERENCED_PARAMETER(ppointers);
}
