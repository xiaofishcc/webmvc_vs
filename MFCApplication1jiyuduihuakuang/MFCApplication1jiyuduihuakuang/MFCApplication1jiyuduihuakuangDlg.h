
// MFCApplication1jiyuduihuakuangDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFCApplication1jiyuduihuakuangDlg 对话框
class CMFCApplication1jiyuduihuakuangDlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1jiyuduihuakuangDlg(CWnd* pParent = NULL);	// 标准构造函数//通过类向导生成的自定义变量或者控件的关联变量都会在构造函数中初始化一个值，开发者可以直接在头文件定义变量，并手动在构造函数中添加初始化语句
	//所以，构造函数是个赋初值的好地方

// 对话框数据
	enum { IDD = IDD_MFCAPPLICATION1JIYUDUIHUAKUANG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持//用于存放各类控件的变量信息


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();//初始化对话框
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();//绘制窗口和图标
	afx_msg HCURSOR OnQueryDragIcon();//返回光标
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedEnable();
	afx_msg void OnBnClickedExit();
	CButton m_Enable;
	CButton m_Exit;
	// 状态栏文本	链接相关网址
	CStatic m_toast;
	afx_msg void OnStnClickedLinkbaidu();
	afx_msg void OnStnClickedLinkhao123();
	CStatic m_Wangyi;
	afx_msg void OnStnClickedToast();
	afx_msg void OnStnClickedWangyi();
	afx_msg void OnClose();
	afx_msg void OnBnClickedXXX(UINT nID);//触发消息时对应的控件ID，响应函数
	CStatic m_toast2;
	afx_msg void OnStnClickedToast2();
	//计算器加法相关
	afx_msg void OnBnClickedCalc();
	double m_add1;
	double m_add2;
	double m_result;
	CEdit m_record;
	CString m_passWord;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnEnChangeStatus();
	afx_msg void OnEnChangePassword();
};
