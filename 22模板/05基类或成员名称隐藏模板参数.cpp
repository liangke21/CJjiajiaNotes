
/*
在位于模板类声明之外的定义中，如果模板类具有不依赖于模板自变量的基类，并且该基类或其成员之一与模板自变量的名称相同，则该基类或成员名称将隐藏模板自变量。
*/

#include <iostream>
using namespace std;

struct B {
	int i;
	void print() { cout << "Base" << endl; }
};

template <class T, int i> struct C : public B {
	void f();
};

template <class B, int i>
void C<B, i>::f() {
	B b;   // 基类 b，而不是模板参数。
	b.print();
	i = 1; // 将基类的 i 设置为 1.
}

int main2206030501() {
	C<int, 1> c;
	c.f();
	cout << c.i << endl;

	return 0;
}