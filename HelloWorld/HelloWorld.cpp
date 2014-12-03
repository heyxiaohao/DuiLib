#include <windows.h>
#include <tchar.h>

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
    ::MessageBox(NULL, _T("Hello World !"), NULL, NULL);
    return 0;
}