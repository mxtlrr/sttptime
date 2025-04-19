#include <Windows.h>

#include "frontend-add-game.hpp"
#include "get-all-processes.hpp"
#include "resource.h"

#define UNUSED(expr) do { (void)(expr); } while (0)

BOOL CALLBACK DialogProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  UNUSED(lParam);
  
  switch (msg) {
    case WM_INITDIALOG: {
      // Wait 10sec before updating the process list.
      SetTimer(hwnd, 1, 10000, NULL);
      break;
    }

    case WM_CLOSE: {
      EndDialog(hwnd, 0);
      return TRUE;
    }
    case WM_TIMER: {
      std::vector<std::string> k117 = GetProcesses();
      // Make sure the combobox is clear beforehand
      for(uint32_t i = 0; i < k117.size()+100; i++)
        SendMessage(GetDlgItem(hwnd, IDC_COMBO1), CB_DELETESTRING, i, 0);

      for(uint32_t i = 0; i < k117.size(); i++){
        SendMessage(GetDlgItem(hwnd, IDC_COMBO1), CB_ADDSTRING,
          0, reinterpret_cast<LPARAM>(_T(k117[i].c_str())));
      }
      
      return TRUE;
    }
  }
  return FALSE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
  UNUSED(nShowCmd); UNUSED(lpCmdLine); UNUSED(hPrevInstance);
  DialogBoxParam(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc, 0);
  return 0;
}