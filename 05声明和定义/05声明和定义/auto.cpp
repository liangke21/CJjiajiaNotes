//auto 初始化表达式可以采用多种形式

#include <iostream>
using namespace std;
int main3() {

	auto a{ 4 };

	cout << "a : " << a << endl;

	auto b = 5;
	cout << "b : " << b << endl;

	auto c = { 6 };
	//cout << "c : " << c << endl;

	auto d(44);
	cout << "d : " << d << endl;
	return 0;
}
//引用和 cv 限定符
// cl.exe /analyze /EHsc /W4
#include <iostream>

using namespace std;

int main31()
{
	int count = 10;
	int& countRef = count;
	auto myAuto = countRef;

	countRef = 11;
	cout << count << " ";

	myAuto = 12;
	cout << count << endl;
	return 0;
}

//用大括号内初始值设定项进行类型推导(c + +14)

#include <initializer_list>

int main32()
{
	// std::initializer_list<int>
	auto A = { 1, 2 };

	// std::initializer_list<int>
	auto B = { 3 };

	// int
	auto C{ 4 };

	// C3535: 无法从初始化列表中推导出“自动”的类型
	//auto D = { 5, 6.7 };

	// C3518 在直接列表初始化上下文中，&#39;auto&#39; 的类型
	// 只能从一个初始化表达式中推导出来
	//auto E{ 8, 9 };

	return 0;
}

//int j = 0;  // 变量 j 是显式类型 int。
auto k = 0; // 变量 k 是隐式类型 int，因为 0 是一个整数。

//以下声明等效，但第二个声明比第一个更简单。 使用关键字的最有说服力的原因之一 auto 是简单的。
//map<int, list<string>>::iterator i = m.begin();
//auto i = m.begin();

//iter elem 当 for 和范围 for 循环开始时，以下代码段将声明变量的类型。

// cl /EHsc /nologo /W4
#include <deque>
#include <deque>
using namespace std;

int main33()
{
	deque<double> dqDoubleData(10, 0.1);

	for (auto iter = dqDoubleData.begin(); iter != dqDoubleData.end(); ++iter)
	{ /* ... */
	}

	// 考虑到以下信息，更喜欢 range-for 循环
	// (这适用于任何带自动的范围，而不仅仅是双端队列)

	for (auto elem : dqDoubleData) // COPIES 元素，比前面的例子好不了多少
	{ /* ... */
		cout << "elem : " << elem << endl;
	}

	for (auto& elem : dqDoubleData) // 就地观察和/或修改元素
	{ /* ... */
		//cout << "elem : " << elem << endl;
	}

	for (const auto& elem : dqDoubleData) // 就地观察元素
	{ /* ... */
		//cout << "elem : " << elem << endl;
	}
	return 0;
}

int main341()
{

	double x = 12.34;
	auto* y = new auto(x), ** z = new auto(&x);

	cout << "x自身的指针 : " <<&x << endl;

	cout << "new auto double 变量的的指针 : " << y << endl;

	cout << "y自身的指针 : " << &y << endl;

	cout << "new auto对象接收一个x变量的指针 : " << *z << endl;

	cout << "new auto对象推断double 的指针 : " << z << endl;

	cout << "z自身的指针 : " << &z << endl;

	cout << "z指针上的值 : " << **z << endl;
	return 0;
}

int main35()
{

	auto x = 1, * y = &x, ** z = &y; // Resolves to int.
	auto a(2.01), * b(&a);         // Resolves to double.
	auto c = 'a', * d(&c);          // Resolves to char.
	auto m = 1, & n = m;  
	// Resolves to int.

	cout << &x << "==" << y << endl;

	cout << &y << "==" << z << endl;


	return 0;
}

//此代码片段使用条件运算符 (?:) 将变量 x 声明为值为 200 的整数：

int main36()
{
	int v1 = 100, v2 = 200;
	auto x = v1 > v2 ? v1 : v2;

	cout << x;
	return 0;
}
//下面的代码片段将变量初始化 x 为类型，将变量引用为对类型的 int 引用，并将变量初始化为指向 y const int fp 返回类型的函数的指针 int 。
int f2(int x) { return x; }
int main37()
{
	auto x = f2(0);
	const auto& y = f2(1);
	int (*p)(int x);
	p = f2;
	auto fp = p;
	return 0;
}