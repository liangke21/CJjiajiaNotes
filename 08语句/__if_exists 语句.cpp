// the__if_exists_statement.cpp
// compile with: /EHsc
#include <iostream>

template<typename T>
class X : public T {
public:
    void Dump() {
        std::cout << "In X<T>::Dump()" << std::endl;

        __if_exists(T::Dump) {  //标识符纯在执行语句
            T::Dump();
        }

        __if_not_exists(T::Dump) {  //表示符不纯在
            std::cout << "T::转储不存在" << std::endl;
        }
    }
};

class A {
public:
    void Dump() {
        std::cout << "In A::Dump()" << std::endl;
    }
};

class B {};

bool g_bFlag = true;

class C {
public:
    void f(int);
    void f(double);
};

int main060201() {
    X<A> x1;
    X<B> x2;

    x1.Dump();  //标识符纯在
    x2.Dump();  //标识符不纯在

    __if_exists(::g_bFlag) {  //有标识符
        std::cout << "g b 标志 = " << g_bFlag << std::endl;
    }

    __if_exists(C::f) { //有标识符
        std::cout << "C::f exists" << std::endl;
    }

    return 0;
}