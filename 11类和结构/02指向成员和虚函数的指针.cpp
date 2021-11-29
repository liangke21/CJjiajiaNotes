

/*通过指向成员函数的指针调用虚函数的工作方式与直接调用函数相同。 在 v 表中查找并调用了正确的函数。

一直以来，虚函数工作的关键是通过指向基类的指针来调用它们*/




// virtual_functions.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

class Base
{
public:
    virtual void Print();
};
void (Base::* bfnPrint)() = &Base::Print;

void Base::Print()
{
    cout << "Print function for class Base" << endl;
}

class Derived : public Base
{
public:
    void Print();  // 打印仍然是一个虚函数。
};

void Derived::Print()
{
    cout << "Print function for class Derived" << endl;
}

int main190201()
{
    Base* bPtr;
    Base    bObject;
    Derived dObject;
    bPtr = &bObject;    // 设置指向 b 对象地址的指针。
    (bPtr->*bfnPrint)();//Print function for class Base

    bPtr = &dObject;    // 设置指向 d 对象地址的指针。
    (bPtr->*bfnPrint)();//Print function for class Derived
    return 0;
}

