
//语法
//static_assert(constant - expression, string - literal);

//static_assert(constant - expression); // C++17 (Visual Studio 2017 and later)

/*
参数
constant-expression
可以转换为布尔值的整型常量表达式。 如果计算表达式为零 (false) ，则 显示字符串 文本参数，编译失败并出现错误。 如果表达式为非零 (为 true) ， static_assert 则声明无效。

string-literal
如果 constant-expression 参数为零，则显示一条消息。 消息是编译器的基字符 集的字符 字符串;即，不是 多字节或宽字符。

备注
声明 的 constant-expression 参数表示软件 断言。 软件断言指定在程序的某个特定点应满足的条件。 如果条件为 true， static_assert 则声明无效。 如果条件为 false，断言失败，编译器将在 字符串文本 参数中显示消息，编译失败并出现错误。 在 Visual Studio 2017 及更高版本中，string-literal 参数是可选的。

声明 static_assert 在编译时测试软件断言。 相反， 断言宏_assert_wassert 函数会运行时测试软件断言，并产生空间或时间的运行时成本。 static_assert声明对于调试模板特别有用，因为模板参数可以包括在static_assert中。

遇到声明时 static_assert ，编译器检查声明的语法错误。 如果常量表达式参数不依赖于模板 参数 ，则编译器会立即计算该参数。 否则，编译器在实例化模板时计算 constant-expression 参数。 因此，当遇到声明时，编译器可能一次发布一个诊断消息，而在对模板进行实例化时也是如此。

可以在命名空间 static_assert 、类或块范围中使用 关键字。 (关键字在技术上是声明，即使它不会在程序中引入新名称，因为它可以在 static_assert 命名空间 scope.)

*/

//static_assert 具有类范围

#include <type_traits>
#include <iosfwd>
namespace std {
    template <class CharT, class Traits = std::char_traits<CharT> >
    class basic_string {
        static_assert(std::is_pod<CharT>::value,
            "模板参数 Char T 必须是类模板基本字符串中的 POD 类型");
        // ...
    };
}


struct NonPOD {
    NonPOD(const NonPOD&) {}
    virtual ~NonPOD() {}
};

int main()
{
    std::basic_string<char> bs;
}
//示例： static_assert 在块范围内
//#include <sys/param.h> // 定义 PAGESIZE
//class VMMClient {
//public:
//    struct VMPage { // ...
//    };
//    int check_pagesize() {
//        static_assert(sizeof(VMPage) == PAGESIZE,
//            "Struct VMPage must be the same size as a system virtual memory page.");
//        // ...
//    }
//    // ...
//};