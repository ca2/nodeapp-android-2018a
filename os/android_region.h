#pragma once

namespace android
{

   class rgn :
      virtual public ::android::graphics_object,
      virtual public ::ca2::rgn
   {
   public:
      static rgn * PASCAL from_handle(::ca2::application * papp, HRGN hRgn);
      operator HRGN() const;

      rgn(::ca2::application * papp);
      virtual ~rgn();

      BOOL CreateRectRgn(int x1, int y1, int x2, int y2);
      BOOL CreateRectRgnIndirect(LPCRECT lpRect);
      BOOL CreateEllipticRgn(int x1, int y1, int x2, int y2);
      BOOL CreateEllipticRgnIndirect(LPCRECT lpRect);
      BOOL CreatePolygonRgn(LPPOINT lpPoints, int nCount, int nMode);
      BOOL CreatePolyPolygonRgn(LPPOINT lpPoints, LPINT lpPolyCounts,
            int nCount, int nPolyFillMode);
      BOOL CreateRoundRectRgn(int x1, int y1, int x2, int y2, int x3, int y3);
      BOOL CreateFromPath(::ca2::graphics * pgraphics);
      BOOL CreateFromData(const XFORM* lpXForm, int nCount,
         const RGNDATA* pRgnData);

   // Operations
      void SetRectRgn(int x1, int y1, int x2, int y2);
      void SetRectRgn(LPCRECT lpRect);
      int CombineRgn(const ::ca2::rgn* pRgn1, const ::ca2::rgn* pRgn2, int nCombineMode);
      int CopyRgn(const ::ca2::rgn* pRgnSrc);
      BOOL EqualRgn(const ::ca2::rgn* pRgn) const;
      int OffsetRgn(int x, int y);
      int OffsetRgn(POINT point);
      int GetRgnBox(LPRECT lpRect) const;
      BOOL PtInRegion(int x, int y) const;
      BOOL PtInRegion(POINT point) const;
      BOOL RectInRegion(LPCRECT lpRect) const;
      int GetRegionData(LPRGNDATA lpRgnData, int nCount) const;

   };

} // namespace android