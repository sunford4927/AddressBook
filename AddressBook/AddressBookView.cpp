
// AddressBookView.cpp: CAddressBookView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "AddressBook.h"
#endif

#include "AddressBookDoc.h"
#include "AddressBookView.h"
#include "CDlgNewAddr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAddressBookView

IMPLEMENT_DYNCREATE(CAddressBookView, CView)

BEGIN_MESSAGE_MAP(CAddressBookView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_NEW_ADDR, &CAddressBookView::OnNewAddr) // 조건에 따른 호출 선언
	ON_COMMAND(ID_SEARCH, &CAddressBookView::OnSearch)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// CAddressBookView 생성/소멸

CAddressBookView::CAddressBookView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CAddressBookView::~CAddressBookView()
{
	GetDocument()->ReleaseList();
}

BOOL CAddressBookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CAddressBookView 그리기

void CAddressBookView::OnDraw(CDC* /*pDC*/)
{
	CAddressBookDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CAddressBookView 인쇄

BOOL CAddressBookView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CAddressBookView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CAddressBookView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CAddressBookView 진단

#ifdef _DEBUG
void CAddressBookView::AssertValid() const
{
	CView::AssertValid();
}

void CAddressBookView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAddressBookDoc* CAddressBookView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAddressBookDoc)));
	return (CAddressBookDoc*)m_pDocument;
}
#endif //_DEBUG


// CAddressBookView 메시지 처리기


int CAddressBookView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	// ListBox 윈도우 생성
	m_wndList.Create(WS_CHILD | WS_VISIBLE | LBS_STANDARD | WS_HSCROLL | WS_TABSTOP ,
	CRect(0, 0, 300, 400), this, 1234);

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	//for (int i = 0; i < 10; i++)
	//{
	//	m_wndList.AddString(_T("TSET STRING"));
	//}
	return 0;
}


void CAddressBookView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_wndList.MoveWindow((cx / 2)/2, (cy / 2)/2, cx/2, cy/2);
}


void CAddressBookView::OnNewAddr()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDlgNewAddr dlg;
	if (dlg.DoModal() == IDOK)
	{
		//m_wndList.AddString(dlg.m_strname + _T('[') + dlg.m_strphone + _T(']'));
		m_wndList.AddString(dlg.m_strname);
		GetDocument()->NewAddr(dlg.m_strname, dlg.m_strphone);
	}
	
}


void CAddressBookView::OnSearch()
{
	CDlgNewAddr dlg;
	if (dlg.DoModal() == IDOK)
	{
		//m_wndList.AddString(dlg.m_strname + _T('[') + dlg.m_strphone + _T(']'));
		CUserData user = GetDocument()->FindUser(dlg.m_strname);
		if (user.GetName().IsEmpty())
		{
			AfxMessageBox(_T("Not Found"));
		}
		else
		{
			AfxMessageBox(user.GetName() + _T(" ") + user.GetPhone());
		}
	}
}


void CAddressBookView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int clickindex = m_wndList.GetCurSel();
	CString str;
	m_wndList.GetText(clickindex,str);

	
	CView::OnLButtonDblClk(nFlags, point);
}




