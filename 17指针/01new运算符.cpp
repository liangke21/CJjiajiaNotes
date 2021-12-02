#include <malloc.h>
#include <memory.h>
//函数 operator new 的范围
class Blanks
{
public:
    Blanks() {}
    void* operator new(size_t stAllocateBlock, char chInit);
};
void* Blanks::operator new(size_t stAllocateBlock, char chInit)
{
    void* pvTemp = malloc(stAllocateBlock);
    if (pvTemp != 0)
        memset(pvTemp, chInit, stAllocateBlock);
    return pvTemp;
}
// 对于 Blanks 类型的离散对象，全局运算符 new 函数
// 是隐藏的。因此，下面的代码分配了一个类型为
// 清空并将其初始化为 0xa5
int main0301()
{
    Blanks* a5 = new(0xa5) Blanks;
    return a5 != 0;
}

//编译器支持类声明中的成员 newdelete 数组和运算符。 例如：
class MyClass
{
public:
    void* operator new[](size_t)
    {
        return 0;
    }
        void   operator delete[](void*)
    {
    }
};

int main0302()
{
    MyClass* pMyClass = new MyClass[5];
    delete[] pMyClass;
    return 0;
}