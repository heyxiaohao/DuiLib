
// MFC��ʹ��duilib.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC��ʹ��duilibApp: 
// �йش����ʵ�֣������ MFC��ʹ��duilib.cpp
//

class CMFC��ʹ��duilibApp : public CWinApp
{
public:
	CMFC��ʹ��duilibApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC��ʹ��duilibApp theApp;