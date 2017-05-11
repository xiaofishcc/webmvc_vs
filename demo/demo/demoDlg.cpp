
// demoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "demo.h"
#include "demoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CdemoDlg 对话框



CdemoDlg::CdemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CdemoDlg::IDD, pParent)
	, m_add1(0)
	, m_add2(0)
	, m_result(0)
	, m_plus(0)
	, m_use(false)
	, m_num1(0)
	, m_num2(0)
	, m_num3(0)
	, m_result1(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CdemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Algorithm, m_algorithm);
	DDX_Text(pDX, IDC_Add1, m_add1);
	DDX_Text(pDX, IDC_Add2, m_add2);
	DDX_Text(pDX, IDC_Result, m_result);
	DDX_Radio(pDX, IDC_Plus, m_plus);
	DDX_Radio(pDX, IDC_Use, m_use);
	DDX_Control(pDX, IDC_Pisa1, m_pisa1);
	DDX_Control(pDX, IDC_Pisa2, m_pisa2);
	DDX_Control(pDX, IDC_Pisa3, m_pisa3);
	DDX_Text(pDX, IDC_Num1, m_num1);
	DDX_Text(pDX, IDC_Num2, m_num2);
	DDX_Text(pDX, IDC_Num3, m_num3);
	DDX_Text(pDX, IDC_Result1, m_result1);
	DDX_Control(pDX, IDC_TimeDis, m_time);
}

BEGIN_MESSAGE_MAP(CdemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	/*ON_BN_CLICKED(IDC_CALC1, &CdemoDlg::OnBnClickedCalc1)
	ON_BN_CLICKED(IDC_Use, &CdemoDlg::OnBnClickedUse)
	ON_BN_CLICKED(IDC_NUse, &CdemoDlg::OnBnClickedNuse)*/
	//ON_CONTROL_RANGE(BN_CLICKED,IDC_Plus,IDC_Div,OnBnClickedAlgor)//实现OnBnClickedAlgor函数
	ON_BN_CLICKED(IDC_BUTTON1, &CdemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_Timer, &CdemoDlg::OnBnClickedTimer)
	ON_BN_CLICKED(IDC_Reset, &CdemoDlg::OnBnClickedReset)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CdemoDlg 消息处理程序

BOOL CdemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	GetDlgItem(IDC_CALC1)->EnableWindow(false);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CdemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CdemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CdemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CdemoDlg::OnBnClickedCalc1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	switch (m_plus)
	{
	case 0:m_result = m_add1 + m_add2; break;
	case 1:m_result = m_add1 - m_add2; break;
	case 2:m_result = m_add1 * m_add2; break;
	case 3:m_result = m_add1 / m_add2; break;
	}
	UpdateData(false);
}




void CdemoDlg::OnBnClickedUse()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_CALC1)->EnableWindow(true);
}


void CdemoDlg::OnBnClickedNuse()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_CALC1)->EnableWindow(false);
}

void CdemoDlg::OnBnClickedAlgor(UINT nID)
{
	CString str;
	switch (nID - IDC_Plus)
	{
	case 0:str = _T("+"); break;
	case 1:str = _T("-"); break;
	case 2:str = _T("*"); break;
	case 3:str = _T("/"); break;
	}
	m_algorithm.SetWindowTextW(str);
}

void CdemoDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	m_result1 = 0;
	if (m_pisa1.GetCheck())
		m_result1 += m_num1 * 250;
	if (m_pisa2.GetCheck())
		m_result1 += m_num2* 275;
	if (m_pisa3.GetCheck())
		m_result1 += m_num3 * 350;
	UpdateData(false);
}


void CdemoDlg::OnBnClickedTimer()
{
	// TODO:  在此添加控件通知处理程序代码
	//SetTimer启动定时器
	SetTimer(1, 10, NULL);
}


void CdemoDlg::OnBnClickedReset()
{
	// TODO:  在此添加控件通知处理程序代码
	KillTimer(1);//销毁定时器KillTimer,同时将文本复位到00:00:00
	m_time.SetWindowTextW(_T("00:00:00"));
}


void CdemoDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	static UINT mm = 0;
	static UINT ss = 0;
	static UINT mss = 0;
	CString str;
	switch (nIDEvent)
	{
	case 1:
		mss++;
		if (mss == 100){ mss = 0; ss++; }
		if (ss==60)
		{
			ss = 0; mm++;
		}
		str.Format(_T("%02i:%02i:%02i"), mm, ss, mss);
		m_time.SetWindowTextW(str);
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}
