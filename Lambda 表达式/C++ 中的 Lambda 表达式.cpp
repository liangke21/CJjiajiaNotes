//Lambda 表达式的组成部分

//ISO C++ 标准展示了作为第三个参数传递给 std::sort() 函数的简单 lambda：

#include <algorithm>
#include <cmath>

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda 表达式开始
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // lambda 表达式结束
    );
}




//https://docs.microsoft.com/zh-cn/cpp/cpp/media/lambdaexpsyntax.png?view=msvc-170
//[] 捕获子句(也称为 c + +规范中的 引导 。)
//
//(float a, float b) 参数列表 可有可无. (也称为 lambda 声明符)
//
//可变规范 可有可无.
//
//异常规范 可有可无.
//
//尾随 - 返回类型 可有可无.
//
//lambda 体。