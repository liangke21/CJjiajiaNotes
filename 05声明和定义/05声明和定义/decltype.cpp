
#include<iostream>

using namespace std;

int fun1() {
	return 4;
}

auto fun2() {

	return 'a';    //假如把这里改成 4 那么类型就会推导为int类型
}
//在编译时推导一个表达式的类型,而不用初始化,
int main11() {

	decltype(fun1()) x;
	decltype(fun2()) y = fun2();

	cout << typeid(x).name() << endl;
	cout << typeid(y).name() << endl;

	//typeid() 打印类型

	return 0;
}