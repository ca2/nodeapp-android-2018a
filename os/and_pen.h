#pragma once

namespace win
{

   /////////////////////////////////////////////////////////////////////////////
   // ::ca2::graphics_object subclasses (drawing tools)

   class CLASS_DECL_ANDROID pen :
      virtual public ::win::graphics_object,
      virtual public ::ca2::pen
   {
   public:
      static pen* PASCAL from_handle(::ca2::application * papp, HPEN hPen);

      pen(::ca2::application * papp);
      virtual void construct(int nPenStyle, int nWidth, COLORREF crColor);
      virtual void construct(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
         int nStyleCount = 0, const DWORD* lpStyle = NULL);
      BOOL CreatePen(int nPenStyle, int nWidth, COLORREF crColor);
      BOOL CreatePen(int nPenStyle, int nWidth, const LOGBRUSH* pLogBrush,
         int nStyleCount = 0, const DWORD* lpStyle = NULL);
      BOOL CreatePenIndirect(LPLOGPEN lpLogPen);

   // Attributes
      operator HPEN() const;
      int GetLogPen(LOGPEN* pLogPen);
      int GetExtLogPen(EXTLOGPEN* pLogPen);

   // Implementation
   public:
      virtual ~pen();
   #ifdef DEBUG
      virtual void dump(dump_context & dumpcontext) const;
   #endif
   };

} // namespace win
