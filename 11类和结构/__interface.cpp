
/*
���԰�������ʾ���� Microsoft c + + �ӿڣ�

�ɴ�����������ӿڼ̳С�

���ܴӻ���̳С�

ֻ�ܰ��������Ĵ��鷽����

���ܰ������캯���������������������

���ܰ�����̬������

���ܰ������ݳ�Ա������ʹ�����ԡ�

*/


//#define _ATL_ATTRIBUTES 1
//#include <atlbase.h>
//#include <atlcom.h>
//#include <string.h>
//#include <comdef.h>
//#include <stdio.h>
//
//[module(name = "test")];
//
//[object, uuid("00000000-0000-0000-0000-000000000001"), library_block]
//__interface IFace {
//    [id(0)] int int_data;
//    [id(5)] BSTR bstr_data;
//};
//
//[coclass, uuid("00000000-0000-0000-0000-000000000002")]
//class MyClass : public IFace {
//private:
//    int m_i;
//    BSTR m_bstr;
//
//public:
//    MyClass()
//    {
//        m_i = 0;
//        m_bstr = 0;
//    }
//
//    ~MyClass()
//    {
//        if (m_bstr)
//            ::SysFreeString(m_bstr);
//    }
//
//    int get_int_data()
//    {
//        return m_i;
//    }
//
//    void put_int_data(int _i)
//    {
//        m_i = _i;
//    }
//
//    BSTR get_bstr_data()
//    {
//        BSTR bstr = ::SysAllocString(m_bstr);
//        return bstr;
//    }
//
//    void put_bstr_data(BSTR bstr)
//    {
//        if (m_bstr)
//            ::SysFreeString(m_bstr);
//        m_bstr = ::SysAllocString(bstr);
//    }
//};
//
//int main()
//{
//    _bstr_t bstr("Testing");
//    CoInitialize(NULL);
//    CComObject<MyClass>* p;
//    CComObject<MyClass>::CreateInstance(&p);
//    p->int_data = 100;
//    printf_s("p->int_data = %d\n", p->int_data);
//    p->bstr_data = bstr;
//    printf_s("bstr_data = %S\n", p->bstr_data);
//}