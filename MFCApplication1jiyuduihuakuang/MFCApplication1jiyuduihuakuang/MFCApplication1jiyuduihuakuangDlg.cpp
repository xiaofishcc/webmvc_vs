
// MFCApplication1jiyuduihuakuangDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCApplication1jiyuduihuakuang.h"
#include "MFCApplication1jiyuduihuakuangDlg.h"
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
public:
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


// CMFCApplication1jiyuduihuakuangDlg 对话框



CMFCApplication1jiyuduihuakuangDlg::CMFCApplication1jiyuduihuakuangDlg(CWnd* pParent /*=NULL*/)//通过类向导生成的自定义变量或者控件的关联变量都会在构造函数中初始化一个值，开发者可以直接在头文件定义变量，并手动在构造函数中添加初始化语句
//所以，构造函数是个赋初值的好地方
	: CDialogEx(CMFCApplication1jiyuduihuakuangDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1jiyuduihuakuangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_Enable, m_Enable);
	DDX_Control(pDX, IDC_Exit, m_Exit);
	//  DDX_Control(pDX, IDC_Delete, m_Delete);
	DDX_Control(pDX, IDC_Toast, m_toast);
	DDX_Control(pDX, IDC_Wangyi, m_Wangyi);
	DDX_Control(pDX, IDC_Toast2, m_toast2);
}
//消息映射，定义乐峰所有消息的来源和处理函数
BEGIN_MESSAGE_MAP(CMFCApplication1jiyuduihuakuangDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	/*ON_WM_CLOSE()*/
	//ON_BN_CLICKED(IDC_Enable, &CMFCApplication1jiyuduihuakuangDlg::OnClickedEnable)
	//ON_BN_CLICKED(IDC_Exit, &CMFCApplication1jiyuduihuakuangDlg::OnBnClickedExit)
	////ON_BN_CLICKED(IDC_Delete, &CMFCApplication1jiyuduihuakuangDlg::m_Delete)
	//ON_BN_CLICKED(IDC_LinkBaidu, &CMFCApplication1jiyuduihuakuangDlg::OnStnClickedLinkbaidu)
	//ON_BN_CLICKED(IDC_LinkHao123, &CMFCApplication1jiyuduihuakuangDlg::OnStnClickedLinkhao123)

	//ON_STN_CLICKED(IDC_Toast, &CMFCApplication1jiyuduihuakuangDlg::OnStnClickedToast)
	//ON_STN_CLICKED(IDC_Wangyi, &CMFCApplication1jiyuduihuakuangDlg::OnStnClickedWangyi)
	
	ON_CONTROL_RANGE(BN_CLICKED, IDC_BUTTON1, IDC_BUTTON4, OnBnClickedXXX)
	ON_STN_CLICKED(IDC_Toast2, &CMFCApplication1jiyuduihuakuangDlg::OnStnClickedToast2)

END_MESSAGE_MAP()

// CMFCApplication1jiyuduihuakuangDlg 消息处理程序

BOOL CMFCApplication1jiyuduihuakuangDlg::OnInitDialog()
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
	m_Exit.EnableWindow(false);//使“退出”按钮不可用
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1jiyuduihuakuangDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1jiyuduihuakuangDlg::OnPaint()//绘制窗口和图标
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;//存储窗口大小的结构体
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
HCURSOR CMFCApplication1jiyuduihuakuangDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAboutDlg::OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/)
{
	// TODO:  在此处添加消息处理程序代码
}



void CMFCApplication1jiyuduihuakuangDlg::OnClickedEnable()
{
	// TODO:  在此添加控件通知处理程序代码
	CString str;
	m_Enable.GetWindowTextW(str);
	if (str == "使能"){
		m_Exit.EnableWindow(true);
		m_Enable.SetWindowTextW(_T("不使能"));
	}
	else
	{
		m_Exit.EnableWindow(false);
		m_Enable.SetWindowTextW(_T("使能"));
	}
}


void CMFCApplication1jiyuduihuakuangDlg::OnBnClickedExit()
{
	// TODO:  在此添加控件通知处理程序代码
	SendMessage(WM_CLOSE, 0, 0);
}


//void CMFCApplication1jiyuduihuakuangDlg::OnBnClickedDelete()
//{
//	// TODO:  在此添加控件通知处理程序代码
//}


void CMFCApplication1jiyuduihuakuangDlg::OnStnClickedLinkbaidu()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(0, NULL, _T("http://www.baidu.com"), NULL, NULL, SW_NORMAL);
	GetDlgItem(IDC_LinkBaidu)->SetWindowTextW(_T("你好百度"));
	m_toast.SetWindowTextW(_T("已打开百度网页！"));
}


void CMFCApplication1jiyuduihuakuangDlg::OnStnClickedLinkhao123()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(0, NULL, _T("http://www.hao123.com"), NULL, NULL, SW_NORMAL);
	GetDlgItem(IDC_LinkHao123)->SetWindowTextW(_T("你好hao123"));
	m_toast.SetWindowTextW(_T("已打开hao123网页！"));
}



void CMFCApplication1jiyuduihuakuangDlg::OnStnClickedToast()
{
	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication1jiyuduihuakuangDlg::OnStnClickedWangyi()
{
	// TODO:  在此添加控件通知处理程序代码
	ShellExecute(0, NULL, _T("http://http://www.163.com/"), NULL, NULL, SW_NORMAL);
	GetDlgItem(IDC_Wangyi)->SetWindowTextW(_T("你好163"));
	m_toast.SetWindowTextW(_T("已打开163网页！"));
}
void CMFCApplication1jiyuduihuakuangDlg::OnBnClickedXXX(UINT nID)
{
	int ID = nID - IDC_BUTTON1;
	CString str;
	str.Format(_T("%s%i%s"), _T("按钮"), ID + 1, _T("按下！"));
	m_toast2.SetWindowTextW(str);
	//注释掉的和前面三行代码的作用一样
	//switch (ID)
	//{
	//case 0:m_toast2.SetWindowTextW(_T("按钮1按下！")); break;
	//case 1:m_toast2.SetWindowTextW(_T("按钮2按下！")); break;
	//case 2:m_toast2.SetWindowTextW(_T("按钮3按下！")); break;
	//case 3:m_toast2.SetWindowTextW(_T("按钮4按下！")); break;
	//}
}

void CMFCApplication1jiyuduihuakuangDlg::OnStnClickedToast2()
{
	// TODO:  在此添加控件通知处理程序代码
}
