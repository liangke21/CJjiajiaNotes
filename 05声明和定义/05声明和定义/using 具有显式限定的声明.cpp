// using_declaration3.cpp
#include <stdio.h>
//可以使用显式限定来引用使用 using 声明声明的成员。 ::前缀引用全局命名空间。
void f() {
    printf_s("In f\n");
}

namespace A {
    void g() {
        printf_s("In A::g\n");
    }
}

namespace X {
    using ::f;   //全局 f 也可见为 X::f
    using A::g;   // A 的 g 现在显示为 X::g
}

void h() {
    printf_s("In h\n");
    X::f();   // calls ::f
    X::g();   // calls A::g
}

int main999() {
    h();

    return 0;
}