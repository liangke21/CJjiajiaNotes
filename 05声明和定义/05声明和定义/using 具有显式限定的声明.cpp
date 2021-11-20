// using_declaration3.cpp
#include <stdio.h>
//����ʹ����ʽ�޶�������ʹ�� using ���������ĳ�Ա�� ::ǰ׺����ȫ�������ռ䡣
void f() {
    printf_s("In f\n");
}

namespace A {
    void g() {
        printf_s("In A::g\n");
    }
}

namespace X {
    using ::f;   //ȫ�� f Ҳ�ɼ�Ϊ X::f
    using A::g;   // A �� g ������ʾΪ X::g
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