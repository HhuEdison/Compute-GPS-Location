
// PPPDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CPPPDlg 对话框
class CPPPDlg : public CDialogEx
{
// 构造
public:
	CPPPDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_PPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
