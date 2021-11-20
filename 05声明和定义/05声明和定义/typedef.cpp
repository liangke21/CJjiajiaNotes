#include <iostream>
using namespace std;


int main81()
{
	// typedef_names1.cpp
// C2377 expected
	typedef unsigned long UL;   // 声明一个 typedef 名称，UL。
	//int UL;                     // C2377：重新定义。
	UL a= -1;

	cout << "bool: \t\t" << "所占字节数：" << sizeof(UL);
	cout << "\t最大值：" << (numeric_limits< UL>::max)();
	return 0;

}

// 与其他标识符相关的名称隐藏规则还可控制使用声明的名称的可见性 typedef 。 因此，以下示例在 C++ 中是合法的：
typedef unsigned long UL;   // 声明一个 typedef 名称，UL
int main82()
{
	unsigned int UL;   // 重新声明隐藏 typedef 名称
	return 0;
}

// typedef UL 回到范围内

//typedef 函数声明

typedef void DRAWF(int, int);

DRAWF boox;
int main83()
{
	
	boox(9, 9);

	return 0;
}

void boox(int, int) {

	cout << "你愁啥";
}

// typedef 通常与结合， struct 以声明和命名用户定义的类型：


#include <stdio.h>

typedef struct mystructtag
{
	int   i;
	double f;
} mystruct;

int main84()
{
	mystruct ms;
	ms.i = 10;
	ms.f = 0.99;
	printf_s("%d   %f\n", ms.i, ms.f);

	return 0;
}