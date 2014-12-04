
/*
可定制默认样式，如Button 如果没有指定属性，则使用默认属性
给<Window>节点添加一个Default节点即可，其中
name属性填写控件的名字，
value属性添加控件的属性的值，需要将双引号【"】换成【&quot;】，单引号【'】换成【&apos;】,单引号也可以不转换。
*/

#include <UIlib.h>
using namespace DuiLib;

class DuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder() { return _T("../简单控件"); }
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