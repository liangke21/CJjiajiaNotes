// the__if_exists_statement.cpp
// compile with: /EHsc
#include <iostream>

template<typename T>
class X : public T {
public:
    void Dump() {
        std::cout << "In X<T>::Dump()" << std::endl;

        __if_exists(T::Dump) {  //��ʶ������ִ�����
            T::Dump();
        }

        __if_not_exists(T::Dump) {  //��ʾ��������
            std::cout << "T::ת��������" << std::endl;
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

    x1.Dump();  //��ʶ������
    x2.Dump();  //��ʶ��������

    __if_exists(::g_bFlag) {  //�б�ʶ��
        std::cout << "g b ��־ = " << g_bFlag << std::endl;
    }

    __if_exists(C::f) { //�б�ʶ��
        std::cout << "C::f exists" << std::endl;
    }

    return 0;
}