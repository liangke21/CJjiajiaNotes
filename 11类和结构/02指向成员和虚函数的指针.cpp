

/*ͨ��ָ���Ա������ָ������麯���Ĺ�����ʽ��ֱ�ӵ��ú�����ͬ�� �� v ���в��Ҳ���������ȷ�ĺ�����

һֱ�������麯�������Ĺؼ���ͨ��ָ������ָ������������*/




// virtual_functions.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Print();
};
void (Base::* bfnPrint)() = &Base::Print;

void Base::Print()
{
    cout << "Print function for class Base" << endl;
}

class Derived : public Base
{
public:
    void Print();  // ��ӡ��Ȼ��һ���麯����
};

void Derived::Print()
{
    cout << "Print function for class Derived" << endl;
}

int main190201()
{
    Base* bPtr;
    Base    bObject;
    Derived dObject;
    bPtr = &bObject;    // ����ָ�� b �����ַ��ָ�롣
    (bPtr->*bfnPrint)();//Print function for class Base

    bPtr = &dObject;    // ����ָ�� d �����ַ��ָ�롣
    (bPtr->*bfnPrint)();//Print function for class Derived
    return 0;
}

