

/*
抽象类作为可从中派生更具体的类的一般概念的表达。 无法创建抽象类类型的对象。 但是，可以使用指向抽象类类型的指针和引用。

通过声明至少一个纯虚拟成员函数来创建抽象类。 这是一个虚拟函数，它使用 纯 说明 () = 0 语法。 派生自抽象类的类必须实现纯虚函数或者它们必须也是抽象类。

请考虑虚拟函数 中提供的示例。 类 Account 的用途是提供通用功能，但 Account 类型的对象太通用，因此没什么用。 这意味着 Account 是抽象类的不错候选项：

*/

//通过声明至少一个纯虚拟成员函数来创建抽象类。 


class Account {
public:
    Account(double d);   // Constructor.
    virtual double GetBalance();   // 取得平衡。
    virtual void PrintBalance() = 0;   // 纯虚函数。
private:
    double _balance;
};
/*
此声明与上一个声明的唯一区别是，PrintBalance 是用 pure 说明符(= 0) 声明的。

抽象类限制
抽象类不能用于：

变量或成员数据

自变量类型

函数返回类型

显式转换的类型

如果抽象类的构造函数直接或间接调用纯虚函数，则结果不确定。 但是，抽象类的构造函数和析构函数都可以调用其他成员函数。
*/