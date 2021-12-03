#include <exception>
#include <iostream>
#include <iostream>
using namespace std;

/*

noexcept-expression是一种noexcept-expression：函数声明的后缀，表示一组类型，对于退出函数的任何异常，这些类型可能由异常处理程序进行匹配。 当 生成 时，一元条件运算符及其无条件同义词 指定可以退出函数的潜在异常类型 noexcept(constant_expression)constant_expressiontruenoexcept 集为空。 也就是说，该函数永远不会引发异常，也永远不会允许异常在其作用域外传播。 当 生成 时， 运算符或除析构函数或释放函数) 之外没有异常规范 (表示可以退出函数的潜在异常集是所有类型的集。 noexcept(constant_expression)constant_expressionfalse

只有当函数调用的所有函数（直接或间接）也是 或 时，才将函数 noexcept 标记为 noexceptconst 。 编译器不一定检查每个代码路径中是否有可能向上冒泡到函数的 noexcept 异常。 如果异常确实退出标记为 的函数的外部作用域，则立即调用 ，并且无法保证将调用任何范围内对象的 noexceptstd::terminate 析构函数。 使用 noexcept 而不是动态异常说明器 throw() 。 动态 异常规范（或规范）在 C++11 中已弃用，在 C++17 中已删除，但 除外，它是 的 throw() 别名 noexcept(true) 。 建议应用于从不允许异常向上传播调用堆栈 noexcept 的任何函数。 声明函数时 noexcept ，它使编译器能够在多个不同的上下文中生成更有效的代码。
*/

//noexcept(bool常量表达式)
class name {
public:
	void func() { throw 1; }

	void func2() noexcept{}
	void func21() noexcept(true){}//以上func 等效

	void func3() noexcept { func(); }
};

int main() {
	name a;
	try
	{
		a.func();
	}
	catch (...)
	{
		cout << "func异常" << endl;
	}


	try
	{
		a.func2();
	}
	catch (...) //不会执行异常 终止程序
	{
		cout << "func2异常" << endl;
	}


	try
	{
		a.func3();
	}
	catch (...) //不会执行异常 终止程序
	{
		cout << "func3异常" << endl;
	}





}