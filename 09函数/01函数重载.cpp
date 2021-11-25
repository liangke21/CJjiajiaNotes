


// function_overloading.cpp
// compile with: /EHsc
#include <iostream>
#include <math.h>
#include <string>

// 原型三个打印功能。
int print(std::string s);             //打印一个字符串。
int print(double dvalue);            // 打印双份。
int print(double dvalue, int prec);  // 打印一个双
                                     //  给定精度。
using namespace std;
int main(int argc, char* argv[])
{
    const double d = 893094.2987;
    if (argc < 2)
    {
        // 这些对 print 的调用调用了 print( char *s )。
        print("这个程序需要一个参数。");
        print("该参数指定了");
        print("第二个数字的位数精度");
        print("printed.");
        exit(0);
    }

    // 调用打印（双 dvalue ）。
    print(d);

    // 调用 print( double dvalue, int prec )。
    print(d, atoi(argv[1]));
}

// 打印一个字符串。
int print(string s)
{
    cout << s << endl;
    return cout.good();
}

// 以默认精度打印双精度。
int print(double dvalue)
{
    cout << dvalue << endl;
    return cout.good();
}

// 以指定精度打印双精度值。
// 精度的正数表示有多少位
// 显示小数点后的精度。消极的
// 用于精度的数字表示将数字四舍五入的位置
//小数点左边。
int print(double dvalue, int prec)
{
    // 使用表查找进行舍入/截断。
    static const double rgPow10[] = {
        10E-7, 10E-6, 10E-5, 10E-4, 10E-3, 10E-2, 10E-1,
        10E0, 10E1,  10E2,  10E3,  10E4, 10E5,  10E6 };
    const int iPowZero = 6;

    // 如果精度超出范围，只需打印数字。
    if (prec < -6 || prec > 7)
    {
        return print(dvalue);
    }
    // 缩放，截断，然后重新缩放。
    dvalue = floor(dvalue / rgPow10[iPowZero - prec]) *
        rgPow10[iPowZero - prec];
    cout << dvalue << endl;
    return cout.good();
}