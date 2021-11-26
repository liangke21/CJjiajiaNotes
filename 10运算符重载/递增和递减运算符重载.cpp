#include <iostream>
using namespace std;

class Point
{
public:
	// 声明前缀和后缀增量运算符。
	Point& operator++();       // 前缀增量运算符。
	Point operator++(int);     // 后缀增量运算符。

	// 声明前缀和后缀递减运算符。
	Point& operator--();       // 前缀递减运算符。
	Point operator--(int);     // 后缀递减运算符。

	// 定义默认构造函数。
	Point() { _x = _y = 1; }

	// Define accessor functions.
	int x() { return _x; }
	int y() { return _y; }
private:
	int _x, _y;
};

// 定义前缀增量运算符。
Point& Point::operator++()
{
	_x++;
	_y++;
	return *this;
}

// 定义后缀增量运算符。
Point Point::operator++(int)
{
	Point temp = *this;
	++* this;
	return temp;
}

// 定义前缀递减运算符。
Point& Point::operator--()
{
	_x--;
	_y--;
	return *this;
}

// 定义后缀递减运算符。
Point Point::operator--(int)
{
	Point temp = *this;
	--* this;
	return temp;
}
int main0301()
{
	Point p;

p.operator++(1);

		cout << "p.x : " << p.x() << " p.y : " <<p.y() << endl;

		return 0;

}
/*
friend Point& operator++( Point& )      // Prefix increment
friend Point& operator++( Point&, int ) // Postfix increment
friend Point& operator--( Point& )      // Prefix decrement
friend Point& operator--( Point&, int ) // Postfix decrement
*/

//int 表示递增或递减运算符的后缀形式的类型的参数通常不用于传递参数。 它通常包含值 0。 但是，可按以下方式使用它：

// increment_and_decrement2.cpp
class Int
{
public:
	Int& operator++(int n);

	int git_int() {

		return _i;
	}
private:
	int _i;

	
};

Int& Int::operator++(int n)
{
	if (n != 0)    // 处理传递参数的情况。
		_i += n;
	else
		_i++;       //处理没有传递参数的情况。
	return *this;
}
int main0302()
{
	Int i;
	i.operator++(25); // Increment by 25.
	//i.operator++(0); // Increment by 25.

	cout << i.git_int() << endl;
	return 0;
}