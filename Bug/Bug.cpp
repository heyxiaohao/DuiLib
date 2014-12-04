/*
�˹��� �����󻯺� �м�İ�ťû�б�� ��ԭ��ť
��Ҫ��WindowImplBase��OnSysCommand�������if( ::IsZoomed(*this) != bZoomed )������ϴ���
if( ::IsZoomed(*this) != bZoomed )
{
	CControlUI* pbtnMax     = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("maxbtn")));       // ��󻯰�ť
	CControlUI* pbtnRestore = static_cast<CControlUI*>(m_PaintManager.FindControl(_T("restorebtn")));   // ��ԭ��ť

	// �л���󻯰�ť�ͻ�ԭ��ť��״̬
	if (pbtnMax && pbtnRestore)
	{
	pbtnMax->SetVisible(TRUE == bZoomed);       // �˴��ñ��ʽ��Ϊ�˱��������BOOLת���ľ���
	pbtnRestore->SetVisible(FALSE == bZoomed);
	}
}

ע��Ҫ���±��붯̬��

CDuiString��Bug�� ��������ǰ�� ���Ƚ� ����Ϊfalse  ��ΪCDuiStringû�����ش���==���������Ƽ�ʹ��std::string

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