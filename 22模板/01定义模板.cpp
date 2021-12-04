#include <iostream>
using namespace std;


//定义和使用模板

template <typename T>
T minimum(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}

int main220101() {

    int a = 20;
    int b = 30;
    int i = minimum<int>(a, b);//ok 的
    //但是，由于这是一个函数模板，并且编译器可以 T 从参数 T 和 b推导的类型，因此可以像普通函数一样调用它：
    int i = minimum(a, b);//ko
    cout << i << endl;
    return 0;
}
//当编译器遇到最后一个语句时，它会生成一个新函数，其中，模板中的每个 T 均替换为 ：

int minimum(const int& lhs, const int& rhs)
{
    return lhs < rhs ? lhs : rhs;
}