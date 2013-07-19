#include "framework.h"

namespace android
{

   pen::pen(::ca2::application * papp) :
      ca2(papp)
   {
   }
   pen::~pen()
   {
   }
   pen::operator HPEN() const
   {
      return (HPEN)(this == NULL ? NULL : get_handle());
   }
   pen* PASCAL pen::from_handle(::ca2::application * papp, HPEN hPen)
   {
      return dynamic_cast < pen* > (::android::graphics_object::from_handle(papp, hPen));
   }
   BOOL pen::CreatePen(int nPenStyle, int nWidth, COLORREF crColor)
   { return Attach(::CreatePen(nPenStyle, nWidth, crColor)); }
   BOOL pen::CreatePenIndirect(LPLOGPEN lpLogPen)
   { return Attach(::CreatePenIndirect(lpLogPen)); }
   BOOL pen::CreatePen(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
      int nStyleCount, const DWORD* lpStyle)
   { return Attach(::ExtCreatePen(nPenStyle, nWidth, pLogBrush, nStyleCount,
   lpStyle)); }
   int pen::GetExtLogPen(EXTLOGPEN* pLogPen)
   { ASSERT(get_handle() != NULL);
   return ::GetObject(get_handle(), sizeof(EXTLOGPEN), pLogPen); }

   int pen::GetLogPen(LOGPEN* pLogPen)
   {
      if(get_handle() == NULL)
         return 0;
      return ::GetObject(get_handle(), sizeof(LOGPEN), pLogPen);
   }


   void pen::construct(int nPenStyle, int nWidth, COLORREF crColor)
   {
      if (!Attach(::CreatePen(nPenStyle, nWidth, crColor)))
         AfxThrowResourceException();
   }

   void pen::construct(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
      int nStyleCount, const DWORD* lpStyle)
   {
      if (!Attach(::ExtCreatePen(nPenStyle, nWidth, pLogBrush, nStyleCount,
         lpStyle)))
         AfxThrowResourceException();
   }

   /////////////////////////////////////////////////////////////////////////////

#ifdef DEBUG
   void pen::dump(dump_context & dumpcontext) const
   {
      ::ca2::graphics_object::dump(dumpcontext);

      if (get_handle() == NULL)
         return;

      if (!afxData.bWin95 && ::GetObjectType(get_handle()) != OBJ_PEN)
      {
         // not a valid object
         dumpcontext << "has ILLEGAL HPEN!";
         return;
      }

      LOGPEN lp;
      VERIFY(GetObject(sizeof(lp), &lp));
      dumpcontext << "lgpn.lopnStyle = " << lp.lopnStyle;
      dumpcontext << "\nlgpn.lopnWidth.x (width) = " << lp.lopnWidth.x;
      dumpcontext << "\nlgpn.lopnColor = " << (void *)(dword_ptr)lp.lopnColor;

      dumpcontext << "\n";
   }
#endif




      // IMPLEMENT_DYNAMIC(resource_exception, base_exception)
      //resource_exception _simpleResourceException(FALSE, __IDS_RESOURCE_EXCEPTION);

      // IMPLEMENT_DYNAMIC(user_exception, base_exception)
      //user_exception _simpleUserException(FALSE, __IDS_USER_EXCEPTION);

      // IMPLEMENT_DYNCREATE(::ca2::graphics_sp, ::radix::object)
      // IMPLEMENT_DYNAMIC(CClientDC, ::ca2::graphics_sp)
      // IMPLEMENT_DYNAMIC(CWindowDC, ::ca2::graphics_sp)
      // IMPLEMENT_DYNAMIC(CPaintDC, ::ca2::graphics_sp)
      // IMPLEMENT_DYNCREATE(::ca2::graphics_object, ::radix::object)

      // IMPLEMENT_DYNAMIC(pen, ::ca2::graphics_object)
      // IMPLEMENT_DYNAMIC(::ca2::brush, ::ca2::graphics_object)
      // IMPLEMENT_DYNAMIC(::ca2::font, ::ca2::graphics_object)
      // IMPLEMENT_DYNAMIC(::ca2::bitmap, ::ca2::graphics_object)
      // IMPLEMENT_DYNAMIC(::ca2::palette, ::ca2::graphics_object)
      // IMPLEMENT_DYNAMIC(::ca2::rgn, ::ca2::graphics_object)

      /////////////////////////////////////////////////////////////////////////////
      // Standard exception processing



} // namespace android
