#pragma once

namespace win
{

   //////////////////////////////////////////////////////////////////////
   //   Creator : El Barto (ef00@luc.ac.be)
   //   Location : http://www.luc.ac.be/~ef00/ebgfx
   //   Date : 09-04-98
   //////////////////////////////////////////////////////////////////////

   class CLASS_DECL_ANDROID dib :
      virtual public ::ca2::dib
   {
   public:

      static float Cosines[360];
      static float Sines[360];
      static int64_t CosN[360]; // * 1 << 31
      static int64_t SinN[360];
      static int64_t Cos10N[10]; // until 10 degress
      static int64_t Sin10N[10]; // more precision * 1 << 34
      static double dPi;

      COLORREF *           m_pcolorref;
      BITMAPINFO           m_info;
      ::ca2::bitmap_sp      m_spbitmap;
      ::ca2::graphics_sp    m_spgraphics;
      class size           m_size;
      HBITMAP              m_hbitmapOriginal;

      virtual ::ca2::graphics * get_graphics();
      virtual ::ca2::bitmap_sp get_bitmap();
      virtual ::ca2::bitmap_sp detach_bitmap();


      virtual COLORREF * get_data();

      dib(::ca2::application * papp);
      virtual void construct(int cx, int cy);
      virtual ~dib();

      static void s_initialize();
      void stretch_dib(::ca2::dib * pdib);

      bool dc_select(bool bSelect = true);

      COLORREF GetAverageColor();
      bool Blend(::ca2::dib *pdib, ::ca2::dib * pdibA, int A);
      bool color_blend(COLORREF cr, BYTE bAlpha);
      void BitBlt(::ca2::dib * pdib, int op);
      int cos(int i, int iAngle);
      int sin(int i, int iAngle);
      int cos10(int i, int iAngle);
      int sin10(int i, int iAngle);

      bool is_rgb_black();
      void xor(::ca2::dib * pdib);

      void ToAlpha(int i);
      void ToAlphaAndFill(int i, COLORREF cr);
      void GrayToARGB(COLORREF cr);

      void from_alpha();
      void mult_alpha();

      void rotate(::ca2::dib * pdib, LPCRECT lpcrect, double dAngle, double dScale);
      void rotate(::ca2::dib * pdib, double dAngle, double dScale);
      void Rotate034(::ca2::dib * pdib, double dAngle, double dScale);


      void SetIconMask(::visual::icon * picon, int cx, int cy);
      void RadialFill(BYTE a, BYTE r, BYTE g, BYTE b, int x, int y, int iRadius);
      void RadialFill(
         BYTE a1, BYTE r1, BYTE g1, BYTE b1, // center colors
         BYTE a2, BYTE r2, BYTE g2, BYTE b2, // border colors
         int x, int y, int iRadius);

      DWORD GetPixel(int x, int y);
      void Mask(COLORREF crMask, COLORREF crInMask, COLORREF crOutMask);
      void channel_mask(BYTE uchFind, BYTE uchSet, BYTE uchUnset, visual::rgba::echannel echannel);
      void transparent_color(color color);


      BOOL create(class size size);
      BOOL create(int iWidth, int iHeight);
      BOOL create(::ca2::graphics * pdc);
      BOOL Destroy();


      void DivideRGB(int iDivide);
      void DivideARGB(int iDivide);
      void DivideA(int iDivide);

      bool from(::ca2::graphics * pdc);
      bool from(point ptDest, ::ca2::graphics * pdc, point pt, class size sz);

      bool to(::ca2::graphics * pgraphics, point pt, class size size, point ptSrc);

      virtual void fill_channel(int C, visual::rgba::echannel echannel);
      void Fill (int A, int R, int G, int B );
      void Fill ( int R, int G, int B );
      void FillGlass ( int R, int G, int B, int A );
      void FillStippledGlass ( int R, int G, int B );
      void Invert();
      void channel_invert(visual::rgba::echannel echannel);
      void channel_multiply(visual::rgba::echannel echannel, double dRate);

      void Map (int ToRgb, int FromRgb );

      void copy( ::ca2::dib *dib );
      void Paste ( ::ca2::dib *dib );

      void Blend ( ::ca2::dib *dib, int A );
      void Darken ( ::ca2::dib *dib );
      void Difference ( ::ca2::dib *dib );
      void Lighten ( ::ca2::dib *dib );
      void Multiply ( ::ca2::dib *dib );
      void Screen ( ::ca2::dib *dib );

      void copy ( ::ca2::dib *dib, int x, int y );
      void PasteRect ( ::ca2::dib *dib, int x, int y );

      void FillRect ( int x, int y, int w, int h, int R, int G, int B );
      void FillGlassRect ( int x, int y, int w, int h, int R, int G, int B, int A );
      void FillStippledGlassRect ( int x, int y, int w, int h, int R, int G, int B );

      void BlendRect ( ::ca2::dib *dib, int x, int y, int A );
      void DarkenRect ( ::ca2::dib *dib, int x, int y );
      void DifferenceRect ( ::ca2::dib *dib, int x, int y );
      void LightenRect ( ::ca2::dib *dib, int x, int y );
      void MultiplyRect ( ::ca2::dib *dib, int x, int y );
      void ScreenRect ( ::ca2::dib *dib, int x, int y );

      void Line ( int x1, int y1, int x2, int y2, int R, int G, int B );
      void LineGlass ( int x1, int y1, int x2, int y2, int R, int G, int B, int A );

      void create_frame(class size size, int iFrameCount);
      void set_frame2(void * lpdata, int iFrame, int iFrameCount);
      void set_frame1(void * lpdata, int iFrame, int iFrameCount);
      void get_frame(void * lpdata, int iFrame, int iFrameCount);
      void xor_dib_frame2(void * lpdata, int iFrame, int iFrameCount);


      int width();
      int height();
      double pi();
   };

} // namespace win
