

/*
当在类模板外定义模板的成员函数时，
可以使用不同的模板参数名称。 
如果模板成员函数定义与声明对模板参数使用了不同的名称，


//总点::并且定义中使用的名称与声明的其他成员冲突，则模板声明中的成员优先。
*/

#include <iostream>
using namespace std;

template <class T> class C {
public:
    struct Z {
        Z() { cout << "Z::Z()" << endl; }
    };
    void f();
};

template <class Z>
void C<Z>::f() {
// Z 指的是结构 Z，而不是模板 arg；
    // 因此，将调用 struct Z 的构造函数。
    Z z;
}

int main22060301() {
    C<int> c;
    c.f();

    return 0;
}