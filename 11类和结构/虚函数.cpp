
/*
虚函数是应在派生类中重新定义的成员函数。 当使用指针或对基类的引用来引用派生的类对象时，可以为该对象调用虚函数并执行该函数的派生类版本。

虚函数确保为该对象调用正确的函数，这与用于进行函数调用的表达式无关。

假设基类包含声明为 virtual 的函数，而派生类定义相同的函数。
为派生类的对象调用派生类中的函数，即使它是使用指针或对基类的引用来调用的。 
以下示例显示了一个基类，它提供了 PrintBalance 函数和两个派生类的实现
*/



#include <iostream>
using namespace std;

class Account {
public:
    Account(double d) { _balance = d; }
    virtual ~Account() {}
    virtual double GetBalance() { return _balance; }
    virtual void PrintBalance() { cerr << "错误。平衡不适用于基础类型." << endl; }
private:
    double _balance;
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double d) : Account(d) {}
    void PrintBalance() { cout << "检查帐户余额: " << GetBalance() << endl; }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double d) : Account(d) {}
    void PrintBalance() { cout << "储蓄账户余额: " << GetBalance(); }
};

int main130201() {
    // 创建类型为 Checking Account 和 Savings Account 的对象。
    CheckingAccount checking(100.00);
    SavingsAccount  savings(1000.00);

    // 使用指向 Account 的指针调用 Print Balance。
    Account* pAccount = &checking;
    pAccount->PrintBalance();//查询账户余额

    // 使用指向 Account 的指针调用 Print Balance。
    pAccount = &savings;
    pAccount->PrintBalance();//储蓄账户余额
    return 0;
}
/*
在前面的代码中，对 PrintBalance 的调用是相同的，pAccount 所指向的对象除外。 由于 PrintBalance 是虚拟的，因此将调用为每个对象定义的函数版本。 派生类 PrintBalance 和 CheckingAccount 中的 SavingsAccount 函数“重写”基类 Account 中的函数。

如果声明的类不提供 PrintBalance 函数的重写实现，则使用基类 Account 中的默认实现。

派生类中的函数仅在基类中的虚函数的类型相同时重写这些虚函数。 派生类中的函数不能只是与其返回类型中的基类的虚函数不同；参数列表也必须不同。

当使用指针或引用调用函数时，以下规则将适用：

根据为其调用的对象的基本类型来解析对虚函数的调用。

根据指针或引用的类型来解析对非虚函数的调用。

以下示例说明在通过指针调用时虚函数和非虚函数的行为：
*/

#include <iostream>
using namespace std;

class BaseX {
public:
    virtual void NameOf();   //虚函数。
    void InvokingClass();   // 非虚函数。
};

// 实现这两个功能。
void BaseX::NameOf() {
    cout << "Base::NameOf\n";
}

void BaseX::InvokingClass() {
    cout << "Invoked by Base\n";
}

class Derived : public BaseX {
public:
    void NameOf();   // 虚函数。
    void InvokingClass();   // 非虚函数。
};

// 实现这两个功能。
void Derived::NameOf() {
    cout << "Derived::NameOf\n";
}

void Derived::InvokingClass() {
    cout << "Invoked by Derived\n";
}

int main130210() {
    //声明一个 Derived 类型的对象。
    Derived aDerived;

    // 声明两个指针，一个是 Derived * 类型，另一个是
    // Base * 类型，并将它们初始化为指向 Derived。
    Derived* pDerived = &aDerived;
    BaseX* pBase = &aDerived;

    // 调用函数。
    pBase->NameOf();           //调用虚函数。 //Derived::NameOf
    pBase->InvokingClass();    // 调用非虚函数。//Invoked by Base   不是虚拟函数基类有就先执行基类的
    pDerived->NameOf();        // 调用虚函数。//Derived::NameOf
    pDerived->InvokingClass(); // 调用非虚函数。//   Invoked by Derived

    return 0;
}