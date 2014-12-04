/*
问题：所有的MFC控件都显示在duilib窗口的上面，这里和ZORD顺序应该有关系
*/

#include <UIlib.h>
using namespace DuiLib;

class DuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder() { return _T("../自绘标题栏XML版"); }
};


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	CPaintManagerUI::SetResourcePath(_T("."));

	DuiFrameWnd duiFrame;
	duiFrame.Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.CenterWindow();
	duiFrame.ShowModal();

	return 0;
}