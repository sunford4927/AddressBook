// CDlgNewAddr.cpp: 구현 파일
//

#include "pch.h"
#include "AddressBook.h"
#include "CDlgNewAddr.h"
#include "afxdialogex.h"


// CDlgNewAddr 대화 상자

IMPLEMENT_DYNAMIC(CDlgNewAddr, CDialogEx)

CDlgNewAddr::CDlgNewAddr(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NEW_ADDR, pParent)
	, m_strname(_T(""))
	, m_strphone(_T(""))
{
	
}

CDlgNewAddr::~CDlgNewAddr()
{
}

void CDlgNewAddr::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strname);
	DDX_Text(pDX, IDC_EDIT_PHONE, m_strphone);
}


BEGIN_MESSAGE_MAP(CDlgNewAddr, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_NAME, &CDlgNewAddr::OnEnChangeEditName)
END_MESSAGE_MAP()


// CDlgNewAddr 메시지 처리기


void CDlgNewAddr::OnEnChangeEditName()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
