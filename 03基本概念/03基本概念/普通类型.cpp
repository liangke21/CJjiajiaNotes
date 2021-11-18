#include <iostream>
using namespace std;
//普通类型
struct Trivial
{
	int i;
private:
	int j;
};

struct Trivial2
{
	int i;
	Trivial2(int a, int b) : i(a), j(b) {}
	Trivial2() = default;
private:
	int j;   // 不同的访问控制

	
};
int main101()
{
	Trivial2(30, 14);

		cout << "rivial2 : " << Trivial2().i;

	return 0;
}

//标准布局类型
struct SL
{
	// All members have same access:
	int i;
	int j;
	SL(int a, int b) : i(a), j(b) {} // 用户定义的构造函数 OK
};



#include <type_traits>
#include <iostream>

using namespace std;

struct B
{
protected:
	virtual void Foo() {}
};

// 既不平凡也不标准布局
struct A : B
{
	int a;
	int b;
	void Foo() override {} // 虚函数
};

// 微不足道但不是标准布局
struct C
{
	int a;
private:
	int b;   //不同的访问控制
};

// 标准布局但并非微不足道
struct D
{
	int a;
	int b;
	D() {} //用户定义的构造函数
};

struct POD
{
	int a;
	int b;
};

int main102()
{
	cout << boolalpha;
	cout << "A 是微不足道的 " << is_trivial<A>() << endl; // false
	cout << "A 是标准布局 is " << is_standard_layout<A>() << endl;  // false

	cout << "C是微不足道的是 " << is_trivial<C>() << endl; // true
	cout << "C是标准布局是 " << is_standard_layout<C>() << endl;  // false

	cout << "D 是微不足道的" << is_trivial<D>() << endl;  // false
	cout << "D 是标准布局是 " << is_standard_layout<D>() << endl; // true

	cout << "POD 是微不足道的 " << is_trivial<POD>() << endl; // true
	cout << "POD 是标准布局是 " << is_standard_layout<POD>() << endl; // true

	return 0;
}