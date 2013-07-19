#pragma once


CLASS_DECL_ANDROID HINSTANCE  vfxFindResourceHandle(const char * lpszName, const char * lpszType);
CLASS_DECL_ANDROID HINSTANCE  vfxFindResourceHandle(const char * lpszName, const char * lpszType);

class CLASS_DECL_ANDROID WinResource :
   virtual public ex1::resource
{
public:
   WinResource(::ca2::application * papp);
   virtual ~WinResource();
   //bool ReadResource(ex1::filesp & file, UINT nID, const char * lpcszType);
   //bool ReadResource(HINSTANCE hinst, ex1::filesp & file, UINT nID, const char * lpcszType);
   bool ReadResource(string & str, UINT nID, const char * lpcszType);
   bool ReadResource(ex1::file & file, UINT nID, const char * lpcszType);
   bool ReadResource(HINSTANCE hinst, ex1::file & file, UINT nID, const char * lpcszType);
};
