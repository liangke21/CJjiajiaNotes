// functions_in_namespaces2.cpp
// C2668 expected
namespace B {
    void f(int);
    void f(double);
}

namespace C {
    void f(int);
    void f(double);
    void f(char);
}


void h2() {
    using B::f;          // introduces B::f(int) and B::f(double)
    using C::f;          // C::f(int), C::f(double), and C::f(char)
   // f('h');              // calls C::f(char)  //无法解析
   // f(1);                // C2668 ambiguous: B::f(int) or C::f(int)?  // 对重载函数的调用不明确
   // void f(int);         // C2883 conflicts with B::f(int) and C::f(int) //声明冲突

}

int main99999()
{
    return 0;
}