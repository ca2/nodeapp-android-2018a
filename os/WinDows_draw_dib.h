#pragma once

#include <vfw.h>

namespace win
{

   //////////////////////////////////////////////////////////////////////
   //
   //   Creator : El Barto (ef00@luc.ac.be)
   //   Location : http://www.luc.ac.be/~ef00/ebgfx
   //   Date : 09-04-98
   //
   //////////////////////////////////////////////////////////////////////

   class CLASS_DECL_ANDROID draw_dib :
      virtual public ::ca2::draw_dib
   {
   public:
      HDRAWDIB m_hdrawdib;

      draw_dib(::ca2::application * papp);
      virtual ~draw_dib ();

      virtual void * get_os_data();

      BOOL open ();
      BOOL close ();
      
      BOOL Begin ( ::ca2::graphics * pdc, int dxDest, int dyDest,
         LPBITMAPINFOHEADER lpbi, int dxSrc, int dySrc, UINT wFlags );
      BOOL End ();

      BOOL draw(::ca2::graphics * pdc, int xDst, int yDst,
         int dxDst, int dyDst, LPBITMAPINFOHEADER lpbi, LPVOID lpBits,
         int xSrc, int ySrc, int dxSrc, int dySrc, UINT wFlags );
      BOOL draw(::ca2::dib * pdib, ::ca2::graphics * pdc, int xDst, int yDst,
         int dxDst, int dyDst, UINT wFlags );

      BOOL draw(::ca2::graphics * pdc, int xDst, int yDst,
         int dxDst, int dyDst, 
          ::ca2::dib * dib, int xSrc, int ySrc,
         int dxSrc, int dySrc, UINT wFlags );
      
      LPVOID GetBuffer ( LPBITMAPINFOHEADER lpbi,
         DWORD dwSize, DWORD dwFlags );
      
      BOOL ProfileDisplay ( LPBITMAPINFOHEADER lpbi );

      ::ca2::palette * get_palette();
      BOOL set_palette ( ::ca2::palette * ppal );
      BOOL ChangePalette ( ::ca2::draw_dib * pdd, int iStart, int iLen,
         LPPALETTEENTRY lppe );
      UINT Realize ( ::ca2::graphics * pdc, BOOL fBackground );

      BOOL Start ( LONG rate );
      BOOL Stop ();
      BOOL time ( LPDRAWDIBTIME lpddtime );

   };

} // namespace win