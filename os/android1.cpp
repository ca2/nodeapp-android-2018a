#include "framework.h"
#include "android1.h"


namespace android
{

   int32_t function()
   {
      return 0;
   }


   DWORD GetTempPath(string & str)
   {
      return ::GetTempPathW(MAX_PATH * 8, wstringtou(str, MAX_PATH * 8));
   }

} // namespace android


