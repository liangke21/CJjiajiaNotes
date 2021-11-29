
/*

指针是仅在 、 或 类型的 this 非状态成员函数中可访问 class struct 的 union 指针。 它指向为其调用成员函数的对象。 静态成员函数没有 this 指针。

语法
C++

复制
this
this->member-identifier
备注
对象的指针 this 不是对象本身的一部分。 它未反映在 对象上的 sizeof 语句的结果中。 为对象调用非状态成员函数时，编译器会将对象的地址作为隐藏参数传递给该函数。 例如，以下函数调用：

C++

复制
myDate.setMonth( 3 );
可解释为：

C++

复制
setMonth( &myDate, 3 );
对象的地址在成员函数中作为指针 this 提供。 大多数 this 指针使用都是隐式的。 引用 的成员时，使用显式 是合法且 this 不必要的 class 。 例如：

C++

复制
void Date::setMonth( int mn )
{
   month = mn;            // 这三个说法
   this->month = mn;      // 是等价的
   (*this).month = mn;
}
表达式 *this 通常用于从成员函数返回当前对象：

C++

复制
return *this;
this 指针还用于防止自引用：

C++

复制
if (&Object != this) {
// do not execute in cases of self-reference
 备注

由于 this 指针不可修改，因此不允许对 this 指针进行赋值。 C++ 的早期版本实现允许将 赋值给 this 。

有时，指针直接使用 - 例如，用于操作自引用数据 this struct uri，其中当前对象的地址是必需的。
*/






#include <iostream>
#include <string.h>

using namespace std;

class Buf
{
public:
    Buf(const char* szBuffer, size_t sizeOfBuffer);
    Buf& operator=(const Buf&);
    void Display() { cout << buffer << endl; }

private:
    char* buffer;
    size_t  sizeOfBuffer;
};

Buf::Buf(const char* szBuffer, size_t sizeOfBuffer)
{
    sizeOfBuffer++; //占空终止符

    buffer = new char[sizeOfBuffer];
    if (buffer)
    {
        strcpy_s(buffer, sizeOfBuffer, szBuffer);
        sizeOfBuffer = sizeOfBuffer;
    }
}

Buf& Buf::operator=(const Buf& otherbuf)
{
    if (&otherbuf != this)
    {
        if (buffer)
            delete[] buffer;

        sizeOfBuffer = strlen(otherbuf.buffer) + 1;
        buffer = new char[sizeOfBuffer];
        strcpy_s(buffer, sizeOfBuffer, otherbuf.buffer);
    }
    return *this;
}

int main2001()
{
    Buf myBuf("my buffer", 10);
    Buf yourBuf("your buffer", 12);

    // 显示“我的缓冲区”
    myBuf.Display();//my buffer    4个空格

    // 赋值运算符
    myBuf = yourBuf;

    // 显示“你的缓冲区”
    myBuf.Display(); //your buffer 3个空格
    return 0;
}