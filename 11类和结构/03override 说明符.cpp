
/*
使用 override 有助于防止代码中出现意外的继承行为。 
下面的示例演示在不使用 重写 的情况下，可能尚未设计派生类的成员函数行为。 
编译器不会发出此代码的任何错误。

*/


class BaseClass
{
    virtual void funcA();
    virtual void funcB() const;
    virtual void funcC(int = 0);
    void funcD();
};

class DerivedClass : public BaseClass
{
    virtual void funcA(); // 好的，按预期工作

    virtual void funcB(); // DerivedClass::funcB() 是非常量的，所以它不
                          // override BaseClass::funcB() const，它是一个新的成员函数

    virtual void funcC(double = 0.0); // DerivedClass::funcC(double) has a different
                                      // 参数类型比 Base Class::func C(int)，所以
                                      // Derived Class::func C(double) 是一个新的成员函数
};

//使用 override 时，编译器会生成错误，而不是以无提示方式创建新的成员函数。

class BaseClass2
{
    virtual void funcA();
   virtual void funcB() const;
    virtual void funcC(int = 0);
    void funcD();
};

class DerivedClass2 : public BaseClass2
{
    virtual void funcA() override; // ok

  //  virtual void funcB() override; // 编译器错误：派生类::func B() 没有
                                   // 覆盖基类::func B() const

   // virtual void funcC(double = 0.0) override; // compiler error:
                                                 // DerivedClass::funcC(double) does not
                                                 // override BaseClass::funcC(int)

   // void funcD() override; // 编译器错误：派生类::func D() 没有
                           // 覆盖非虚拟基类::func D()

    //以上 报错的原因是基类没有虚拟构造函数
};

int main1203() {

    return 0;
}