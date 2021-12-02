/*
* 指向 void 原始内存位置的指针。 有时需要使用 void* 指针，例如在 c + + 代码和 c 函数之间传递时。

将类型化的指针强制转换为 void 指针时，内存位置的内容将保持不变。
但类型信息会丢失，因此不能执行递增或递减操作。
例如，可以将内存位置转换为，也可以强制转换 MyClass*void* 回 MyClass* 。
此类操作本质上容易出错，并需要小心处理 void 错误。 现代 c + + void 在几乎所有情况下都不鼓励使用指针。



*/

//func.c
void func(void* data, int length)
{
    char* c = (char*)(data);

    // fill in the buffer with data
    for (int i = 0; i < length; ++i)
    {
        *c = 0x41;
        ++c;
    }
}

// main.cpp
#include <iostream>

extern "C"
{
   // void func(void* data, int length);
}

class MyClass
{
public:
    int num;
    std::string name;
    void print() { std::cout << name << ":" << num << std::endl; }
};

int main0401()
{
    MyClass* mc = new MyClass{ 10, "Marian" };
    std::cout << mc << std::endl; 

    void* p = static_cast<void*>(mc);
    std::cout << p << std::endl;

    MyClass* mc2 = static_cast<MyClass*>(p);
    std::cout << mc2 << std::endl;

    std::cout << mc2->name << std::endl; // "Marian"

    // 使用 operator new 分配无类型内存块
    void* pvoid = operator new(1000);
    char* pchar = static_cast<char*>(pvoid);
    for (char* c = pchar; c < pchar + 1000; ++c)
    {
        *c = 0x00;
    }
    func(pvoid, 1000);
    char ch = static_cast<char*>(pvoid)[0];
    std::cout << ch << std::endl; // 'A'
    operator delete(p);
    return 0;
}