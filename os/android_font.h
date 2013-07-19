#pragma once

namespace android
{

   class CLASS_DECL_ANDROID font :
      virtual public ::android::graphics_object,
      virtual public ::ca2::font
   {
   public:
      static font * PASCAL from_handle(::ca2::application * papp, HFONT hFont);

      font(::ca2::application * papp);
      virtual ~font();

      virtual void font::construct(const ::ca2::font & fontParam);

      virtual BOOL CreateFontIndirect(const LOGFONT* lpLogFont);
      virtual BOOL CreateFont(int nHeight, int nWidth, int nEscapement,
            int nOrientation, int nWeight, BYTE bItalic, BYTE bUnderline,
            BYTE cStrikeOut, BYTE nCharSet, BYTE nOutPrecision,
            BYTE nClipPrecision, BYTE nQuality, BYTE nPitchAndFamily,
            const char * lpszFacename);
      virtual BOOL CreatePointFont(int nPointSize, const char * lpszFaceName, ::ca2::graphics * pgraphics = NULL);
      virtual BOOL CreatePointFontIndirect(const LOGFONT* lpLogFont, ::ca2::graphics * pgraphics = NULL);

   // Attributes
      operator HFONT() const;
      virtual int GetLogFont(LOGFONT* pLogFont);

      // Implementation
      public:
      #ifdef DEBUG
         virtual void dump(dump_context & dumpcontext) const;
      #endif
   };

} // namespace android
