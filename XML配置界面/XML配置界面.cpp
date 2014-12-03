
/*
duilib主打的界面制作方式是XML + UI引擎 + win32框架
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
		// 1 修改WM_CREATE消息处理
		if (uMsg == WM_CREATE)
		{
			/************************************************************************/
			/* 非XML方式构建界面
			/************************************************************************/
			// CControlUI 是所有控件的基类
			//CControlUI *pWnd = new CButtonUI;
			//pWnd->SetName(_T("btnHello")); // 设置控件的名字，唯一标识
			//pWnd->SetText(_T("HelloWorld")); // 设置文字
			//pWnd->SetBkColor(0xFF00FF00);
			//m_PaintManager.Init(m_hWnd);
			//m_PaintManager.AttachDialog(pWnd);
			//m_PaintManager.AddNotifier(this); // 添加控件消息响应
			//return lRes;

			/************************************************************************/
			/* XML方式构建界面
			/************************************************************************/
			m_PaintManager.Init(m_hWnd);
			CDialogBuilder builder;
			// duilib.xml需要放到exe目录下
			CControlUI *pRoot = builder.Create(_T("duilib.xml"), (UINT)0, NULL, &m_PaintManager); 
			ASSERT(pRoot && "Failed to parse XML");
			m_PaintManager.AttachDialog(pRoot);
			m_PaintManager.AddNotifier(this);
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
	// 2 设置XML路径
	//CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()); // 设置资源默认路径（此处设置为与exe同级目录）
	CPaintManagerUI::SetResourcePath(_T("."));
	// 3 建立xml

	DuiFrameWnd duiFrame;
	duiFrame.Create(nullptr, _T("DuiWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.ShowModal();

	return 0;
}