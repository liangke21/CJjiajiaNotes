class Point
{
public:
    Point(int, int);// 声明公共构造函数。
        Point();// 声明公共默认构造函数。
    int& x(int); // 声明公共访问器。
    int& y(int); // 声明公共访问器。

private:                 // 声明私有状态变量。
    int _x;
    int _y;

protected:      // 仅为派生类声明受保护的函数。
    Point ToWindowCoords();
};

/*

默认访问位于 private 类中，在 public 结构或联合中。 类中的访问说明符可按任何顺序使用任意次数。 类类型的对象的存储分配是取决于实现的，但成员一定能分配到访问说明符之间的依次升高的内存地址。

成员访问控制
成员访问控制
访问类型	含义
private	声明为 的类成员只能由成员函数和友元 (private 类或类) 的友元使用。
protected	声明为 的类成员可以由成员函数和友元 (protected 类或) 类或函数使用。 此外，它们还可由派生自该类的类使用。
public	声明为 的 public 类成员可用于任何函数。
访问控制有助于阻止您通过不适当的方式使用对象。 在执行显式类型转换（强制转换）时，此保护将丢失。

 备注

访问控制同样适用于所有名称：成员函数、成员数据、嵌套类和枚举数。
*/


/*
https://docs.microsoft.com/zh-cn/cpp/cpp/member-access-control-cpp?view=msvc-170#member-access-in-base-class
基类中的成员访问
基类中的成员访问
private	   protected	公用
无论派生访问权限如何，始终不可访问	如果使用私有派生，则在派生类中为私有	如果使用私有派生，则在派生类中为私有
如果使用受保护派生，则在派生类中为受保护	如果使用受保护派生，则在派生类中为受保护
如果使用公有派生，则在派生类中为受保护	如果使用公有派生，则在派生类中为公有
以下示例对此进行了说明：
*/


// access_specifiers_for_base_classes.cpp
class BaseClass
{
public:
    int PublicFunc(); // 声明一个公共成员.
protected:
    int ProtectedFunc(); // 声明一个受保护的成员。
private:
    int PrivateFunc(); // 声明一个私有成员。
};

// 声明两个派生自 Base Class 的类。
class DerivedClass1 : public BaseClass
{
    void foo()
    {
        PublicFunc();
        ProtectedFunc();
       // PrivateFunc(); // 功能无法访问
    }
};

class DerivedClass2 : private BaseClass
{
    void foo()
    {
        PublicFunc();
        ProtectedFunc();
       // PrivateFunc(); // 功能无法访问
    }
};

int main050101()
{
   // DerivedClass1 derived_class1;
  //  DerivedClass2 derived_class2;
   // derived_class1.PublicFunc();
   // derived_class2.PublicFunc(); // 功能无法访问  只能在派生类中访问//

    return 0;
}