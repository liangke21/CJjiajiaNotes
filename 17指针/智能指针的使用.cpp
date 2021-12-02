

//创建智能指针   std::unique_ptr<LargeObject> pLarge(new LargeObject());


/*
智能指针在 stdstd头文件的命名空间中定义。 
它们对于 RAII 或 资源获取是初始化 编程编程至关重要。
此习惯用法的主要目的是确保资源获取与对象初始化同时发生，
从而能够创建该对象的所有资源并在某行代码中准备就绪。 
实际上，RAII 的主要原则是为将任何堆分配资源（例如，动态分配内存或系统对象句柄）
的所有权提供给其析构函数包含用于删除或释放资源的代码以及任何相关清理代码的堆栈分配对象。

大多数情况下，当初始化原始指针或资源句柄以指向实际资源时，
会立即将指针传递给智能指针。 在现代 C++ 中，原始指针仅用于范围有限的小代码块、
循环或者性能至关重要且不会混淆所有权的 Helper 函数中。

下面的示例将原始指针声明与智能指针声明进行了比较。
*/

//void UseRawPointer()
//{
//    // 使用原始指针——不推荐。
//    Song* pSong = new Song(L"Nothing on You", L"Bruno Mars");
//
//    // 使用 p 歌...
//
//    // 别忘了删除！
//    delete pSong;
//}
//
//
//void UseSmartPointer()
//{
//    // 在堆栈上声明一个智能指针并将原始指针传递给它。
//    unique_ptr<Song> song2(new Song(L"Nothing on You", L"Bruno Mars"));
//
//    // 使用歌曲2...
//    wstring s = song2->duration_;
//    //...
//
//} // 此处将自动删除歌曲 2。

/*
如示例所示，智能指针是你在堆栈上声明的类模板，并可通过使用指向某个堆分配的对象的原始指针进行初始化。 在初始化智能指针后，它将拥有原始的指针。 这意味着智能指针负责删除原始指针指定的内存。 智能指针析构函数包括要删除的调用，并且由于在堆栈上声明了智能指针，当智能指针超出范围时将调用其析构函数，尽管堆栈上的某处将进一步引发异常。

通过使用熟悉的指针运算符（-> 和 *）访问封装指针，智能指针类将重载这些运算符以返回封装的原始指针。

C++ 智能指针思路类似于在语言（如 C#）中创建对象的过程：创建对象后让系统负责在正确的时间将其删除。 不同之处在于，单独的垃圾回收器不在后台运行；按照标准 C++ 范围规则对内存进行管理，以使运行时环境更快速更有效。

 重要

请始终在单独的代码行上创建智能指针，而绝不在参数列表中创建智能指针，这样就不会由于某些参数列表分配规则而发生轻微泄露资源的情况。
*/


#include <memory>
class LargeObject
{
public:
    void DoSomething() {}
};

void ProcessLargeObject(const LargeObject& lo) {}
void SmartPointerDemo()
{
    // 创建对象并将其传递给智能指针
    std::unique_ptr<LargeObject> pLarge(new LargeObject());

    //调用对象的方法
    pLarge->DoSomething();

    // 传递对方法的引用。
    ProcessLargeObject(*pLarge);

} //p 当功能块超出范围时会自动删除大。