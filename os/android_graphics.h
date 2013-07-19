#pragma once

namespace android
{

   class CLASS_DECL_ANDROID graphics :
      virtual public ::ca2::graphics,
      virtual public hdc_handle
   {
      // // DECLARE_DYNCREATE(::ca2::graphics_sp)
   public:

      graphics();
      graphics(::ca2::application * papp);
      virtual ~graphics();

   // Attributes
   //   HDC get_os_data();          // The output DC (must be first data member <= no more true (What are the consequences?))
   //   HDC get_handle2();    // The Attribute DC
      operator HDC() const;
      HDC get_handle1() const; // Always returns the Output DC
      virtual void * get_os_data();
      ::ca2::window * GetWindow() const;

      static ::ca2::graphics * PASCAL from_handle(HDC hDC);
      static void PASCAL DeleteTempMap();
      BOOL Attach(HDC hDC);   // Attach/Detach affects only the Output DC
      HDC Detach();

      virtual void SetAttribDC(HDC hDC);  // Set the Attribute DC
      virtual void SetOutputDC(HDC hDC);  // Set the Output DC
      virtual void ReleaseAttribDC();     // Release the Attribute DC
      virtual void ReleaseOutputDC();     // Release the Output DC

      BOOL IsPrinting() const;            // TRUE if being used for printing

      ::ca2::pen* GetCurrentPen() const;
      ::ca2::brush* GetCurrentBrush() const;
      ::ca2::palette* GetCurrentPalette() const;
      ::ca2::font* GetCurrentFont() const;
      ::ca2::bitmap* GetCurrentBitmap() const;

      // for bidi and mirrored localization
      DWORD GetLayout() const;
      DWORD SetLayout(DWORD dwLayout);

   // Constructors
      BOOL CreateDC(const char * lpszDriverName, const char * lpszDeviceName,
         const char * lpszOutput, const void * lpInitData);
      BOOL CreateIC(const char * lpszDriverName, const char * lpszDeviceName,
         const char * lpszOutput, const void * lpInitData);
      BOOL CreateCompatibleDC(::ca2::graphics * pgraphics);

      BOOL DeleteDC();

   // Device-Context Functions
      virtual int SaveDC();
      virtual BOOL RestoreDC(int nSavedDC);
      int GetDeviceCaps(int nIndex) const;
      UINT SetBoundsRect(LPCRECT lpRectBounds, UINT flags);
      UINT GetBoundsRect(LPRECT lpRectBounds, UINT flags);
      BOOL ResetDC(const DEVMODE* lpDevMode);

   // Drawing-Tool Functions
      point GetBrushOrg() const;
      point SetBrushOrg(int x, int y);
      point SetBrushOrg(POINT point);
      int EnumObjects(int nObjectType,
            int (CALLBACK* lpfn)(LPVOID, LPARAM), LPARAM lpData);

   // Type-safe selection helpers
   public:
      virtual ::ca2::graphics_object* SelectStockObject(int nIndex);
      ::ca2::pen* SelectObject(::ca2::pen* pPen);
      ::ca2::brush* SelectObject(::ca2::brush* pBrush);
      virtual ::ca2::font* SelectObject(::ca2::font* pFont);
      ::ca2::bitmap* SelectObject(::ca2::bitmap* pBitmap);
      int SelectObject(::ca2::rgn* pRgn);       // special return for regions
      ::ca2::graphics_object* SelectObject(::ca2::graphics_object* pObject);
         // ::ca2::graphics_object* provided so compiler doesn't use SelectObject(HGDIOBJ)

   // color and color Palette Functions
      COLORREF GetNearestColor(COLORREF crColor) const;
      ::ca2::palette* SelectPalette(::ca2::palette* pPalette, BOOL bForceBackground);
      UINT RealizePalette();
      void UpdateColors();

   // Drawing-Attribute Functions
      COLORREF GetBkColor() const;
      int GetBkMode() const;
      int GetPolyFillMode() const;
      int GetROP2() const;
      int GetStretchBltMode() const;
      COLORREF GetTextColor() const;

      virtual COLORREF SetBkColor(COLORREF crColor);
      int SetBkMode(int nBkMode);
      int SetPolyFillMode(int nPolyFillMode);
      int SetROP2(int nDrawMode);
      int SetStretchBltMode(int nStretchMode);
      virtual COLORREF SetTextColor(COLORREF crColor);

      BOOL GetColorAdjustment(LPCOLORADJUSTMENT lpColorAdjust) const;
      BOOL SetColorAdjustment(const COLORADJUSTMENT* lpColorAdjust);

   #if (_WIN32_WINNT >= 0x0500)

      COLORREF GetDCBrushColor() const;
      COLORREF SetDCBrushColor(COLORREF crColor);

      COLORREF GetDCPenColor() const;
      COLORREF SetDCPenColor(COLORREF crColor);

   #endif

      // Graphics mode
      int SetGraphicsMode(int iMode);
      int GetGraphicsMode() const;

      // World transform
      BOOL SetWorldTransform(const XFORM* pXform);
      BOOL ModifyWorldTransform(const XFORM* pXform,DWORD iMode);
      BOOL GetWorldTransform(XFORM* pXform) const;

      // Mapping Functions
      virtual int GetMapMode() const;
      virtual point GetViewportOrg() const;
      virtual int SetMapMode(int nMapMode);
      // Viewport Origin
      virtual point SetViewportOrg(int x, int y);
      virtual point SetViewportOrg(POINT point);
      virtual point OffsetViewportOrg(int nWidth, int nHeight);

      // Viewport Extent
      virtual size GetViewportExt() const;
      virtual size SetViewportExt(int cx, int cy);
      virtual size SetViewportExt(SIZE size);
      virtual size ScaleViewportExt(int xNum, int xDenom, int yNum, int yDenom);

      // Window Origin
      point GetWindowOrg() const;
      point SetWindowOrg(int x, int y);
      point SetWindowOrg(POINT point);
      point OffsetWindowOrg(int nWidth, int nHeight);

      // Window extent
      size GetWindowExt() const;
      virtual size SetWindowExt(int cx, int cy);
            size SetWindowExt(SIZE size);
      virtual size ScaleWindowExt(int xNum, int xDenom, int yNum, int yDenom);

   // Coordinate Functions
      void DPtoLP(LPPOINT lpPoints, int nCount = 1) const;
      void DPtoLP(LPRECT lpRect) const;
      void DPtoLP(LPSIZE lpSize) const;
      void LPtoDP(LPPOINT lpPoints, int nCount = 1) const;
      void LPtoDP(LPRECT lpRect) const;
      void LPtoDP(LPSIZE lpSize) const;

   // Special Coordinate Functions (useful for dealing with metafiles and OLE)
      void DPtoHIMETRIC(LPSIZE lpSize) const;
      void LPtoHIMETRIC(LPSIZE lpSize) const;
      void HIMETRICtoDP(LPSIZE lpSize) const;
      void HIMETRICtoLP(LPSIZE lpSize) const;

   // Region Functions
      BOOL FillRgn(::ca2::rgn* pRgn, ::ca2::brush* pBrush);
      BOOL FrameRgn(::ca2::rgn* pRgn, ::ca2::brush* pBrush, int nWidth, int nHeight);
      BOOL InvertRgn(::ca2::rgn* pRgn);
      BOOL PaintRgn(::ca2::rgn* pRgn);

   // Clipping Functions
      virtual int GetClipBox(LPRECT lpRect) const;
      virtual BOOL PtVisible(int x, int y) const;
            BOOL PtVisible(POINT point) const;
      virtual BOOL RectVisible(LPCRECT lpRect) const;
            int SelectClipRgn(::ca2::rgn* pRgn);
            int ExcludeClipRect(int x1, int y1, int x2, int y2);
            int ExcludeClipRect(LPCRECT lpRect);
            int ExcludeUpdateRgn(::ca2::window * pWnd);
            int IntersectClipRect(int x1, int y1, int x2, int y2);
            int IntersectClipRect(LPCRECT lpRect);
            int OffsetClipRgn(int x, int y);
            int OffsetClipRgn(SIZE size);
      int SelectClipRgn(::ca2::rgn* pRgn, int nMode);

   // Line-Output Functions
      point GetCurrentPosition() const;
      point MoveTo(int x, int y);
      point MoveTo(POINT point);
      BOOL LineTo(int x, int y);
      BOOL LineTo(POINT point);
      BOOL Arc(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
      BOOL Arc(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
      BOOL Polyline(const POINT* lpPoints, int nCount);

      BOOL AngleArc(int x, int y, int nRadius, float fStartAngle, float fSweepAngle);
      BOOL ArcTo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
      BOOL ArcTo(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
      int GetArcDirection() const;
      int SetArcDirection(int nArcDirection);

      BOOL PolyDraw(const POINT* lpPoints, const BYTE* lpTypes, int nCount);
      BOOL PolylineTo(const POINT* lpPoints, int nCount);
      BOOL PolyPolyline(const POINT* lpPoints,
         const DWORD* lpPolyPoints, int nCount);

      BOOL PolyBezier(const POINT* lpPoints, int nCount);
      BOOL PolyBezierTo(const POINT* lpPoints, int nCount);

   // Simple Drawing Functions
      void FillRect(LPCRECT lpRect, ::ca2::brush* pBrush);
      void FrameRect(LPCRECT lpRect, ::ca2::brush* pBrush);
      void InvertRect(LPCRECT lpRect);
      BOOL DrawIcon(int x, int y, ::visual::icon * picon);
      BOOL DrawIcon(POINT point, ::visual::icon * picon);
      BOOL DrawIcon(int x, int y, ::visual::icon * picon, int cx, int cy, UINT istepIfAniCur, HBRUSH hbrFlickerFreeDraw, UINT diFlags);
      BOOL DrawState(point pt, size size, HBITMAP hBitmap, UINT nFlags,
         HBRUSH hBrush = NULL);
      BOOL DrawState(point pt, size size, ::ca2::bitmap* pBitmap, UINT nFlags,
         ::ca2::brush* pBrush = NULL);
      BOOL DrawState(point pt, size size, HICON hIcon, UINT nFlags,
         HBRUSH hBrush = NULL);
      BOOL DrawState(point pt, size size, HICON hIcon, UINT nFlags,
         ::ca2::brush* pBrush = NULL);
      BOOL DrawState(point pt, size size, const char * lpszText, UINT nFlags,
         BOOL bPrefixText = TRUE, int nTextLen = 0, HBRUSH hBrush = NULL);
      BOOL DrawState(point pt, size size, const char * lpszText, UINT nFlags,
         BOOL bPrefixText = TRUE, int nTextLen = 0, ::ca2::brush* pBrush = NULL);
      BOOL DrawState(point pt, size size, DRAWSTATEPROC lpDrawProc,
         LPARAM lData, UINT nFlags, HBRUSH hBrush = NULL);
      BOOL DrawState(point pt, size size, DRAWSTATEPROC lpDrawProc,
         LPARAM lData, UINT nFlags, ::ca2::brush* pBrush = NULL);

   // Ellipse and Polygon Functions
      BOOL Chord(int x1, int y1, int x2, int y2, int x3, int y3,
         int x4, int y4);
      BOOL Chord(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
      void DrawFocusRect(LPCRECT lpRect);
      BOOL Ellipse(int x1, int y1, int x2, int y2);
      BOOL Ellipse(LPCRECT lpRect);
      BOOL Pie(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4);
      BOOL Pie(LPCRECT lpRect, POINT ptStart, POINT ptEnd);
      BOOL Polygon(const POINT* lpPoints, int nCount);
      BOOL PolyPolygon(const POINT* lpPoints, const INT* lpPolyCounts, int nCount);
      BOOL Rectangle(int x1, int y1, int x2, int y2);
      BOOL Rectangle(LPCRECT lpRect);
      BOOL RoundRect(int x1, int y1, int x2, int y2, int x3, int y3);
      BOOL RoundRect(LPCRECT lpRect, POINT point);

   // Bitmap Functions
      BOOL PatBlt(int x, int y, int nWidth, int nHeight, DWORD dwRop);
      BOOL BitBlt(int x, int y, int nWidth, int nHeight, ::ca2::graphics * pgraphicsSrc,
         int xSrc, int ySrc, DWORD dwRop);
      BOOL StretchBlt(int x, int y, int nWidth, int nHeight, ::ca2::graphics * pgraphicsSrc,
         int xSrc, int ySrc, int nSrcWidth, int nSrcHeight, DWORD dwRop);
      COLORREF GetPixel(int x, int y) const;
      COLORREF GetPixel(POINT point) const;
      COLORREF SetPixel(int x, int y, COLORREF crColor);
      COLORREF SetPixel(POINT point, COLORREF crColor);
      BOOL FloodFill(int x, int y, COLORREF crColor);
      BOOL ExtFloodFill(int x, int y, COLORREF crColor, UINT nFillType);
      BOOL MaskBlt(int x, int y, int nWidth, int nHeight, ::ca2::graphics * pgraphicsSrc,
         int xSrc, int ySrc, ::ca2::bitmap& maskBitmap, int xMask, int yMask,
         DWORD dwRop);
      BOOL PlgBlt(LPPOINT lpPoint, ::ca2::graphics * pgraphicsSrc, int xSrc, int ySrc,
         int nWidth, int nHeight, ::ca2::bitmap& maskBitmap, int xMask, int yMask);
      BOOL SetPixelV(int x, int y, COLORREF crColor);
      BOOL SetPixelV(POINT point, COLORREF crColor);
      BOOL GradientFill(TRIVERTEX* pVertices, ULONG nVertices,
        void * pMesh, ULONG nMeshElements, DWORD dwMode);
      BOOL TransparentBlt(int xDest, int yDest, int nDestWidth, int nDestHeight,
        ::ca2::graphics * pgraphicsSrc, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight,
        UINT clrTransparent);
      bool alpha_blend(int xDest, int yDest, int nDestWidth, int nDestHeight,
        ::ca2::graphics * pgraphicsSrc, int xSrc, int ySrc, int nSrcWidth, int nSrcHeight,
        BLENDFUNCTION blend);

   // Text Functions
      virtual BOOL TextOut(int x, int y, const char * lpszString, int nCount);
            BOOL TextOut(int x, int y, const string & str);
      virtual BOOL ExtTextOut(int x, int y, UINT nOptions, LPCRECT lpRect,
               const char * lpszString, UINT nCount, LPINT lpDxWidths);
            BOOL ExtTextOut(int x, int y, UINT nOptions, LPCRECT lpRect,
               const string & str, LPINT lpDxWidths);
      virtual size TabbedTextOut(int x, int y, const char * lpszString, int nCount,
               int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin);
            size TabbedTextOut(int x, int y, const string & str,
               int nTabPositions, LPINT lpnTabStopPositions, int nTabOrigin);

   #pragma push_macro("DrawText")
   #pragma push_macro("DrawTextEx")
   #undef DrawText
   #undef DrawTextEx
      virtual int _AFX_FUNCNAME(DrawText)(const char * lpszString, int nCount, LPRECT lpRect,
               UINT nFormat);
            int _AFX_FUNCNAME(DrawText)(const string & str, LPRECT lpRect, UINT nFormat);

      virtual int _AFX_FUNCNAME(DrawTextEx)(LPTSTR lpszString, int nCount, LPRECT lpRect,
               UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
            int _AFX_FUNCNAME(DrawTextEx)(const string & str, LPRECT lpRect, UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);

            int DrawText(const char * lpszString, int nCount, LPRECT lpRect,
               UINT nFormat);
            int DrawText(const string & str, LPRECT lpRect, UINT nFormat);

            int DrawTextEx(LPTSTR lpszString, int nCount, LPRECT lpRect,
               UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
            int DrawTextEx(const string & str, LPRECT lpRect, UINT nFormat, LPDRAWTEXTPARAMS lpDTParams);
   #pragma pop_macro("DrawText")
   #pragma pop_macro("DrawTextEx")

      size GetTextExtent(const char * lpszString, int nCount) const;
      size GetTextExtent(const string & str) const;
      size GetOutputTextExtent(const char * lpszString, int nCount) const;
      size GetOutputTextExtent(const string & str) const;
      size GetTabbedTextExtent(const char * lpszString, int nCount,
         int nTabPositions, LPINT lpnTabStopPositions) const;
      size GetTabbedTextExtent(const string & str,
         int nTabPositions, LPINT lpnTabStopPositions) const;
      size GetOutputTabbedTextExtent(const char * lpszString, int nCount,
         int nTabPositions, LPINT lpnTabStopPositions) const;
      size GetOutputTabbedTextExtent(const string & str,
         int nTabPositions, LPINT lpnTabStopPositions) const;
      virtual BOOL GrayString(::ca2::brush* pBrush,
         BOOL (CALLBACK* lpfnOutput)(HDC, LPARAM, int), LPARAM lpData,
            int nCount, int x, int y, int nWidth, int nHeight);
      UINT GetTextAlign() const;
      UINT SetTextAlign(UINT nFlags);
      int GetTextFace(__in int nCount, __out_ecount_part_z(nCount, return + 1) LPTSTR lpszFacename) const;
      int GetTextFace(string & rString) const;
   #pragma push_macro("GetTextMetrics")
   #undef GetTextMetrics
      BOOL _AFX_FUNCNAME(GetTextMetrics)(LPTEXTMETRIC lpMetrics) const;
      BOOL GetTextMetrics(LPTEXTMETRIC lpMetrics) const;
   #pragma pop_macro("GetTextMetrics")
      BOOL GetOutputTextMetrics(LPTEXTMETRIC lpMetrics) const;
      int SetTextJustification(int nBreakExtra, int nBreakCount);
      int GetTextCharacterExtra() const;
      int SetTextCharacterExtra(int nCharExtra);

      DWORD GetCharacterPlacement(const char * lpString, int nCount, int nMaxExtent, LPGCP_RESULTS lpResults, DWORD dwFlags) const;
      DWORD GetCharacterPlacement(string & str, int nMaxExtent, LPGCP_RESULTS lpResults, DWORD dwFlags) const;

   #if (_WIN32_WINNT >= 0x0500)

      BOOL GetTextExtentExPointI(LPWORD pgiIn, int cgi, int nMaxExtent, LPINT lpnFit, LPINT alpDx, __out_opt LPSIZE lpSize) const;
      BOOL GetTextExtentPointI(LPWORD pgiIn, int cgi, __out_opt LPSIZE lpSize) const;

   #endif



   // Advanced Drawing
      BOOL DrawEdge(LPRECT lpRect, UINT nEdge, UINT nFlags);
      BOOL DrawFrameControl(LPRECT lpRect, UINT nType, UINT nState);

   // Scrolling Functions
      BOOL ScrollDC(int dx, int dy, LPCRECT lpRectScroll, LPCRECT lpRectClip,
         ::ca2::rgn* pRgnUpdate, LPRECT lpRectUpdate);

   // font Functions
      BOOL GetCharWidth(UINT nFirstChar, UINT nLastChar, LPINT lpBuffer) const;
      BOOL GetOutputCharWidth(UINT nFirstChar, UINT nLastChar, LPINT lpBuffer) const;
      DWORD SetMapperFlags(DWORD dwFlag);
      size GetAspectRatioFilter() const;

      BOOL GetCharABCWidths(UINT nFirstChar, UINT nLastChar, LPABC lpabc) const;
      DWORD GetFontData(DWORD dwTable, DWORD dwOffset, LPVOID lpData, DWORD cbData) const;
      int GetKerningPairs(int nPairs, LPKERNINGPAIR lpkrnpair) const;
      UINT GetOutlineTextMetrics(UINT cbData, LPOUTLINETEXTMETRIC lpotm) const;
      DWORD GetGlyphOutline(UINT nChar, UINT nFormat, LPGLYPHMETRICS lpgm,
         DWORD cbBuffer, LPVOID lpBuffer, const MAT2* lpmat2) const;

      BOOL GetCharABCWidths(UINT nFirstChar, UINT nLastChar,
         LPABCFLOAT lpABCF) const;
      BOOL GetCharWidth(UINT nFirstChar, UINT nLastChar,
         float* lpFloatBuffer) const;

      DWORD GetFontLanguageInfo() const;

   #if (_WIN32_WINNT >= 0x0500)

      BOOL GetCharABCWidthsI(UINT giFirst, UINT cgi, LPWORD pgi, LPABC lpabc) const;
      BOOL GetCharWidthI(UINT giFirst, UINT cgi, LPWORD pgi, LPINT lpBuffer) const;

   #endif

   // Printer/Device Escape Functions
      virtual int Escape(__in int nEscape, __in int nCount,
         __in_bcount(nCount) const char * lpszInData, __in LPVOID lpOutData);
      int Escape(__in int nEscape, __in int nInputSize, __in_bcount(nInputSize) const char * lpszInputData,
         __in int nOutputSize, __out_bcount(nOutputSize) char * lpszOutputData);
      int DrawEscape(int nEscape, int nInputSize, const char * lpszInputData);

      // Escape helpers
      int StartDoc(const char * lpszDocName);  // old Win3.0 version
      int StartDoc(LPDOCINFO lpDocInfo);
      int StartPage();
      int EndPage();
      int SetAbortProc(BOOL (CALLBACK* lpfn)(HDC, int));
      int AbortDoc();
      int EndDoc();

   // MetaFile Functions
      BOOL PlayMetaFile(HMETAFILE hMF);
      BOOL PlayMetaFile(HENHMETAFILE hEnhMetaFile, LPCRECT lpBounds);
      BOOL AddMetaFileComment(UINT nDataSize, const BYTE* pCommentData);
         // can be used for enhanced metafiles only

   // Path Functions
      BOOL AbortPath();
      BOOL BeginPath();
      BOOL CloseFigure();
      BOOL EndPath();
      BOOL FillPath();
      BOOL FlattenPath();
      BOOL StrokeAndFillPath();
      BOOL StrokePath();
      BOOL WidenPath();
      float GetMiterLimit() const;
      BOOL SetMiterLimit(float fMiterLimit);
      int GetPath(LPPOINT lpPoints, LPBYTE lpTypes, int nCount) const;
      BOOL SelectClipPath(int nMode);

   // Misc Helper Functions
      static ::ca2::brush* PASCAL GetHalftoneBrush(::ca2::application * papp);
      void DrawDragRect(LPCRECT lpRect, SIZE size,
         LPCRECT lpRectLast, SIZE sizeLast,
         ::ca2::brush* pBrush = NULL, ::ca2::brush* pBrushLast = NULL);
      void FillSolidRect(const __rect64 * lpRect, COLORREF clr);
      void FillSolidRect(LPCRECT lpRect, COLORREF clr);
      void FillSolidRect(int x, int y, int cx, int cy, COLORREF clr);
      void Draw3dRect(LPCRECT lpRect, COLORREF clrTopLeft, COLORREF clrBottomRight);
      void Draw3dRect(int x, int y, int cx, int cy,
         COLORREF clrTopLeft, COLORREF clrBottomRight);

   // Implementation
   public:
   #ifdef DEBUG
      virtual void assert_valid() const;
      virtual void dump(dump_context & dumpcontext) const;
   #endif

      // advanced use and implementation
      BOOL m_bPrinting;
      HGDIOBJ SelectObject(HGDIOBJ);      // do not use for regions

   protected:
      // used for implementation of non-virtual SelectObject calls
      static ::ca2::graphics_object* PASCAL SelectGdiObject(::ca2::application * papp, HDC hDC, HGDIOBJ h);
   };

} // namespace android
