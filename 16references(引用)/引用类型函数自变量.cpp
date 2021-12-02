



#include <iostream>

struct Date
{
    short Month;
    short Day;
    short Year;
};

// 创建一个格式为 DDDYYYY (day of year, year) 的日期
// 来自日期。
long DateOfYear(const Date& date)
{
    static int cDaysInMonth[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    long dateOfYear = 0;

 // 添加已经过去的月份的天数。
    for (int i = 0; i < date.Month - 1; ++i)
        dateOfYear += cDaysInMonth[i];

// 添加本月的天数。
    dateOfYear += date.Day;

// 检查闰年。
    if (date.Month > 2 &&
        ((date.Year % 100 != 0 || date.Year % 400 == 0) &&
            date.Year % 4 == 0))
        dateOfYear++;

// 添加年份。
    dateOfYear *= 10000;
    dateOfYear += date.Year;

    return dateOfYear;
}

int main0401()
{
    Date date{ 12, 2, 2021};
    long dateOfYear = DateOfYear(date);
    std::cout << dateOfYear << std::endl;



    return 0;
}

/*
尽管作为引用类型传递的参数遵循非指针类型的语法，但它们保留了指针类型的一个重要特征：除非声明为 ，否则它们是可修改的 const 。 由于上述代码的目的不是修改对象 date，因此更合适的函数原型是：

C++

复制
long DateOfYear( const Date& date );
*/