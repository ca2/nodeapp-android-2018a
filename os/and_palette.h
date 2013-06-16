#pragma once

namespace win
{

   class CLASS_DECL_ANDROID palette : 
      virtual public ::win::graphics_object,
      virtual public ::ca2::palette
   {
   public:
      static palette* PASCAL from_handle(::ca2::application * papp, HPALETTE hPalette);

      palette(::ca2::application * papp);
      BOOL CreatePalette(LPLOGPALETTE lpLogPalette);
      BOOL CreateHalftonePalette(::ca2::graphics * pgraphics);

   // Attributes
      operator HPALETTE() const;
      int GetEntryCount();
      UINT GetPaletteEntries(UINT nStartIndex, UINT nNumEntries,
            LPPALETTEENTRY lpPaletteColors) const;
      UINT SetPaletteEntries(UINT nStartIndex, UINT nNumEntries,
            LPPALETTEENTRY lpPaletteColors);

   // Operations
      void AnimatePalette(UINT nStartIndex, UINT nNumEntries,
            LPPALETTEENTRY lpPaletteColors);
      UINT GetNearestPaletteIndex(COLORREF crColor) const;
      BOOL ResizePalette(UINT nNumEntries);

   // Implementation
      virtual ~palette();
   };

} // namespace win