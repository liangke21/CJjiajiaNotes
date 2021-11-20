//C + + 标准特性

/*
[[noreturn]] 指定函数从不返回;换句话说，它总是引发异常。 编译器可以调整实体的编译规则 [[noreturn]] 。

[[carries_dependency]] 指定函数传播线程同步的数据依赖项排序。 特性可应用于一个或多个参数，以指定传入的参数将依赖项传递到函数体中。 特性可应用于函数本身，以指定返回值将依赖项移出函数。 编译器可使用此信息生成更高效的代码。

[[deprecated]] Visual Studio 2015 及更高版本： 指定函数不应使用。 或者，它可能不存在于库接口的未来版本中。 当客户端代码尝试调用函数时，编译器可以使用此特性生成信息性消息。 [[deprecated]] 可应用于类的声明、typedef 名称、变量、非静态数据成员、函数、命名空间、枚举、枚举器或模板特殊化。

[[fallthrough]] Visual Studio 2017 和更高版本：(随) 提供， / std:c++17 [[fallthrough]] 属性可在语句的上下文中用作 switch 编译器(的提示，或读取代码的任何人，) fallthrough 的行为。 Microsoft c + +编译器当前不会对 fallthrough 行为发出警告，因此此属性不会影响编译器行为。
*/
[[deprecated]]
void Foo(int);

[[nodiscard]]
int foo(int i) { return i * i; }

int main121()
{
    foo(42); //warning C4834: 使用“nodiscard”属性丢弃函数的返回值
    return 0;
}


int main122()
{
    int arr[10]; // GSL warning C26494 将被解雇
    int* p = arr; // GSL warning C26485 将被解雇
    [[gsl::suppress(bounds.1)]] // 此属性禁止边界规则 #1
    {
        int* q = p + 1; // GSL 警告 C26481 被抑制
        p = q--; // GSL 警告 C26481 被抑制
    }

    return 0;
}
