
/*
�ɶ���Ĭ����ʽ����Button ���û��ָ�����ԣ���ʹ��Ĭ������
��<Window>�ڵ����һ��Default�ڵ㼴�ɣ�����
name������д�ؼ������֣�
value������ӿؼ������Ե�ֵ����Ҫ��˫���š�"�����ɡ�&quot;���������š�'�����ɡ�&apos;��,������Ҳ���Բ�ת����
*/

#include <UIlib.h>
using namespace DuiLib;

class DuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder() { return _T("../�򵥿ؼ�"); }
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