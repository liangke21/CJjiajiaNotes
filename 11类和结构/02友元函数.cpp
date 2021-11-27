/*
friend 函数是一个函数，它不是类的成员，但可以访问类的私有和受保护成员。 友元函数不被视为类成员；它们是获得了特殊访问权限的普通外部函数。 友元不在类的范围内，并且不是使用成员选择运算符 (来调用的 。 和- >) ，除非它们是另一个类的成员。 friend 函数由授予访问权限的类声明。 friend 声明可放置在类声明中的任何位置。 它不受访问控制关键字的影响。
*/

//以下示例显示 Point 类和友元函数 ChangePrivate。 friend 函数有权访问作为参数接收的对象的私有数据成员 Point 。
#include <iostream>

using namespace std;
class Point
{
    friend void ChangePrivate(Point&); //声明一个友元函数
public:
    Point(void) : m_i(0) {}
    void PrintPrivate(void) { cout << m_i << endl; }

private:
    int m_i;
};

void ChangePrivate(Point& i) { i.m_i++; } //定义函数

int main05020201()
{
    Point sPoint;
    sPoint.PrintPrivate();
    ChangePrivate(sPoint); //引用函数
    sPoint.PrintPrivate();
    // Output: 0
    1;

    return 0;
}