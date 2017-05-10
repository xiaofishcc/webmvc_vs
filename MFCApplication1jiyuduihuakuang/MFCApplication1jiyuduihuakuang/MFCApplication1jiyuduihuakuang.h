
// MFCApplication1jiyuduihuakuang.h : PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号


// CMFCApplication1jiyuduihuakuangApp: 
// 有关此类的实现，请参阅 MFCApplication1jiyuduihuakuang.cpp
//

class CMFCApplication1jiyuduihuakuangApp : public CWinApp
{
public:
	CMFCApplication1jiyuduihuakuangApp();

// 重写
public:
	virtual BOOL InitInstance();

// 实现

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication1jiyuduihuakuangApp theApp;//项目生成后，都会生成一个属于CMFCApplication1jiyuduihuakuangApp类的theApp对象