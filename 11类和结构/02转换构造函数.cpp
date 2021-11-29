
//转换构造函数定义了从用户定义的类型或内置类型到用户定义的类型的转换。 下面的示例演示从内置类型转换为用户定义类型的 double 转换构造函数 Money 。



#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    Money(double _amount) : amount{ _amount } {};

    double amount;
};

void display_balance(const Money balance)
{
    std::cout << "The balance is: " << balance.amount << std::endl;
}

int main150201(int argc, char* argv[])
{
    Money payable{ 79.99 };

    display_balance(payable);
    display_balance(49.95);
    display_balance(9.99f);

    return 0;
}

/*
请注意，对函数 display_balance 的首次调用（它将采用类型 Money 的自变量）不需要转换，因为它的自变量类型正确。 但是，第二次调用 时，需要转换，因为 参数的类型（值为 ）不是函数 display_balance double 49.95 期望的类型。 函数不能直接使用此值，但由于存在从参数类型到匹配参数类型的转换，因此类型的临时值从 参数构造并用于 double Money 完成函数 Money 调用。 在对 的第三次调用中，请注意 参数不是 ，而是值为 的 ，但函数调用仍可完成，因为编译器可以执行从 到 的标准转换，然后执行从 到 的用户定义转换以完成 display_balance double float 9.99 float double double Money 必要的转换。
*/



