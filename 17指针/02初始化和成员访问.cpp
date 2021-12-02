#include <iostream>
#include <string>

class MyClass
{
public:
    int num;
    std::string name;
    void print() { std::cout << name << ":" << num << std::endl; }
};

// 接受一个 My Class 指针
void func_A(MyClass* mc)
{
// 修改 mc 指向的对象。
    // 指针的所有副本都将指向
    // 相同的修改对象。
    mc->num = 3;
}

// Accepts a MyClass object
void func_B(MyClass mc)
{
// 这里的 mc 是一个普通对象，而不是一个指针。
    // 使用 ”。”操作员访问成员。
    // 该语句只修改 mc 的本地副本。
    mc.num = 21;
    std::cout << "Local copy of mc:";
    mc.print(); // "Erika, 21"
}


int main0201()
{
// 使用 * 运算符声明指针类型
    // 使用new来分配和初始化内存
    MyClass* pmc = new MyClass{ 108, "Nick" };

// 打印内存地址。通常不是你想要的。
    std::cout << pmc << std::endl;

// 通过解引用指针复制指向的对象
    // 访问内存位置的内容。
    // mc 是一个单独的对象，这里分配在栈上
    MyClass mc = *pmc;

// 使用 addressof 操作符声明一个指向 mc 的指针
    MyClass* pcopy = &mc;
    std::cout << &pcopy << std::endl;
// 使用-&gt; 操作符访问对象的公共成员
    pmc->print(); // "Nick, 108"
// 复制指针。现在 pmc 和 pmc2 指向同一个对象！
    MyClass* pmc2 = pmc;

// 使用复制的指针修改原始对象
    pmc2->name = "Erika";
    pmc->print(); // "Erika, 108"
    pmc2->print(); // "Erika, 108"

// 将指针传递给函数。
    func_A(pmc);
    pmc->print(); // "Erika, 3"
    pmc2->print(); // "Erika, 3"

// 取消引用指针并传递一个副本
    // 指向函数的对象
    func_B(*pmc);
    pmc->print(); // 《Erika, 3》（原版未按功能修改）

    delete(pmc); // 不要忘记将内存还给操作系统！
   // 删除（pmc2）； //碰撞！内存位置已被删除

    return 0;
}