

//�����Ӷ��������������ô�������������������г���˳����û��๹�캯����

#include <iostream>
using namespace std;

class BaseClass1 {
public:
    BaseClass1() { cout << "���� 1 ctor\n"; }
};
class BaseClass2 {
public:
    BaseClass2() { cout << "���� 2 ctor\n"; }
};
class BaseClass3 {
public:
    BaseClass3() { cout << "����3 ctor\n"; }
};
class DerivedClass : public BaseClass1,
    public BaseClass2,
    public BaseClass3
{
public:
    DerivedClass() { cout << "�����๹�캯��\n"; }
};

int main10010701() {
    DerivedClass dc;
    /*
    ���� 1 ctor
    ���� 2 ctor
    ����3 ctor
    �����๹�캯��
    */

    return 0;
}