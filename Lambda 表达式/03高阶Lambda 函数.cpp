
#include <iostream>
#include <functional>

int main030301()
{
    using namespace std;
// 下面的代码声明了一个返回的 lambda 表达式
    // 另一个将两个数字相加的 lambda 表达式。
    // 返回的 lambda 表达式按值捕获参数 x。
    auto addtwointegers = [](int x) -> function<int(int)> {//->表示返回类型
        return [=](int y) { return x + y; };
    };

// 下面的代码声明了一个 lambda 表达式，它接受另一个
    // lambda 表达式作为它的参数。
    // lambda 表达式将参数 z 应用于函数 f
    // 并乘以 2。
    auto higherorder = [](const function<int(int)>& f, int z) {
        return f(z) * 2;
    };

    // 调用绑定到高阶的 lambda 表达式。
    auto answer = higherorder(addtwointegers(7), 8);

    // 打印结果，即 (7+8)*2.
    cout << answer << endl;//30

    return 0;
}