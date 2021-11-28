#include <iostream>
using namespace std;


struct Derived;

struct Base {
    friend struct Derived;
private:
    Base() {
        cout << "1" << endl;
    }
};

struct Derived : Base {

    Derived() {

        cout << "2" << endl;
    }
};



int main10010601() {

    Derived d1; // OK. 不涉及聚合初始化。
    Derived d2{}; // OK in C++14: 调用派生::派生()
                   // 可以调用 Base ctor。

   // 上面两种初始化等效
    cout << "3" << endl;
    return 0;
}