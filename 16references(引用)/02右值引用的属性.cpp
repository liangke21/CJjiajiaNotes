/*
通过重载函数来采用左值 const 引用或右值引用，
你可以编写代码来区分不可修改的对象 (左值) 和可修改的临时值 (右) 。
如果对象被标记为，则可以将对象传递到采用右值引用的函数 const 。
以下示例演示了函数 f，该函数将被重载以采用左值引用和右值引用。
main 函数同时使用左值和右值来调用 f。

*/



#include <iostream>
using namespace std;

// 包含内存资源的类。
class MemoryBlock
{
	// TODO: 在此处为班级添加资源。
};

void f(const MemoryBlock&)
{
	cout << "在 f(const Memory Block&amp;) 中。这个版本不能修改参数." << endl;
}

void f(MemoryBlock&&)
{
	cout << "在 f（内存块&amp;&amp;）中。这个版本可以修改参数." << endl;
}

int main030201()
{
	MemoryBlock block;
	f(block); //不能修改参数
	f(MemoryBlock());//可以修改参数

	return 0;
}




namespace aa {


#include <iostream>
using namespace std;

// 包含内存资源的类。
class MemoryBlock
{
	// TODO: 在此处为班级添加资源。
};

void g(const MemoryBlock&)
{
	cout << "在 g(const Memory Block&amp;) 中。" << endl;
}

void g(MemoryBlock&&)
{
	cout << "In g(MemoryBlock&&)." << endl;
}

MemoryBlock&& f(MemoryBlock&& block)
{
	g(block);
	return move(block);
}

}
int main030202()
{
	using namespace aa;

	aa::g(f(aa::MemoryBlock()));//In g(MemoryBlock&&).

	return 0;
}







// cast-reference.cpp
// Compile with: /EHsc
#include <iostream>
namespace bb {



// A class that contains a memory resource.
class MemoryBlock
{
	// TODO: Add resources for the class here.
};

void g(const MemoryBlock&)
{
	cout << "In g(const MemoryBlock&)." << endl;
}

void g(MemoryBlock&&)
{
	cout << "In g(MemoryBlock&&)." << endl;
}
}
int main0302()
{
	using namespace bb;

	bb::MemoryBlock block;
	g(block);//In g(const MemoryBlock&)
	g(static_cast<bb::MemoryBlock&&>(block));//In g(MemoryBlock&&).

	return 0;
}



