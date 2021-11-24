
//最小函数 声明 包含返回类型、函数名称和参数列表 (可能为空) 以及向编译器提供其他指令的可选关键字。 以下示例是函数声明：
int sum2(int a, int b);

//函数定义由声明和 正文 组成，正文是大括号之间的所有代码：
int sum2(int a, int b)
{
    return a + b;
}

//constexpr，指示函数的返回值是常量值，可以在编译时计算。

constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
};

//其链接规范或 extern static 。

//使用 C 链接声明 printf。
extern "C" int printf(const char* fmt, ...);

//inline，指示编译器将函数的每次调用替换为函数代码本身。 在某个函数快速执行并且在性能关键代码段中重复调用的情况下，内联可以帮助提高性能。

//inline double Account::GetBalance()
//{
//    return balance;
//}

// 一 noexcept 个表达式，指定函数是否可以引发异常。 在下面的示例中，如果表达式计算结果为 ， is_pod 则函数不会引发异常 true 。

/*

#include <type_traits>

template <typename T>
T copy_object(T& obj) noexcept(std::is_pod<T>) { ... }

*/