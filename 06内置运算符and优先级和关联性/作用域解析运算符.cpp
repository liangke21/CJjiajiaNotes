//用于 :: 类和命名空间

#include <iostream>
namespace NamespaceA {
    int x;
    class ClassA {
    public:
        int x;
    };
}

int main291() {

    // 用于消除歧义的命名空间名称
    NamespaceA::x = 1;

    //用于消除歧义的类名
    NamespaceA::ClassA a1;
    a1.x = 2;

    return 0;
}
//没有范围限定符的范围解析运算符表示全局命名空间。
namespace NamespaceB {
    int x;
}

int x;

int main292() {
    int x;

    // main() 中的 x
    x = 0;
    // 全局命名空间中的 x
    ::x = 1;

    // A 命名空间中的 x
    NamespaceB::x = 2;

    return 0;
}
/*
可以使用范围解析运算符标识的成员 namespace ，
或标识在指令中 nominates 成员的命名空间的命名空间 using 。 
在下面的示例中，你可以使用 NamespaceC 来限定 ClassB ，
即使 ClassB 是在命名空间中声明的， 
NamespaceB 因为 NamespaceB 是 NamespaceC 由指令在中命名的 using 。
*/
namespace NamespaceD {
 
    class ClassB {
    public:
        int x;
    };
}

namespace NamespaceC {
    using namespace NamespaceD;
}

int main293() {
    NamespaceD::ClassB b_b;
    NamespaceC::ClassB c_b;

    b_b.x = 3;
    c_b.x = 4;
    return 0;
}
/*
可使用范围解析运算符链。 
在以下示例中，NamespaceD::NamespaceD1 将标识嵌套的命名空间 NamespaceD1，
并且 NamespaceE::ClassE::ClassE1 将标识嵌套的类 ClassE1。
*/
namespace NamespaceD {
    namespace NamespaceD1 {
        int x;
    }
}

namespace NamespaceE {
    class ClassE {
    public:
        class ClassE1 {
        public:
            int x;
        };
    };
}

int main294() {
    NamespaceD::NamespaceD1::x = 6;
    NamespaceE::ClassE::ClassE1 e1;
    e1.x = 7;
    return 0;
}
