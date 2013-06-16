#pragma once

namespace win
{

   class CLASS_DECL_ANDROID factory_exchange :
      virtual public ::radix::object
   {
   public:
      factory_exchange(::ca2::application * papp);
      virtual ~factory_exchange();
   };

} // namespace win