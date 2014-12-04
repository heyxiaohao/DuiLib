/*
复杂的控件都需要初始化  初始化函数InitWindow
UI设计器里面的Name属性不能使默认的名字，否则不会写入xml中
*/

#include <UIlib.h>
using namespace DuiLib;

class DuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder() { return _T("../复杂控件"); }

	virtual void InitWindow()
	{
		CActiveXUI *pActiveXUI = static_cast<CActiveXUI*>(m_PaintManager.FindControl(_T("ActiveXDemo1")));
		if (pActiveXUI)
		{
			IWebBrowser2 *pWebBrowser = NULL;
			pActiveXUI->SetDelayCreate(false); // 相当于界面设计器的DelayCreate
			pActiveXUI->CreateControl(CLSID_WebBrowser); // 相当于界面设计器里的CLSID设置值
			pActiveXUI->GetControl(IID_IWebBrowser2, (void **)&pWebBrowser);
			if (pWebBrowser != NULL)
			{
				pWebBrowser->Navigate(L"http://www.baidu.com", NULL, NULL, NULL, NULL);
				pWebBrowser->Release();
			}
		}

		// 改变进度条的位置
		CProgressUI *pProgressUI = static_cast<CProgressUI*>(m_PaintManager.FindControl(_T("ProgressDemo1")));
		if (pProgressUI)
		{
			pProgressUI->SetValue(86);
		}

		// 改变滑动条的位置
		CSliderUI *pSliderUI = static_cast<CSliderUI*>(m_PaintManager.FindControl(_T("SliderDemo1")));
		if (pSliderUI)
		{
			pSliderUI->SetValue(86);
		}

		// 添加List列表内容，必须先Add(pListElement)再SetText
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
				pListElement->SetText(1, _T("哈哈"));
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
	// 初始化COM服务
	HRESULT hr = ::CoInitialize(0);
	if (FAILED(hr)) return 0;

	DuiFrameWnd *duiFrame = new DuiFrameWnd();
	duiFrame->Create(NULL, _T("DUIWnd"), UI_WNDSTYLE_FRAME, WS_EX_WINDOWEDGE);
	duiFrame->CenterWindow();
	duiFrame->ShowModal();

	delete duiFrame;
	// 退出COM服务
	::CoUninitialize();
	return 0;
}