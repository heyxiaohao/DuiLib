/*
窗口的最后一个函数一定是OnFinalMessage
*/

#ifndef __DUI_MENU_H__
#define __DUI_MENU_H__

#include <UIlib.h>
using namespace DuiLib;

class CDuiMenu : public WindowImplBase
{
protected:
	virtual ~CDuiMenu()
	{
		// 私有化析构函数，此对象只能 new
	}

	CDuiString m_strXMLPath;

public:
	explicit CDuiMenu(LPCTSTR pszXMLPath) : m_strXMLPath(pszXMLPath){}
	virtual LPCTSTR GetWindowClassName() const { return _T("CDuiMenu"); }
	virtual CDuiString GetSkinFolder(){ return _T("../菜单"); }
	virtual CDuiString GetSkinFile() { return m_strXMLPath; }
	virtual void OnFinalMessage(HWND hWnd) { delete this; }
	virtual LRESULT OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled)
	{
		Close();
		bHandled = FALSE;
		return 0;
	}

	void Init(HWND hWndParaent, POINT ptPos)
	{
		Create(hWndParaent, _T("MenuWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
		::ClientToScreen(hWndParaent, &ptPos);
		::SetWindowPos(*this, NULL, ptPos.x, ptPos.y, 0, 0, SWP_NOZORDER | SWP_NOSIZE | SWP_NOACTIVATE);
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		BOOL bHandled = TRUE;

		switch (uMsg)
		{
		case WM_KILLFOCUS:
			lRes = OnKillFocus(uMsg, wParam, lParam, bHandled);
			break;
		default:
			bHandled = FALSE;
			break;
		}

		if (bHandled || m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}
};

#endif // __DUI_MENU_H__