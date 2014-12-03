/*
1 调用AddNotifier将消息加入duilib的消息循环
2 给按钮设置唯一的控件ID (SetName函数）
3 在Notify函数里处理按钮点击消息
*/


#include <UIlib.h>
using namespace DuiLib;

class DuiFrameWnd :public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DuiMainFrame"); }

	// 处理消息
	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			if (msg.pSender->GetName() == _T("btnHello"))
			{
				::MessageBox(NULL, _T("我是按钮"), _T("点击了按钮"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		if (uMsg == WM_CREATE)
		{
			// CControlUI 是所有控件的基类
			CControlUI *pWnd = new CButtonUI;
			pWnd->SetName(_T("btnHello")); // 设置控件的名字，唯一标识
			pWnd->SetText(_T("HelloWorld")); // 设置文字
			pWnd->SetBkColor(0xFF00FF00);
			m_PaintManager.Init(m_hWnd);
			m_PaintManager.AttachDialog(pWnd);
			m_PaintManager.AddNotifier(this); // 添加控件消息响应
			return lRes;
		}

		if (m_PaintManager.MessageHandler(uMsg, wParam, lParam, lRes))
		{
			return lRes;
		}

		return __super::HandleMessage(uMsg, wParam, lParam);
	}

protected:
	CPaintManagerUI m_PaintManager;
};

int APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);

	DuiFrameWnd duiFrame;
	duiFrame.Create(nullptr, _T("DuiWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.ShowModal();

	return 0;
}