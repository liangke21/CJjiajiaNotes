

/*


备注
protected 关键字指定对成员列表中的类成员的访问，直到下一个访问说明 (或) 或 public private 类定义的末尾。 声明为 的 protected 类成员只能由以下项使用：

最初声明这些成员的类的成员函数。

最初声明这些成员的类的友元。

使用公共或受保护访问（派生自最初声明这些成员的类）派生的类。

也对受保护成员具有专用访问权限的以私有方式派生的直接类。

在基类的名称前面， 关键字指定基类的公共成员和受保护成员是 protected 派生类的受保护成员。

受保护的成员不像成员一样私有，只有声明受保护的成员的类的成员可以访问这些成员，但它们不作为成员公开，这些成员可在任何函数 private public 中访问。

被声明为 的受保护成员可供派生类的任何 static 友元或成员函数访问。 未声明为 的受保护成员仅可通过指向派生类的指针、对派生类的引用或对象来访问派生类中的友元和成员 static 函数。

有关相关信息，请参阅控制对类成员的访问中的友元、公共、私有和成员访问表。

*/


// keyword_protected.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class X {
public:
    void setProtMemb(int i) { m_protMemb = i; }
    void Display() { cout << m_protMemb << endl; }
protected:
    int  m_protMemb;
    void Protfunc() { cout << "\nAccess allowed\n"; }
} x;

class Y : public X {
public:
    void useProtfunc() { Protfunc(); }
} y;

int main050401() {
    // x.m_protMemb;         错误，m prot 成员受到保护
    x.setProtMemb(0);   // OK，使用公共访问功能
    x.Display();
    y.setProtMemb(5);   // OK, 使用公共访问功能
    y.Display();
    // x.Protfunc();         错误，Protfunc() 被保护
    y.useProtfunc();    // OK,使用公共访问功能         //Access allowed
                         // 在派生类中
    return 0;
}