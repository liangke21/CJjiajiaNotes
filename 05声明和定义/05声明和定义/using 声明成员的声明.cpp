// using_declaration2.cpp


#include <stdio.h>
//当用于声明成员时，using 声明必须引用基类的成员。
class B {
public:
    void f(char) {
        printf_s("In B::f()\n");
    }

    void g(char) {
        printf_s("In B::g()\n");
    }
};

class C {
public:
    int g();
};

class D2 : public B {
public:
    using B::f;   // ok: B is a base of D2
    // using C::g;   // error: C isn't a base of D2
};

int main99() {
    D2 MyD2;
    MyD2.f('a');

    return 0;
}