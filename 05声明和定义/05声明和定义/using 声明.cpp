// using_declaration1.cpp
#include <stdio.h>
class B {
public:
    void f(char) {
        printf_s("In B::f()\n");
    }

    void g(char) {
        printf_s("In B::g()\n");
    }
};
//ʾ���� using ���ֶ��е�����
class D : B {
public:
    using B::f;    // B::f(char) ������ʾΪ D::f(char)
    using B::g;    // B::g(char) ������ʾΪ D::g(char)
    void f(int) {
        printf_s("In D::f()\n");
        f('c');     // Invokes B::f(char) instead of recursing
    }

    void g(int) {
        printf_s("In D::g()\n");
        g('c');     // Invokes B::g(char) instead of recursing
    }
};

int main9() {
    D myD;
    myD.f(1);
    myD.g('a'); //������õ��Ǹ����

    return 0;
}

