#pragma once

namespace user
{
   class ::user::window_interface;
} // namespace user

namespace android
{

   class CLASS_DECL_ANDROID window_draw :
      virtual public ::ca2::window_draw,
      virtual public ::ca2::message_window_simple_callback
   {
   public:


      enum EOptimize
      {
         OptimizeNone,
         OptimizeThis,
         OptimizeAllNext,
      };

      user::LPWndArray                       m_wndpaOut;
      user::window_draw_client_tool          m_twrenderclienttool;
      mutex                                  m_mutexRendering;
      mutex                                  m_mutexRgnUpdate;
      semaphore                              m_semaphoreBuffer;
      bool                                   m_bRender;
      DWORD                                  m_dwLastRedrawRequest;
      mutex                                  m_mutexRender;
      critical_section                       m_csWndInterfaceMap;
      typed_pointer_map <
         CMapPtrToPtr,
         oswindow,
         ::user::window_interface *>
                                             m_wndinterfacemap;
      DWORD                                  m_dwLastUpdate;


      window_draw(::ca2::application * papp);
      virtual ~window_draw();


      virtual bool start();

      bool UpdateBuffer(LPCRECT lpcrect);
      //void OnPaint(oswindow hwnd, CPaintDC & spgraphics);

      semaphore * TwfGetBufferSemaphore();

      // Bit blitting spread functions
      virtual bool ScreenOutput(
         user::buffer *,
         ::ca2::rgn & rgnUpdate);

      virtual bool ScreenOutput();

      virtual bool ScreenOutput(
         user::buffer *,
         ::user::interaction* pwnd,
         ::ca2::rgn & rgnUpdate);

      // Transparent drawing operations
      // controllers
      virtual bool UpdateBuffer();

      virtual bool to(
         ::ca2::graphics *       pdc,
         LPCRECT     lprectUpdate,
         user::HwndTree & hwndtree,
         bool        bGdiLocked,
         bool        bExcludeParamWnd);

      virtual bool to(
         ::ca2::graphics *       pdc,
         LPCRECT     lprectUpdate,
         user::HwndTree::Array & hwndtreea,
         bool        bGdiLocked,
         bool        bExcludeParamWnd);

   /*     EOptimize TwfOptimizeRender2(
         user::HwndTree::Array & hwndtreea,
         LPCRECT lpcrect);

      EOptimize TwfOptimizeRender2(
         user::HwndTree & hwndtree,
         LPCRECT lpcrect);*/


      EOptimize TwfOptimizeRender(
         user::HwndTree::Array & hwndtreea,
         LPCRECT lpcrect);

      EOptimize TwfOptimizeRender(
         user::HwndTree & hwndtree,
         LPCRECT lpcrect);

      void TwfGetTopWindow(
         oswindow hwnd,
         user::HWNDArray & hwnda,
         base_array < HRGN, HRGN > & hrgna,
         user::HwndTree::Array & hwndtreea,
         LPCRECT lpcrect);

      bool TwfGetTopWindow(
         oswindow hwnd,
         user::HWNDArray & hwnda,
         base_array < HRGN, HRGN > & hrgna,
         user::HwndTree::Array & hwndtreea,
         HRGN hrgn);

      bool TwfGetTopWindow(
         oswindow hwnd,
         user::HWNDArray & hwnda,
         base_array < HRGN, HRGN > & hrgna,
         user::HwndTree & hwndtree,
         HRGN hrgn);

      void TwfGetTopWindowOptimizeOpaque(
         oswindow hwndOpaque,
         user::HWNDArray & hwnda,
         base_array < HRGN, HRGN > & hrgna);


      EOptimize TwfOptimizeRenderRemoveNextProper(
         user::HwndTree::Array & hwndtreea,
         int iIndex,
         LPCRECT lpcrect);

      void get_wnda(user::LPWndArray & wndpa);
      void get_wnda(user::HWNDArray & hwnda);

      static UINT __CDECL ThreadProcRedraw(LPVOID lpv);

      virtual UINT RedrawProc();

      virtual void asynch_redraw();
      virtual void _asynch_redraw();
      virtual void synch_redraw();
      virtual void _synch_redraw();

      virtual void message_window_message_handler(::ca2::signal_object * pobj);

   };

} // namespace android
