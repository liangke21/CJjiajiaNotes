


// 声明一个带有纯虚析构函数的抽象基类。
// 它是最简单的抽象类。
class base
{
public:
    base() {}
    // 在类外定义虚拟析构函数：
    virtual ~base() = 0;

//  virtual ~base() = 0 {};
};

base::~base() {} // 如果不使用 Microsoft 扩展，则需要

class derived : public base
{
public:
    derived() {}
    ~derived() {}
};

int main1501()
{
    derived aDerived; // 超出范围时调用析构函数
    return 0;
}
/*
 备注

在前面的示例中，纯虚函数 base::~base 是从 derived::~derived 隐式调用的。 也可使用完全限定的成员函数名称显式调用纯虚拟函数。 此类函数必须具有实现，否则调用会导致链接时出错。
*/