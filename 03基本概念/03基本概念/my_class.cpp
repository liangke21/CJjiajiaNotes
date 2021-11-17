// my_class.cpp
#include "my_class.h" // 本地目录中的标题
#include <iostream> // 标准库中的头文件

using namespace N;
using namespace std;

void my_class::do_something()
{
    cout << "做事！" << endl;
}

int main31()
{
    class my_class aa;

    aa.do_something();

    class my_class* aa2 = new my_class;

    aa.do_something();
    return 0;
}