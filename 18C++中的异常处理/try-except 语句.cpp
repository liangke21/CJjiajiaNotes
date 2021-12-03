






#include <stdio.h>
#include <windows.h> // 异常访问违规
#include <excpt.h>

int filter(unsigned int code, struct _EXCEPTION_POINTERS* ep)
{
    puts("in filter.");
    if (code == EXCEPTION_ACCESS_VIOLATION)
    {
        puts("caught AV as expected.");
        return EXCEPTION_EXECUTE_HANDLER;
    }
    else
    {
        puts("didn't catch AV, unexpected.");
        return EXCEPTION_CONTINUE_SEARCH;
    };
}

int main181101()
{
    int* p = 0x00000000;   // 指向 NULL 的指针
    puts("hello");
    __try
    {
        puts("in try");
        __try
        {
            puts("in try");
            *p = 13;    // causes an access violation exception;
        }
        __finally
        {
            puts("in finally. termination: ");
            puts(AbnormalTermination() ? "\tabnormal" : "\tnormal");
        }
    }
    __except (filter(GetExceptionCode(), GetExceptionInformation()))  //没有发生异常 也执行 发生异常 有3种执行方式
    {
        puts("in except");
    }
    puts("world");

    return 0;

    /*
    
    hello
in try
in try
in filter.
caught AV as expected.
in finally. termination:
        abnormal
in except
world
    */
}
/*
子句后的复合 __try 语句是__try或已保护部分。 __except表达式也称为筛选器__except。 其值确定如何处理异常。 在 __except 子句后的复合语句是异常处理程序。 处理程序指定在执行正文部分期间引发异常时要采取的操作。 执行过程如下所示：

执行受保护节。

如果在受保护节执行过程中未发生异常，则继续执行 __except 子句之后的语句。

如果在执行已保护的节期间或在任何例程的已保护节调用中发生异常， __except 则计算表达式。 有三种可能的值：

EXCEPTION_CONTINUE_EXECUTION (-1) 异常已消除。 从出现异常的点继续执行。

EXCEPTION_CONTINUE_SEARCH (0) 无法识别异常。 继续向上搜索堆栈查找处理程序，首先是所在的 try-except 语句，然后是具有下一个最高优先级的处理程序。

EXCEPTION_EXECUTE_HANDLER (1) 识别异常。 通过执行复合语句将控制转移到异常处理程序，然后在 __except 块后继续执行 __except 。

__except表达式作为 C 表达式计算。 它仅限于单个值、条件表达式运算符或逗号运算符。 如果需要更大量的处理，表达式可调用返回上面列出的三个值之一的例程。

每个应用程序都可以有各自的异常处理程序。

跳转到 语句无效，但跳转到一个 语句 __try 有效。 如果进程在执行 语句的过程中终止，则不调用异常 try-except 处理程序。
*/