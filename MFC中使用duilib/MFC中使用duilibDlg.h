
// MFC��ʹ��duilibDlg.h : ͷ�ļ�
//

#pragma once

#include "DuiFrameWnd.h"

// CMFC��ʹ��duilibDlg �Ի���
class CMFC��ʹ��duilibDlg : public CDialogEx
{
// ����
public:
	CMFC��ʹ��duilibDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MFCDUILIB_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	DuiFrameWnd m_duiFrame;
public:
	afx_msg void OnClose();
};
