#include <string>



// TestRun.h

class TestRun
{
    // 开始成员列表。

    //所有调用者都可以访问的类接口。
public:
    // 使用编译器生成的默认构造函数：
    TestRun() = default;
    // 不要生成复制构造函数：
    TestRun(const TestRun&) = delete;
    TestRun(std::string name);
    void DoSomething();
    int Calculate(int a, double d);
    virtual ~TestRun();
    enum class State { Active, Suspended };

    // 仅可访问此类和派生类。
protected:  //子类可以访问
    virtual void Initialize();
    virtual void Suspend();
    State GetState();

    // 仅此课程可访问。
private:
    // 实例成员的默认花括号初始化：
    State _state{ State::Suspended };
    std::string _testName{ "" };
    int _index{ 0 };

    //非常量静态成员：
    static int _instances;
    // 结束成员名单。
};

// 定义并初始化静态成员。
int TestRun::_instances{ 0 };

/*


成员可访问性
在成员列表中声明类的成员。 类的成员列表可以分为任意数量 private ， protected 并 public 使用关键字称为访问说明符。 冒号 ： 必须遵循访问说明符。 这些部分不需要是连续的，也就是说，这些关键字中的任何一个都可能在成员列表中多次出现。 关键字指定所有成员直到下一个访问说明符或右大括号的访问。 有关详细信息，请参阅 成员访问控制 (c + +) 。

静态成员
可将数据成员声明为静态，这表示类的所有对象都有权访问它的同一副本。 成员函数可以声明为静态，在这种情况下，它只能访问类的静态数据成员 (并且不) 此 指针。 有关详细信息，请参阅 静态数据成员。




*/