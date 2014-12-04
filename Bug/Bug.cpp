/*
此工程 点击最大化后 中间的按钮没有变成 还原按钮
需要在WindowImplBase的OnSysCommand函数里，在if( ::IsZoomed(*this) != bZoomed )里面加上代码
if( ::IsZoomed(*this) != bZoomed )
{
	CControlUI* pbtnMax     = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("maxbtn")));       // 最大化按钮
	CControlUI* pbtnRestore = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("restorebtn")));   // 还原按钮

	// 切换最大化按钮和还原按钮的状态
	if (pbtnMax && pbtnRestore)
	{
	pbtnMax->SetVisible(TRUE == bZoomed);       // 此处用表达式是为了避免编译器BOOL转换的警告
	pbtnRestore->SetVisible(FALSE == bZoomed);
	}
}

注：要重新编译动态库

CDuiString的Bug， 常量放在前面 作比较 总是为false  因为CDuiString没有重载此类==操作符，推荐使用std::string

#include <string>
#include <sstream>

namespace duilib
{
#ifdef _UNICODE
	typedef wchar_t              char_t;
	typedef std::wstring         string_t;
	typedef std::wstringstream   stringstream_t;
#else
	typedef char                 char_t;
	typedef std::string          string_t;
	typedef std::stringstream    stringstream_t;
#endif
}


*/

#include <UIlib.h>
using namespace DuiLib;

class DuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder() { return _T("../Bug"); }
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