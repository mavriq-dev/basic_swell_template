/*
  File: main.cpp (example use of Swell)

*/

#ifndef WDL_NO_DEFINE_MINMAX
#define WDL_NO_DEFINE_MINMAX
#endif
#include "../vendor/WDL/WDL/wdltypes.h"
//#include <math.h>
//#include <stdio.h>

#ifndef _WIN32
#include "../vendor/WDL/WDL/swell/swell.h"
#else
#define _WIN32_WINNT 0x0601 //Target Windows 7 SP1
#endif

#include "resource.h"


HINSTANCE g_hInstance;


static void DoPaint(HWND hwndDlg, HDC dc)
{
  RECT r;
  GetClientRect(hwndDlg, &r);
  
#ifdef _WIN32
  r.top+=40;
  if (r.top >= r.bottom) r.top=r.bottom-1;
#endif
  
}

// this is only used on OS X since it's way faster there
/*LRESULT WINAPI testRenderDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{

   return DefWindowProc(hwndDlg,uMsg,wParam,lParam);
}*/

WDL_DLGRET WINAPI dlgProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
  switch(uMsg)
  {
  case WM_INITDIALOG:

    
  return 0;
  case WM_DESTROY:

  return 0;
    
#ifdef _WIN32
  case WM_TIMER:
    InvalidateRect(hwndDlg,NULL,FALSE);
    return 0;
  case WM_PAINT:
    {
      PAINTSTRUCT ps;
      
      HDC dc = BeginPaint(hwndDlg, &ps);

      DoPaint(hwndDlg,dc);
      EndPaint(hwndDlg,&ps);
    }
    break;
#else
  case WM_SIZE:
  {
    RECT r;
    GetClientRect(hwndDlg,&r);
    r.top+=40;
    SetWindowPos(GetDlgItem(hwndDlg,IDC_RECT),NULL,r.left,r.top,r.right-r.left,r.bottom-r.top,SWP_NOZORDER|SWP_NOACTIVATE);
  }
  return 0;
  case WM_TIMER:
#if 1
    InvalidateRect(GetDlgItem(hwndDlg,IDC_RECT),NULL,FALSE);
#else
    {
      HWND h = GetDlgItem(hwndDlg,IDC_RECT);
      HDC dc = GetWindowDC(h);
      DoPaint(hwndDlg,dc);
      ReleaseDC(h,dc);
      SWELL_FlushWindow(h);
    }
#endif
  return 0;
#endif
  case WM_COMMAND:
    switch(LOWORD(wParam))
    {
      break;
      case IDCANCEL:
#ifndef __APPLE__
        EndDialog(hwndDlg, 0);
#else
        DestroyWindow(hwndDlg); // on mac we run modeless
#endif
      break;
    }
    break;
  }
  return 0;
}

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nShowCmd)
{

  g_hInstance=hInstance;
  DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, dlgProc);

  return 0;
}
#else

/*static HWND ccontrolCreator(HWND parent, const char *cname, int idx, const char *classname, int style, int x, int y, int w, int h)
{
  if (!stricmp(classname,"TestRenderingClass"))
  {
    HWND hw=CreateDialog(NULL,0,parent,(DLGPROC)testRenderDialogProc);
    SetWindowLong(hw,GWL_ID,idx);
    SetWindowPos(hw,HWND_TOP,x,y,w,h,SWP_NOZORDER|SWP_NOACTIVATE);
    ShowWindow(hw,SW_SHOWNA);
    return hw;
  }
  return 0;
}*/

#include "../vendor/WDL/WDL/swell/swell-dlggen.h"

// Include the resource files build by swell_resgen.php
#include "basic_swell_template.rc_mac_dlg"
#include "basic_swell_template.rc_mac_menu"

#if !defined(__APPLE__) // This is for Linux only.
int main(int argc, char **argv)
{
  SWELL_initargs(&argc,&argv);
  SWELL_Internal_PostMessage_Init();
  SWELL_ExtendedAPI("APPNAME",(void*)"basic_swell_template");
  //SWELL_RegisterCustomControlCreator(ccontrolCreator);
  //SWELL_ExtendedAPI("INIFILE",(void*)"path/to/ini/file.ini");
  //SWELL_ExtendedAPI("FONTPANGRAM",(void*)"LICE test thingy lbah akbzfshauoh01384u1023");
  DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, dlgProc);

  return 0;
}

INT_PTR SWELLAppMain(int msg, INT_PTR parm1, INT_PTR parm2)
{
  return 0;
}
#endif
#endif
