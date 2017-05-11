
// demoDlg.h : 头文件
//

#pragma once
#include "afxwin.h"

#define WM_MYMSG WM_USER+1//自定义消息，ID要比WM_USER大

// CdemoDlg 对话框
class CdemoDlg : public CDialogEx
{
// 构造
public:
	CdemoDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DEMO_DIALOG };

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
	afx_msg LRESULT OnMyMsgHandler(WPARAM, LPARAM);//添加函数声明，用于响应自定义消息
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeAdd2();
	CStatic m_algorithm;
	afx_msg void OnBnClickedCalc1();
	afx_msg void OnEnChangeAdd1();
	afx_msg void OnBnClickedUse();
	afx_msg void OnBnClickedNuse();
	//单个函数处理多个事件
	afx_msg void OnBnClickedAlgor(UINT nID);
	double m_add1;
	double m_add2;
	double m_result;
	int m_plus;
	BOOL m_use;
	CButton m_pisa1;
	CButton m_pisa2;
	CButton m_pisa3;
	UINT m_num1;
	UINT m_num2;
	UINT m_num3;
	afx_msg void OnBnClickedButton1();
	double m_result1;
	CStatic m_time;
	afx_msg void OnBnClickedTimer();
	afx_msg void OnBnClickedReset();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedClick();
	CButton m_autoStart;
	afx_msg void OnBnClickedAutostart();
	CComboBox m_com1;
	double m_result2;
	afx_msg void OnBnClickedCalc();
	CComboBox m_algor;
	CString m_com2;
	CComboBox m_com2Control;
};
