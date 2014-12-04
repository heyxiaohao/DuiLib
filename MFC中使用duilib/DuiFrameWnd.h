#ifndef __DUI_FRAMEWND_H__
#define __DUI_FRAMEWND_H__

#include <UIlib.h>
using namespace DuiLib;

class DuiFrameWnd : public WindowImplBase
{
public:
	virtual LPCTSTR GetWindowClassName() const { return _T("DUIMainFrame"); }
	virtual CDuiString GetSkinFile() { return _T("duilib.xml"); }
	virtual CDuiString GetSkinFolder() { return _T("../MFC÷– π”√duilib"); }
};

#endif // __DUI_FRAMEWND_H__