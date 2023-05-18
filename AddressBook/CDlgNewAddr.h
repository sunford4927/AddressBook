#pragma once


// CDlgNewAddr 대화 상자

class CDlgNewAddr : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNewAddr)

public:
	CDlgNewAddr(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgNewAddr();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW_ADDR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strname;
	CString m_strphone;
	afx_msg void OnEnChangeEditName();
};
