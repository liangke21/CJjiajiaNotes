#include <iostream>


/*
当数组传递到函数时，它将作为指向第一个元素的指针传递，无论它是基于堆栈还是基于堆的数组。
指针不包含其他大小或类型信息。 此行为称为 指针衰减。 将数组传递给函数时，
必须始终在单独的参数中指定元素数。 此行为还意味着数组元素传递到函数时不会复制。
若要防止函数修改元素，请将参数指定为指向元素的指针 const 。

下面的示例演示了一个函数，该函数接受一个数组和一个长度。
指针指向原始数组，而不是副本。 由于参数不为 const ，因此函数可以修改数组元素。
*/

void process(double* p, const size_t len)
{
    std::cout << "process:\n";
    for (size_t i = 0; i < len; ++i)
    {
        // 用 p 做点什么[i]
    }
}

//声明数组参数，并将 p 其定义为 const ，使其在函数块中为只读：

void process(const double* p, const size_t len);

//也可以通过这些方式声明同一函数，不会更改行为。 数组仍作为指向第一个元素的指针传递：

// 未定大小的数组
void process2(const double p[], const size_t len);

// 固定大小的数组。长度仍必须明确指定。
void process3(const double p[1000], const size_t len);