#pragma once

namespace android
{

   class CLASS_DECL_ANDROID brush :
      virtual public ::android::graphics_object,
      virtual public ::ca2::brush
   {
   public:
      static brush* PASCAL from_handle(::ca2::application * papp, HBRUSH hBrush);

      // Constructors
      brush(::ca2::application * papp);
      virtual void construct(COLORREF crColor);                // CreateSolidBrush
      virtual void construct(int nIndex, COLORREF crColor);    // CreateHatchBrush
      virtual void construct(::ca2::bitmap * pbitmap);                // CreatePatternBrush

      virtual ~brush();

      BOOL CreateSolidBrush(COLORREF crColor);
      BOOL CreateHatchBrush(int nIndex, COLORREF crColor);
      BOOL CreateBrushIndirect(const LOGBRUSH* lpLogBrush);
      BOOL CreatePatternBrush(::ca2::bitmap* pBitmap);
      BOOL CreateDIBPatternBrush(HGLOBAL hPackedDIB, UINT nUsage);
      BOOL CreateDIBPatternBrush(const void * lpPackedDIB, UINT nUsage);
      BOOL CreateSysColorBrush(int nIndex);

      // Attributes
      operator HBRUSH() const;
      int GetLogBrush(LOGBRUSH* pLogBrush);

      // Implementation
   public:
#ifdef DEBUG
      virtual void dump(dump_context & dumpcontext) const;
#endif
   };


} // namespace android
