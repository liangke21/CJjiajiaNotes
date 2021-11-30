
#include <functional>
#include <iostream>

int main0301()
{

    using namespace std;

    // 分配将两个数字相加到自动变量的 lambda 表达式。
    auto f1 = [](int x, int y) { return x + y; };

    cout << f1(2, 3) << endl;

    //将相同的 lambda 表达式分配给函数对象。
    function<int(int, int)> f2 = [](int x, int y) { return x + y; };

    cout << f2(3, 4) << endl;

    return 0;
}



#include <functional>
#include <iostream>

int main030102()
{
    using namespace std;

    int i = 3;
    int j = 5;

    // 以下 lambda 表达式按值捕获 i 并且
    // j 参考。
    function<int(void)> f = [i, &j] { return i + j; };

    // 更改 i 和 j 的值。
    i = 22;
    j = 44;

    // 调用 f 并打印其结果。
    cout << f() << endl;

    return 0;
}
/*
声明该表达式时，Microsoft C++ 编译器将 lambda 表达式绑定到其捕获的变量，而不是在调用表达式时。
以下示例显示一个通过值捕获局部变量 i 并通过引用捕获局部变量 j 的 lambda 表达式。 
由于 lambda 表达式通过值捕获 i，因此在程序后面部分中重新指派 i 不影响该表达式的结果。
但是，由于 lambda 表达式通过引用捕获 j，因此重新指派 j 会影响该表达式的结果。


*/