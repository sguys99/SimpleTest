﻿
// SimpleTestDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "SimpleTest.h"
#include "SimpleTestDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSimpleTestDlg 대화 상자



CSimpleTestDlg::CSimpleTestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SIMPLETEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSimpleTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_event_list);
	DDX_Control(pDX, IDC_EDIT, m_edit_out);
}

BEGIN_MESSAGE_MAP(CSimpleTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MSG_BTN, &CSimpleTestDlg::OnBnClickedMsgBtn)
	ON_BN_CLICKED(IDC_RESET_BTN, &CSimpleTestDlg::OnBnClickedResetBtn)
	ON_BN_CLICKED(IDC_CNT_BTN, &CSimpleTestDlg::OnBnClickedCntBtn)
END_MESSAGE_MAP()


// CSimpleTestDlg 메시지 처리기

BOOL CSimpleTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_nBtnClickCounter = 0;
	m_edit_out.SetWindowTextW(_T("0"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSimpleTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSimpleTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSimpleTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSimpleTestDlg::OnBnClickedMsgBtn()
{
	//AfxMessageBox(_T("Button clicked!"));
	m_nBtnClickCounter++;

	CString csMsg;
	csMsg.Format(_T("Button clicked!! #%02d"), m_nBtnClickCounter);
	
	int index = m_event_list.InsertString(-1, csMsg);
	m_event_list.SetCurSel(index);
}


void CSimpleTestDlg::OnBnClickedResetBtn()
{
	int nCount = m_event_list.GetCount();
	CString csMsg;

	if (IDYES == AfxMessageBox(_T("Clear contents?"), MB_YESNO))
	{
		csMsg.Format(_T("Number of contents removed : %02d"), nCount);
		m_event_list.ResetContent();

		AfxMessageBox(csMsg);

		m_nBtnClickCounter = 0;
	}
}

int CSimpleTestDlg::AddNumbers(int n)
{
	return n * (n + 1) / 2;
}

void CSimpleTestDlg::OnBnClickedCntBtn()
{
	CString strTmp;

	strTmp.Format(_T("%d"), m_nBtnClickCounter);
	m_edit_out.SetWindowTextW(strTmp);
}

int CSimpleTestDlg::CalcSum(int a, int b)
{
	return a + b;
}

int CSimpleTestDlg::CalcSub(int a, int b)
{
	return a - b;
}

int CSimpleTestDlg::CalcMul(int a, int b)
{
	return a * b;
}

int CSimpleTestDlg::CalcDiv(int a, int b)
{
	return int(a / b);
}
