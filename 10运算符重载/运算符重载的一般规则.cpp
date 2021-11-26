


class Point
{
public:
    Point operator<(Point&);  // 声明一个成员操作符
                                 //  overload.
    // 声明加法运算符。
    friend Point operator+(Point&, int);
    friend Point operator+(int, Point&);
};

int main0201()
{

    return 0;
}


/*
前面的代码示例将小于运算符声明为成员函数；但是，加法运算符被声明为具有友元访问的全局函数。
请注意，可以为给定运算符提供多个实现。 对于前面的加法运算符，将提供两个实现以便于交换。 同样，将添加到的运算符添加到， Point 等等也 Point int Point 可能会实现。

*/