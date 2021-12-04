/*
术语成员模板引用了成员函数模板和嵌套类模板。 
成员函数模板是类或类模板的成员的模板函数。

成员函数可以是多个环境中的函数模板。
类模板的所有函数都是泛型的，但却不称为成员模板或成员函数模板。
如果这些成员函数采用其自己的模板自变量，则将它们视为成员函数模板。
*/
#include <iostream>

using namespace std;

struct X
{
	template <class T> void mf(T* t) {
		cout << t;
	}
};

int main22040601()
{
	int i=10;
	cout << &i<<endl;
	X* x = new X();
	x->mf(&i);

	return 0;
}