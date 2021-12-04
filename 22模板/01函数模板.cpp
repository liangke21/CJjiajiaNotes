#include <string>
using namespace std;



template< class T > void MySwap(T& a, T& b) {
	T c(a);
	a = b;
	b = c;
}
int main2204010101() {

	int j = 10;
	int k = 18;
	string Hello = "Hello, Windows!";
	MySwap(j, k);          //OK
	//MySwap(j, Hello);      //error

	return 0;
}
//第二个 MySwap 调用触发了编译时错误，因为编译器无法生成具有不同类型的参数的 MySwap 函数。 如果使用了 void 指针，两个函数调用都将正确编译，但函数在运行时无法正常工作。


// function_templates2.cpp
template<class T> void f(T) {}
int main2204010102(int j) {
	f<char>(j);   // 生成专业 f(char).
	// 如果没有明确指定, f(int) 会被推导出来。

	return 0;
}