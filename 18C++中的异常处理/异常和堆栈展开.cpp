





#include <string>
#include <iostream>
using namespace std;

class MyException {};
class Dummy
{
public:
    Dummy(string s) : MyName(s) { PrintMsg("Created Dummy:"); }
    Dummy(const Dummy& other) : MyName(other.MyName) { PrintMsg("Copy created Dummy:"); }
    ~Dummy() { PrintMsg("Destroyed Dummy:"); }
    void PrintMsg(string s) { cout << s << MyName << endl; }
    string MyName;
    int level;
};

void C(Dummy d, int i)
{
    cout << "Entering FunctionC" << endl;
    d.MyName = " C";
    throw MyException();

    cout << "Exiting FunctionC" << endl;
}

void B(Dummy d, int i)
{
    cout << "Entering FunctionB" << endl;
    d.MyName = "B";
    C(d, i + 1);
    cout << "Exiting FunctionB" << endl;
}

void A(Dummy d, int i)
{
    cout << "Entering FunctionA" << endl;
    d.MyName = " A";
    //  Dummy* pd = new Dummy("new Dummy"); //Not exception safe!!!
    B(d, i + 1);//执行复制构造函数
    //   delete pd;
    cout << "Exiting FunctionA" << endl;
}

int main180601()
{
    cout << "Entering main" << endl;
    try
    {
        Dummy d(" M");//执行构造函数 接收string类型的参数
        A(d, 1);//执行 复制构造函数
    }
    catch (MyException& e)
    {
        cout << "Caught an exception of type: " << typeid(e).name() << endl;
    }

    cout << "Exiting main." << endl;
    char c;
    cin >> c;
    return 0;
}

/*
以下示例演示引发异常时如何展开堆栈。
线程执行将从 C 中的 throw 语句跳转到 main 中的 catch 语句，
并在此过程中展开每个函数。 请注意创建 Dummy 对象的顺序，
并且会在它们超出范围时将其销毁。 还请注意，除了包含 catch 语句的 main 之外，其他函数均未完成。
函数 A 绝不会从其对 B() 的调用返回，并且 B 绝不会从其对 C() 的调用返回。
如果取消注释 Dummy 指针和相应的 delete 语句的定义并运行程序，请注意绝不会删除该指针。
这说明了当函数不提供异常保证时会发生的情况。
有关详细信息，请参阅“如何：针对异常进行设计”。
如果注释掉 catch 语句，则可以观察当程序因未经处理的异常而终止时将发生的情况。
*/

/* Output:
    Entering main
    Created Dummy: M
    Copy created Dummy: M
    Entering FunctionA
    Copy created Dummy: A
    Entering FunctionB
    Copy created Dummy: B
    Entering FunctionC
    Destroyed Dummy: C
    Destroyed Dummy: B
    Destroyed Dummy: A
    Destroyed Dummy: M
    Caught an exception of type: class MyException
    Exiting main.

*/