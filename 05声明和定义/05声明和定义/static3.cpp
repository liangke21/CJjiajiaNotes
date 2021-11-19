// static3.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;


struct C {
    void Test(int value) {
        static int var = 0;
        if (var == value)
            cout << "var == value" << endl;
        else
            cout << "var != value" << endl;

        var = value;
    }
};

int main23() {
    C c1;
    C c2;
    c1.Test(100);

    c2.Test(100);
    return 0;
}

//thread_local (C++11)

thread_local float f = 42.0; // 全局命名空间。不是隐式静态的。

struct S // 不能应用于类型定义
{
  //  thread_local int i; // 非法的。该成员必须是静态的。
    thread_local static char buf[10]; // OK
};

void DoSomething()
{
    // 将线程局部应用于局部变量。
    // 隐式“线程局部静态 S 我的结构”。
    thread_local S my_struct;
}