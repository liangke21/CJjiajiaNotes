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
//示例： using 类字段中的声明
class D : B {
public:
    using B::f;    // B::f(char) 现在显示为 D::f(char)
    using B::g;    // B::g(char) 现在显示为 D::g(char)
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
    myD.g('a'); //这里调用的是父类的

    return 0;
}

