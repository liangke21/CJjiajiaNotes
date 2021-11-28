#include <iostream>
using namespace std;


struct Derived;

struct Base {
    friend struct Derived;
private:
    Base() {
        cout << "1" << endl;
    }
};

struct Derived : Base {

    Derived() {

        cout << "2" << endl;
    }
};



int main10010601() {

    Derived d1; // OK. ���漰�ۺϳ�ʼ����
    Derived d2{}; // OK in C++14: ��������::����()
                   // ���Ե��� Base ctor��

   // �������ֳ�ʼ����Ч
    cout << "3" << endl;
    return 0;
}