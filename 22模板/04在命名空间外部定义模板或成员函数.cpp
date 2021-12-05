

#include <iostream>
using namespace std;

namespace NS {
    void g() { cout << "NS::g" << endl; }

    template <class T> struct C {
        void f();
        void g() { cout << "C<T>::g" << endl; }
    };
};

template <class T>
void NS::C<T>::f() {
    g(); // C<T>::g, not NS::g
};
//������ģ��������ռ��ⶨ��ģ�庯�����Ա����ʱ��ģ���Ա����������������ռ���������Ա�����ơ�
int main22060304() {
    NS::C<int> c;
    c.f();//C<T>::g

    return 0;
}