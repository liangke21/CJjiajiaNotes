
//typename在模板定义中使用限定名，告诉编译器给定的限定名称标识类型。 有关详细信息，请参阅 类型名称。

#include <stdio.h>
template <class T> class X
{
public:
	void f(typename T::myType* mt) {}
};

class Yarg
{
public:
	struct myType { };
};

int main22060201()
{
	X<Yarg> x;
	x.f(new Yarg::myType());
	printf("使用 typename 关键字解析的名称.");
	return 0;
}

/*
相关名称的名称查找从模板定义的上下文中检查名称-在下面的示例中，
此上下文会发现 myFunction(char) 和模板实例化的上下文。
在下面的示例中，模板在 main 中实例化;因此，
在 MyNamespace::myFunction 实例化点可见，
并将其选取为更好的匹配项。 如果重命名 MyNamespace::myFunction，则将调用 myFunction(char)。


所有名称都会得到解析，就如同它们是依赖名称一样。 尽管如此，如果存在任何可能的冲突，建议您使用完全限定名。
*/


#include <iostream>
using namespace std;

void myFunction(char)
{
	cout << "Char myFunction" << endl;
}

template <class T> class Class1
{
public:
	Class1(T i)
	{
		// 如果替换为我的函数（1），我的函数（字符）
        // 将被调用
		myFunction(i);
	}
};

namespace MyNamespace
{
	void myFunction(int)
	{
		cout << "Int MyNamespace::myFunction" << endl;
	}
};

using namespace MyNamespace;

int main22060202()
{
	Class1<int>* c1 = new Class1<int>(100);
	return 0;
}