
// PPPDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CPPPDlg �Ի���
class CPPPDlg : public CDialogEx
{
// ����
public:
	CPPPDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo1;
	CComboBox m_hour;
	CComboBox m_minute;
	CComboBox m_sec;
	CComboBox m_X;
	CEdit m_Y;
	CEdit m_Z;
	afx_msg void OnBnClickedComputeButton1();
};
