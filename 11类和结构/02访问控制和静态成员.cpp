
class Base
{
public:
    int Print();             // 非静态成员。
    static int CountOf();    // 静态成员。

};

// Derived1 将 Base 声明为私有基类。
class Derived1 : private Base
{
  
};
// Derived2 将 Derived1 声明为公共基类。
class Derived2 : public Derived1
{
    int ShowCount();    // 非静态成员。

  
};
// 为 Derived2 定义 Show Count 函数。
int Derived2::ShowCount()
{
    // 显式调用静态成员函数 Count Of。
 //   int cCount = Base::CountOf();     // OK.

   // 使用指针调用静态成员函数 Count 。
 //   cCount = this->CountOf();  // C2247. 的转换
                               //  Derived2 * to Base * not
                               //  permitted.



    return 0;
}

/*


将基类指定为 时 private ，它仅影响非状态成员。 在派生类中，公共静态成员仍是可访问的。 但是，使用指针、引用或对象访问基类的成员需要转换，此时将再次应用访问控制。 请考虑以下示例：

*/

/*
在前面的代码中，访问控制禁止从指向 Derived2 的指针转换为指向 Base 的指针。 指针 this 隐式为 类型 Derived2 * 。 若要选择 CountOf 函数， this 必须转换为类型 Base * 。 不允许执行此类转换，因为 Base 是 Derived2 的私有间接基类。 到私有基类类型的转换仅对于指向立即派生类的指针是可接受的。 因此，可以将 Derived1 * 类型的指针转换为 Base * 类型。

请注意，显式调用 CountOf 函数而不使用指针、引用或对象来选择它，则表示没有转换。 因此，允许该调用。

派生类 T 的成员和朋友可以将指向 T 的指针转换为指向 T 的私有直接基类的指针。
*/

int main05010201()
{

    return 0;
}