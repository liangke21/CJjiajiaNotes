

//如果类从多个基类派生，那么将按照派生类声明中列出的顺序调用基类构造函数：

#include <iostream>
using namespace std;

class BaseClass1 {
public:
    BaseClass1() { cout << "基类 1 ctor\n"; }
};
class BaseClass2 {
public:
    BaseClass2() { cout << "基类 2 ctor\n"; }
};
class BaseClass3 {
public:
    BaseClass3() { cout << "基类3 ctor\n"; }
};
class DerivedClass : public BaseClass1,
    public BaseClass2,
    public BaseClass3
{
public:
    DerivedClass() { cout << "派生类构造函数\n"; }
};

int main10010701() {
    DerivedClass dc;
    /*
    基类 1 ctor
    基类 2 ctor
    基类3 ctor
    派生类构造函数
    */

    return 0;
}