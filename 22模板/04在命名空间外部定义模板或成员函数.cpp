

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
//在声明模板的命名空间外定义模板函数或成员函数时，模板自变量将优先于命名空间中其他成员的名称。
int main22060304() {
    NS::C<int> c;
    c.f();//C<T>::g

    return 0;
}