/*
Module : IPENUM.H
Purpose: Interface for an ca2 API class wrapper for IP address enumeration
Created: PJN / 21-04-1998
History: None

Copyright (c) 1998 by PJ Naughter.


*/


namespace android
{


   class CLASS_DECL_ANDROID ip_enum :
      virtual public ::ca2::ip_enum
   {
   public:


      ip_enum(sp(base_application) papp);
      virtual ~ip_enum();


      virtual ::count enumerate(stringa & stra);


   };


} // namespace android




