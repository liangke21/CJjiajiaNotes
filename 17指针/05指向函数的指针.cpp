/*

在 C 样式编程中，函数指针主要用于将函数传递到其他函数。 此方法允许调用方自定义函数的行为而不进行修改。 在现代 c + + 中， lambda 表达式 提供相同的功能以及更高的类型安全性和其他优点。

函数指针声明指定所指向的函数必须具有的签名：

C++

复制
// 声明指向任何函数的指针...

// ...接受一个字符串并返回一个字符串
string (*g)(string a);

// 没有返回值和参数
void (*x)();

// ...返回一个整数并接受三个参数
// 指定类型
int (*i)(int i, string s, double d);
下面的示例演示一个函数 combine ，该函数将接受的任何函数作为参数 std::string ，并返回 std::string 。 根据传递到的函数 combine ，它将添加或追加字符串。




*/

#include <iostream>
#include <string>

using namespace std;

string base{ "hello world" };

string append(string s)
{
    return base.append(" ").append(s);
}

string prepend(string s)
{
    return s.append(" ").append(base);
}

string combine(string s, string(*g)(string a))
{
    return (*g)(s);
}

int main0501()
{
    cout << combine("from MSVC", append) << "\n";
    cout << combine("Good morning and", prepend) << "\n";
    return 0;
}