
/*
模板可以在类或类模板中定义，在这种情况下，它们被称为成员模板。 作为类的成员模板称为嵌套类模板。 成员 函数模板中讨论了作为函数的成员模板。

嵌套类模板被声明为外部类范围内的类模板。 可以在封闭类的内部或外部定义它们。

下面的代码演示普通类中的嵌套类模板。
*/

//#include <iostream>
//using namespace std;
//
//class X
//{
//
//    template <class T>
//    struct Y
//    {
//        T m_t;
//        Y(T t) : m_t(t) { }
//    };
//
//    Y<int> yInt;
//    Y<char> yChar;
//
//public:
//    X(int i, char c) : yInt(i), yChar(c) { }
//    void print()
//    {
//        cout << yInt.m_t << " " << yChar.m_t << endl;
//    }
//};
//
//int main22030201()
//{
//    X x(1, 'a');
//    x.print();
//
//    return 0;
//}

//

// nested_class_template2.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

template <class T>
class X
{
    template <class U> class Y
    {
        U* u;
    public:
        Y();
        U& Value();
        void print();
        ~Y();
    };

    Y<int> y;
public:
    X(T t) { y.Value() = t; }
    void print() { y.print(); }
};

template <class T>
template <class U>
X<T>::Y<U>::Y()
{
    cout << "X<T>::Y<U>::Y()" << endl;
    u = new U();
}

template <class T>
template <class U>
U& X<T>::Y<U>::Value()
{
    return *u;
}

template <class T>
template <class U>
void X<T>::Y<U>::print()
{
    cout << this->Value() << endl;
}


template <class T> template <class U>
X<T>::Y<U>::~Y()
{
    cout << "X<T>::Y<U>::~Y()" << endl;
    delete u;
}

int main22030202()
{
    X<int>* xi = new X<int>(10);
    X<char>* xc = new X<char>('c');
    xi->print();
    xc->print();
    delete xi;
    delete xc;
    return 0;
}

//Output:
//X<T>::Y<U>::Y()
//X<T>::Y<U>::Y()
//10
//99
//X<T>::Y<U>::~Y()
//X<T>::Y<U>::~Y()