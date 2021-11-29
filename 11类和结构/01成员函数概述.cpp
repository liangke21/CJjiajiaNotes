#include <iostream>


/*
成员函数是静态或非静态的。 静态成员函数的行为与其他成员函数的行为不同，
因为静态成员函数没有隐式 this 自变量。 非静态成员函数具有 this 指针。
可以在类声明的内部或外部定义成员函数（无论是静态的还是非静态的）。

如果在类声明的内部定义一个成员函数，则该函数会被视为内联函数，
并且不需要用其类名来限定函数名称。 尽管在类声明中定义的函数已被视为内联函数，
但您可以使用 inline 关键字来记录代码。

在类声明中声明函数的示例如下所示：

*/


class Account
{
public:
  // 在声明中声明成员函数Deposit
    // 类帐户。
    double Deposit(double HowMuch)
    {
        balance += HowMuch;
        return balance;
    }
private:
    double balance;
};

int main1201()
{
    Account a;
    a.Deposit(4.8);

    return 0;

}
//如果成员函数的定义在类声明的外部，则仅当它显式声明为时，才会将其视为内联函数 inline 。 此外，必须通过范围解析运算符(::) 用类名称限定定义中的函数名称。

//以下示例与类 Account 的以前的声明等效，只不过 Deposit 函数是在类声明的外部定义的：


class Account
{
public:
    // 声明成员函数存款但不定义它。
    double Deposit(double HowMuch);
private:
    double balance;
};

inline double Account::Deposit(double HowMuch)
{
    balance += HowMuch;
    return balance;
}

int main1202()
{
    return 0;
}
/*
 备注

虽然成员函数既可在类声明的内部进行定义也可单独进行定义，但在定义类后，不能将任何成员函数添加到类中。



包含成员函数的类可具有多个声明，但成员函数本身只能在程序中有一个定义。 多个定义会导致在链接时出现错误消息。 如果类包含内联函数定义，则这些函数定义必须与遵守此“一个定义”规则相同。
*/