
#include "WndUI.h"
#include <UIlib.h>
using namespace DuiLib;

class DuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder() { return _T("../使用MFC控件"); }

	virtual CControlUI *CreateControl(LPCTSTR pstrClass)
	{
		if (_tcsicmp(pstrClass, _T("Wnd")) == 0)
		{
			CWndUI *pUI = new CWndUI();
			HWND hWnd = CreateWindow(_T("Button"), _T("win32"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
				0, 0, 0, 0, m_PaintManager.GetPaintWindow(), NULL, NULL, NULL);
			pUI->Attach(hWnd);
			// 或使用MFC按钮
// 			CButton *pBtn = new CButton;
// 			pBtn->Create(_T("MFC"), WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, CRect(0, 0, 0, 0), CWnd::FromHandle(m_PaintManager.GetPaintWindow()), NULL);
// 			pUI->Attach(*pBtn);

			return pUI;
		}
		return NULL;
	}


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