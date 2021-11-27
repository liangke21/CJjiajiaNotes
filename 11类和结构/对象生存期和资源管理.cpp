
/*

与托管语言不同，C++ 没有自动 垃圾回收。 这是一个内部进程，在程序运行时释放堆内存和其他资源。 C++ 程序负责将获取的所有资源返回到操作系统。 释放未使用的资源失败 称为泄漏。 在进程退出之前，其他程序无法使用泄漏的资源。 尤其是内存泄漏是 C 样式编程中 bug 的常见原因。

现代 C++ 通过声明堆栈上的 对象来尽可能避免使用堆内存。 如果资源对于堆栈来说太大，则它应 归 对象所有。 当对象初始化时，它将获取它拥有的资源。 然后，对象负责在其析构函数中释放资源。 在堆栈上声明拥有对象本身。 对象拥有 资源的原则 也称为"资源获取是初始化"或 RAII。

当资源拥有堆栈对象超出范围时，会自动调用其析构函数。 这样，C++ 中的垃圾回收与对象生存期密切相关，并且具有确定性。 资源始终在程序中的已知点释放，你可以控制该点。 仅类似 C++ 中的确定析构函数可公平处理内存和非内存资源。

以下示例演示一个简单的 对象 w 。 它在函数范围的堆栈上声明，在函数块的末尾销毁。 对象 w 不拥有任何 (， 例如堆分配的内存) 。 它的唯 g 一成员本身在堆栈上声明，只是与 一起超出范围 w 。 析构函数中不需要 widget 特殊代码。

*/

/*
class widget {
private:
    gadget g;   // 生命周期自动绑定到封闭对象
public:
    void draw();
};

void functionUsingWidget() {
    widget w;   // 生命周期自动绑定到封闭范围
                // 构造 w，包括 w.g 小工具成员
    // ...
    w.draw();
    // ...
} // w 和 w.g 的自动销毁和释放
  // 自动异常安全，
  // 好像“finally { w.dispose(); w.g.dispose(); }”

 */

//在下面的示例中， w 拥有内存资源，因此必须在其析构函数中具有代码以删除内存。

class widget
{
private:
    int* data;
public:
    widget(const int size) { data = new int[size]; } // acquire
    ~widget() { delete[] data; } // release
    void do_something() {}
};

void functionUsingWidget() {
    widget w(1000000);   // 生命周期自动绑定到封闭范围
                        // 构造 w，包括 w.data 成员
    w.do_something();

} // w 和 w.data 的自动销毁和重新分配


//void functionUsingWidget2() {
//    widget w(1000000);   // 生命周期自动绑定到封闭范围
//                        // 构造 w，包括 w.data 成员
//    w.do_something();
//
//    delete &w;
//}

//自 C++11 起，有一种更好的编写上一个示例的方法：使用标准库中的智能指针。 智能指针处理它拥有的内存的分配和删除。 使用智能指针无需在 类中显式析 widget 构函数。

#include <memory>
class widget2
{
private:
    std::unique_ptr<int> data;
public:
    widget2(const int size) { data = std::make_unique<int>(size); }
    void do_something() {}
};

void functionUsingWidget3() {
    widget2 w(1000000);   // 生命周期自动绑定到封闭范围
                // 构造 w，包括 w.data 小工具成员
    // ...
    w.do_something();
    // ...
} // w 和 w.data 的自动销毁和重新分配

int main0701() {


    return 0;
}