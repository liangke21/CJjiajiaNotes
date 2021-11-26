

// 原型三个打印功能。
int print(char* s);                  // 打印一个字符串。
int print(double dvalue);            // 打印双份。
//int print(double dvalue, int prec);  // 打印一个双
//  给定精度。

//在许多应用程序中，可为 prec 提供合理的默认值，从而消除对两个函数的需求：

// 原型两个打印功能。
//int print(char* s);                    // 打印一个字符串。
//int print(double dvalue, int prec = 2);  // 打印一个双
//  给定精度。


// 默认参数.cpp
// 编译： /EHsc /c



// 以指定精度打印双精度值。
// 精度的正数表示有多少位
// 显示小数点后的精度。消极的
// 用于精度的数字表示将数字四舍五入的位置
//小数点左边。

#include <iostream>
#include <math.h>
using namespace std;

//int print(double dvalue, int prec) {
//    //使用表查找进行舍入/截断。
//    static const double rgPow10[] = {
//       10E-7, 10E-6, 10E-5, 10E-4, 10E-3, 10E-2, 10E-1, 10E0,
//          10E1,  10E2,  10E3,  10E4, 10E5,  10E6
//    };
//    const int iPowZero = 6;
//    // 如果精度超出范围，只需打印数字。
//    if (prec >= -6 && prec <= 7)
//        //缩放，截断，然后重新缩放。
//        dvalue = floor(dvalue / rgPow10[iPowZero - prec]) *
//        rgPow10[iPowZero - prec];
//    cout << dvalue << endl;
//    return cout.good();
//}

//使用默认参数时，请注意以下几点：

//默认参数仅在其中省略了尾随参数的函数调用中使用 - 它们必须是最后的参数。 因此，以下代码是非法的

//int print(double dvalue = 0.0, int prec);


// 打印功能的原型。
int print2(double dvalue, int prec = 2);



// 打印功能的定义。
//int print2(double dvalue, int prec = 2)
//{
//  
//}


int print2(double dvalue)
{

    return 0;

}