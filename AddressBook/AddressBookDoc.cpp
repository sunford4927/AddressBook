
// AddressBookDoc.cpp: CAddressBookDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "AddressBook.h"
#endif

#include "AddressBookDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CAddressBookDoc

IMPLEMENT_DYNCREATE(CAddressBookDoc, CDocument)

BEGIN_MESSAGE_MAP(CAddressBookDoc, CDocument)
	ON_COMMAND(ID_FILE_SAVE, &CAddressBookDoc::OnFileSave)
END_MESSAGE_MAP()


// CAddressBookDoc 생성/소멸

CAddressBookDoc::CAddressBookDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CAddressBookDoc::~CAddressBookDoc()
{
}

BOOL CAddressBookDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CAddressBookDoc serialization

void CAddressBookDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CAddressBookDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CAddressBookDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CAddressBookDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CAddressBookDoc 진단

#ifdef _DEBUG
void CAddressBookDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAddressBookDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CAddressBookDoc 명령


int CAddressBookDoc::NewAddr(CString name, CString phone)
{
	// TODO: 여기에 구현 코드 추가.
	CUserData * pNew = new CUserData(name, phone);
	m_ptrList.AddTail(pNew);
	return 0;
}


void CAddressBookDoc::ReleaseList()
{
	POSITION pos = m_ptrList.GetHeadPosition();
	while (pos != NULL) {
		CUserData* pNode = (CUserData*)m_ptrList.GetNext(pos);

		OutputDebugString(pNode->GetName() + _T("------------------------------\n"));// 디버깅 메시지 출력
		delete pNode;
	}
}

CUserData CAddressBookDoc::FindUser(CString name)
{
	POSITION pos = m_ptrList.GetHeadPosition();
	while (pos != NULL) {
		CUserData* pNode = (CUserData*)m_ptrList.GetNext(pos);
		if (pNode->GetName() == name)
		{
			return *pNode;
		}
		
	}
	return CUserData(_T(""), _T(""));
}






void CAddressBookDoc::OnFileSave()
{
	CString path;
	CFileDialog dlg(false);
	if (dlg.DoModal() == IDOK)
	{
		path = dlg.GetPathName();
		AfxMessageBox(path);
	}
	else { return; }
	CFile file;
	CArchive ar(&file, CArchive::store); // 저장모드로 설정
	file.Open(path, CFile::modeCreate | CFile::modeWrite | CFile::modeNoTruncate, NULL);
	
	int a, b, c;

}

//void SaveDataToFile(const CString& filePath, CUserData& data)
//{
//	CFile file;
//	if (file.Open(filePath, CFile::modeCreate | CFile::modeWrite))
//	{
//		CArchive ar(&file, CArchive::store);
//		data.Serialize(ar);
//		ar.Close();
//		file.Close();
//	}
//}
//
//void LoadDataFromFile(const CString& filePath, CUserData& data)
//{
//	CFile file;
//	if (file.Open(filePath, CFile::modeRead))
//	{
//		CArchive ar(&file, CArchive::load);
//		data.Serialize(ar);
//		ar.Close();
//		file.Close();
//	}
//}