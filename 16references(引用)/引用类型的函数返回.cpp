






/*
可将函数声明为返回引用类型。 做出此类声明有两个原因：

返回的信息是一个返回引用比返回副本更有效的足够大的对象。

函数的类型必须为左值。

引用的对象在函数返回时不会超出范围。

正如按引用将大型对象传递给函数更高效一样，按引用从函数返回大型对象也会更高效。 引用返回协议使得不必在返回前将对象复制到临时位置。

当函数的计算结果必须为左值时，引用返回类型也可能很有用。 大多数重载运算符属于此类别，尤其是赋值运算符。 重载运算符 中介绍了 重载运算符。
*/
#include <iostream>
using namespace std;

class Point
{
public:
// 将“访问器”函数定义为
// 引用类型。
	unsigned& x();
	unsigned& y();
private:
	// 请注意，这些是在类范围内声明的：
	unsigned obj_x;
	unsigned obj_y;
};

unsigned& Point::x()
{
	return obj_x;
}
unsigned& Point::y()
{
	return obj_y;
}

int main0501()
{
	Point ThePoint;
	// 使用 x() 和 y() 作为左值。
	ThePoint.x() = 7;
	ThePoint.y() = 9;

	// 使用 x() 和 y() 作为 r 值。
	cout << "x = " << ThePoint.x() << "\n"
		<< "y = " << ThePoint.y() << "\n";

	return 0;
}