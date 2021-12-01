#include <iostream>

/*
可能需要的数组太大，无法在堆栈上分配，或者其大小在编译时是未知的。 
通过使用表达式，可以在堆上分配此数组 new[] 。 运算符返回指向第一个元素的指针。
下标运算符在指针变量上的工作方式与它在基于堆栈的数组中的工作方式相同。
还可以使用 指针算法 将指针移动到数组中的任意元素。 你有责任确保：

始终保留原始指针地址的副本，以便在不再需要数组时可以删除内存。
不会递增或递减超出数组界限的指针地址。
下面的示例演示如何在运行时在堆上定义一个数组。 它演示了如何使用下标运算符和使用指针算法访问数组元素：
*/

void do_something(size_t size)
{
    // 声明要在堆上分配的双精度数组
    double* numbers = new double[size] { 0 };  //new 出来的数组

    // 为第一个元素分配一个新值
    numbers[0] = 1;

// 为每个后续元素赋值
    // (numbers[1] 是数组中的第二个元素。)
    for (size_t i = 1; i < size; i++)
    {
        numbers[i] = numbers[i - 1] * 1.1;
    }

// 使用下标运算符访问每个元素
    for (size_t i = 0; i < size; i++)
    {
        std::cout << numbers[i] << " ";
    }

// 使用指针算法访问每个元素
    // 使用指针的副本进行迭代
    double* p = numbers;

    for (size_t i = 0; i < size; i++)
    {
// 取消引用指针，然后增加它
        std::cout << *p++ << " ";
    }

// 替代方法：
    // 将 p 重置为数字 [0]:
    p = numbers;

// 使用指针地址计算边界。
    // 编译器将大小计算为数字
    // 元素 *（每个元素的字节数）。
    while (p < (numbers + size))
    {
     // 取消引用指针，然后增加它
        std::cout << *p++ << " ";
    }

    delete[] numbers; // 不要忘记这样做！

}
int main0201()
{
    do_something(108);

    return 0;
}