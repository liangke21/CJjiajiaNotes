// using_declaration_inheritance1.cpp
#include <stdio.h>
struct B {
    virtual void f(int) {
        printf_s("In B::f(int)\n");
    }

    virtual void f(char) {
        printf_s("In B::f(char)\n");
    }

    void g(int) {
        printf_s("In B::g\n");
    }

    void h(int);
};

struct D : B {
    using B::f;
    void f(int) {   // ok: D::f(int) overrides B::f(int)
        printf_s("In D::f(int)\n");
    }

    using B::g;
    void g(char) {   // ok: there is no B::g(char)
        printf_s("In D::g(char)\n");
    }

    using B::h;
    void h(int) {}   // Note: D::h(int) hides non-virtual B::h(int)
};

void f(D* pd) {  //这里D和B一定要啥继承关系
    pd->f(1);     // calls D::f(int)
    pd->f('a');   // calls B::f(char)
    pd->g(1);     // calls B::g(int)
    pd->g('a');   // calls D::g(char)
}

int main96() {
    D* myd = new D();
    f(myd);

    return 0;
}