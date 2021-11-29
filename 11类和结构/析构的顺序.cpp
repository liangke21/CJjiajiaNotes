
/*
当对象超出范围或被删除时，其完整析构中的事件序列如下所示：

将调用该类的析构函数，并且会执行该析构函数的主体。

按照非静态成员对象的析构函数在类声明中的显示顺序的相反顺序调用这些函数。 构造这些成员时使用的可选成员初始化列表不会影响构造或析构的顺序。

非虚拟基类的析构函数以声明的相反顺序调用。

虚拟基类的析构函数以声明的相反顺序被调用。
*/



#include <cstdio>

struct A1 { virtual ~A1() { printf("A1 dtor\n"); } };
struct A2 : A1 { virtual ~A2() { printf("A2 dtor\n"); } };
struct A3 : A2 { virtual ~A3() { printf("A3 dtor\n"); } };

struct B1 { ~B1() { printf("B1 dtor\n"); } };
struct B2 : B1 { ~B2() { printf("B2 dtor\n"); } };
struct B3 : B2 { ~B3() { printf("B3 dtor\n"); } };

int main1102() {
	A1* a = new A3;
	delete a;
	printf("\n");

	B1* b = new B3;
	delete b;
	printf("\n");

	B3* b2 = new B3;
	delete b2;
	return 0;
}

//A3 dtor
//A2 dtor
//A1 dtor
//
//B1 dtor
//
//B3 dtor
//B2 dtor
//B1 dtor