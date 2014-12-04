/*
���ӵĿؼ�����Ҫ��ʼ��  ��ʼ������InitWindow
UI����������Name���Բ���ʹĬ�ϵ����֣����򲻻�д��xml��
*/

#include <UIlib.h>
using namespace DuiLib;

class DuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder() { return _T("../���ӿؼ�"); }

	virtual void InitWindow()
	{
		CActiveXUI *pActiveXUI = static_cast<CActiveXUI*>(m_PaintManager.FindControl(_T("ActiveXDemo1")));
		if (pActiveXUI)
		{
			IWebBrowser2 *pWebBrowser = NULL;
			pActiveXUI->SetDelayCreate(false); // �൱�ڽ����������DelayCreate
			pActiveXUI->CreateControl(CLSID_WebBrowser); // �൱�ڽ�����������CLSID����ֵ
			pActiveXUI->GetControl(IID_IWebBrowser2, (void **)&pWebBrowser);
			if (pWebBrowser != NULL)
			{
				pWebBrowser->Navigate(L"http://www.baidu.com", NULL, NULL, NULL, NULL);
				pWebBrowser->Release();
			}
		}

		// �ı��������λ��
		CProgressUI *pProgressUI = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("ProgressDemo1")));
		if (pProgressUI)
		{
			pProgressUI->SetValue(86);
		}

		// �ı们������λ��
		CSliderUI *pSliderUI = static_cast<CSliderUI*>(m_PaintManager.FindControl(_T("SliderDemo1")));
		if (pSliderUI)
		{
			pSliderUI->SetValue(86);
		}

		// ���List�б����ݣ�������Add(pListElement)��SetText
		CDuiString str;
		CListUI *pListUI = static_cast<CListUI*>(m_PaintManager.FindControl(_T("ListDemo1")));
		if (pListUI)
		{
			for (int i = 0; i < 100; ++i)
			{
				CListTextElementUI *pListElement = new CListTextElementUI();
				pListElement->SetTag(i);
				pListUI->Add(pListElement);

				str.Format(_T("%d"), i);
				pListElement->SetText(0, str);
				pListElement->SetText(1, _T("����"));
			}
		}
	}

	virtual void Notify(TNotifyUI& msg)
	{
		if (msg.sType == _T("selectchanged"))
		{
			CDuiString strName = msg.pSender->GetName();
			CTabLayoutUI *pTabLayoutUI = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tabTest")));
			if (pTabLayoutUI)
			{
				if (strName == _T("OptionDemo1"))
				{
					pTabLayoutUI->SelectItem(0);
				}
				else if (strName == _T("OptionDemo2"))
				{
					pTabLayoutUI->SelectItem(1);
				}
				else if (strName == _T("OptionDemo3"))
				{
					pTabLayoutUI->SelectItem(2);
				}
			}
		}

		__super::Notify(msg);
	}
};


int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	CPaintManagerUI::SetInstance(hInstance);
	// ��ʼ��COM����
	HRESULT hr = ::CoInitialize(0);
	if (FAILED(hr)) return 0;

	DuiFrameWnd *duiFrame = new DuiFrameWnd();
	duiFrame->Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame->CenterWindow();
	duiFrame->ShowModal();

	delete duiFrame;
	// �˳�COM����
	::CoUninitialize();
	return 0;
}