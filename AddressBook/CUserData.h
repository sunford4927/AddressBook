#pragma once
#include <afx.h>
class CUserData :
    public CObject
{
public:
    CUserData(CString name, CString phone) {
        m_strname = name;
        m_strphone = phone;
    }
    CUserData(const CUserData& rhs) {
        this->m_strname = rhs.m_strname;
        this->m_strphone = rhs.m_strphone;
    }

    CString GetName() { return m_strname; }
    CString GetPhone() { return m_strphone; }
private:
    CString m_strname;
    CString m_strphone;
};

