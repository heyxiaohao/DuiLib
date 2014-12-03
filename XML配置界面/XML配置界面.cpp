
/*
duilib����Ľ���������ʽ��XML + UI���� + win32���
*/

#include <UIlib.h>
using namespace DuiLib;

class DuiFrameWnd :public CWindowWnd, public INotifyUI
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DuiMainFrame"); }

	// ������Ϣ
	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("click"))
		{
			if (msg.pSender->GetName() == _T("btnHello"))
			{
				::MessageBox(NULL, _T("���ǰ�ť"), _T("����˰�ť"), NULL);
			}
		}
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		LRESULT lRes = 0;
		// 1 �޸�WM_CREATE��Ϣ����
		if (uMsg == WM_CREATE)
		{
			/************************************************************************/
			/* ��XML��ʽ��������
			/************************************************************************/
			// CControlUI �����пؼ��Ļ���
			//CControlUI *pWnd = new CButtonUI;
			//pWnd->SetName(_T("btnHello")); // ���ÿؼ������֣�Ψһ��ʶ
			//pWnd->SetText(_T("HelloWorld")); // ��������
			//pWnd->SetBkColor(0xFF00FF00);
			//m_PaintManager.Init(m_hWnd);
			//m_PaintManager.AttachDialog(pWnd);
			//m_PaintManager.AddNotifier(this); // ��ӿؼ���Ϣ��Ӧ
			//return lRes;

			/************************************************************************/
			/* XML��ʽ��������
			/************************************************************************/
			m_PaintManager.Init(m_hWnd);
			CDialogBuilder builder;
			// duilib.xml��Ҫ�ŵ�exeĿ¼��
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
	// 2 ����XML·��
	//CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath()); // ������ԴĬ��·�����˴�����Ϊ��exeͬ��Ŀ¼��
	CPaintManagerUI::SetResourcePath(_T("."));
	// 3 ����xml

	DuiFrameWnd duiFrame;
	duiFrame.Create(nullptr, _T("DuiWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame.ShowModal();

	return 0;
}