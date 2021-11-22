// expre_Formal_and_Actual_Arguments.cpp
void func(long param1, double param2);

int main01031()
{
    long i = 1;
    double j = 2;

    // 使用实参 i 和 j 调用 func。
    func(i, j);

    return 0;
}

// 用形参 param1 和 param2 定义 func。
void func(long param1, double param2)
{
}
//自变量类型的处理

// expre_Treatment_of_Argument_Types.cpp
int func1(const int i, int j, char* c) {
   // i = 7;   // C3892 i is const.
    j = i;   // j 的值在返回时丢失
    *c = 'a' + j;   // 在调用函数中更改 c 的值
    return i;
}

double& func2(double& d, const char* c) {
    d = 14.387;   // 在调用函数中更改 d 的值。
  //  *c = 'a';   // C3892 c 是一个指向 const 对象的指针。
    return d;
}
//省略号和默认参数



#include <iostream>

// 声明打印字符串的函数print，
// 然后是终结者。
void print(const char* string,
    const char* terminator = "\n");

int main03031()
{
    print("hello,");
    print("world!");

    print("good morning", ", ");
    print("sunshine.");

    return 0;
}

using namespace std;
// 定义打印。   上下文 已经声明了第二个默认产生为换行符
void print(const char* string, const char* terminator)
{
    if (string != NULL)
        cout << string;

    if (terminator != NULL)
        cout << terminator;
}