#include "iostream"
#include "windows.h"

using namespace std;

CHAR windowText[MAXBYTE], className[MAXBYTE];
WORD windowNumber = 0;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam) {
  windowNumber++;
  GetWindowText(hwnd, windowText, 200);
  GetClassName(hwnd, className, 200);

  cout << windowNumber << " [Window Name] "
       << (strlen(windowText) ? windowText : "null") << " [Class Name] "
       << className << endl;
  return TRUE;
}

int main() {
  EnumWindows(EnumWindowsProc, NULL);
  while (TRUE)
    ;
  return 0;
}