

/*
在此示例中，编译器注意到函数 f() 采用了自变量 x。 自变量 x 是命名空间 A::X 中定义的类型 A。 编译器搜索命名空间 A 并查找采用类型 f() 的参数的函数 A::X 的定义。
*/
namespace A
{
	struct X
	{
	};
	void f(const X&)
	{
	}
}
int main0501()
{
	// 编译器在命名空间 A 中找到 A::f()，即
	// 定义了参数 x 的类型。 x 的类型是 A::X。
	A::X x;
	f(x);

	return 0;
}