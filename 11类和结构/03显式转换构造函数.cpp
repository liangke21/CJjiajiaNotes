/*

将转换构造函数声明为 时，它只能用于执行对象的直接初始化 explicit 或执行显式强制转换。
这将阻止接受类类型的自变量的函数同样隐式接受转换构造函数的源类型的自变量，
并且将阻止从该源类型的值复制初始化类的类型。
以下示例演示了如何定义显式转换构造函数，
以及它对哪个代码格式正确所产生的影响。

*/

#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    explicit Money(double _amount) : amount{ _amount } {};

    double amount;
};

void display_balance2(const Money balance)
{
    std::cout << "The balance is: " << balance.amount << std::endl;
}

int main150301(int argc, char* argv[])
{
    Money payable{ 79.99 };        //合法：直接初始化是显式的。

    display_balance2(payable);      // 合法：无需转换
    //display_balance(49.95);        // 错误：不存在从 double 转换为 Money 的合适转换。
    display_balance2((Money)9.99f); // 合法：显式转换为 Money

    return 0;
}