
// SimpleTestDlg.h: 헤더 파일
//

#pragma once


// CSimpleTestDlg 대화 상자
class CSimpleTestDlg : public CDialogEx
{
// 생성입니다.
public:
	CSimpleTestDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	int m_nBtnClickCounter;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SIMPLETEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedMsgBtn();
	CListBox m_event_list;
	afx_msg void OnBnClickedResetBtn();

	int AddNumbers(int n);
	CEdit m_edit_out;
	afx_msg void OnBnClickedCntBtn();
	int CalcSum(int a, int b);
	int CalcSub(int a, int b);
	int CalcMul(int a, int b);
	int CalcDiv(int a, int b);
	int CalcPow(int a, int b);

	int MulAll(int n);
	int AddAll(int n);
};
