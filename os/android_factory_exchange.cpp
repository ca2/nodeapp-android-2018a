#include "framework.h"

namespace android
{

   factory_exchange::factory_exchange(::ca2::application * papp) :
      ca2(papp)
   {
      System.factory().cloneable_large < WinStdioFile         >  (typeid(::ex1::text_file        ));
      System.factory().cloneable_large < WinFile              >  (typeid(::ex1::file             ));
      System.factory().cloneable_large < WinFileSet           >  (typeid(::ex2::file_set         ));
      System.factory().cloneable < WinFileSystem        >  (typeid(::ex1::file_system      ), 1);
      System.factory().cloneable_small < WinFileException     >  (typeid(::ex1::file_exception   ));
      System.factory().cloneable < WinResource          >  (typeid(::ex1::resource         ), 1);
      System.factory().cloneable < application          >  (typeid(::ex2::application      ), 1);
      System.factory().cloneable < dir                  >  (typeid(::ca2::dir::system            ), 1);
      System.factory().cloneable_small < folder_watch         >  (typeid(::ex2::folder_watch     ));
      System.factory().cloneable_large < dib                  >  (typeid(::ca2::dib               ));
      System.factory().cloneable_large < graphics             >  (typeid(::ca2::graphics          ));
      System.factory().cloneable_large < bitmap               >  (typeid(::ca2::bitmap            ));
      System.factory().cloneable_large < pen                  >  (typeid(::ca2::pen               ));
      System.factory().cloneable_large < brush                >  (typeid(::ca2::brush             ));
      System.factory().cloneable_large < palette              >  (typeid(::ca2::palette           ));
      System.factory().cloneable_large < rgn                  >  (typeid(::ca2::rgn               ));
      System.factory().cloneable_large < font                 >  (typeid(::ca2::font              ));
      System.factory().creatable < window_draw          >  (typeid(::ca2::window_draw       ), 1);
      System.factory().creatable_large < thread               >  (typeid(::ca2::thread            ));
      System.factory().creatable_large < window               >  (typeid(::ca2::window            ));
      System.factory().cloneable_small < draw_dib             >  (typeid(::ca2::draw_dib          ));
      System.factory().creatable < osi                  >  (typeid(::ca2::osi               ), 1);
      System.factory().creatable < port_forward         >  (typeid(::ca4::port_forward            ), 1);
      ::android::dib::s_initialize();
   }

   factory_exchange::~factory_exchange()
   {
   }

} // namespace android



void ca2_factory_exchange(::ca2::application * papp)
{
   android::factory_exchange factoryexchange(papp);
}