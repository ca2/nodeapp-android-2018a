#include "framework.h"


namespace android
{


   copydesk::copydesk(sp(::ca2::application) papp) :
      ca2(papp),
      ::ca2::copydesk(papp)
   {

   }


   copydesk::~copydesk()
   {

   }


   int32_t copydesk::get_file_count()
   {

      return 0;

   }


   void copydesk::get_filea(stringa & stra)
   {
      
      int32_t iCount = get_file_count();
      
      if(iCount <= 0)
         return;

      throw todo(get_app());

   }


   void copydesk::set_filea(stringa & stra)
   {

      strsize iLen = 0;

      for(int32_t i = 0; i < stra.get_size(); i++)
      {
         iLen += ::ca2::international::utf8_to_unicode_count(stra[i]) + 1;
      }

      throw todo(get_app());

   }


   bool copydesk::initialize()
   {

      if(!::ca2::copydesk::initialize())
         return false;


      return true;

   }


   bool copydesk::finalize()
   {

      bool bOk;

      bOk = ::ca2::copydesk::finalize();

      return bOk;

   }

   void copydesk::set_plain_text(const char * psz)
   {

      string str;

      str = ::ca2::international::utf8_to_unicode(psz);


   }


   string copydesk::get_plain_text()
   {

   }


   bool copydesk::desk_to_dib(::draw2d::dib * pdib)
   {

   }


} // namespace android




