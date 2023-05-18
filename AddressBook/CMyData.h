#pragma once
#include <afx.h>
class CMyData : public CObject
{
public:
    CPtrList m_dataList;

    // 직렬화 함수들을 구현합니다.
    DECLARE_SERIAL(CMyData)
    void Serialize(CArchive& ar);
};

IMPLEMENT_SERIAL(CMyData, CObject, 1)

void CMyData::Serialize(CArchive& ar)
{
    if (ar.IsStoring())
    {
        // 리스트 저장
        ar << m_dataList.GetCount();
        POSITION pos = m_dataList.GetHeadPosition();
        while (pos)
        {
            CMyData* pObject = (CMyData*)m_dataList.GetNext(pos);
            pObject->Serialize(ar);
        }
    }
    else
    {
        // 리스트 불러오기
        int count;
        ar >> count;
        for (int i = 0; i < count; i++)
        {
            CMyData* pObject = new CMyData();
            pObject->Serialize(ar);
            m_dataList.AddTail(pObject);
        }
    }
}