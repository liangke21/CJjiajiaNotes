#include <stdlib.h>


int main131()
{
	long  long_num1, long_num2;
	int   int_num;

	// int num 在赋值之前提升为 long 类型。
//	long_num1 = int_num;  

	//int num 在乘法之前提升为 long 类型。
	//long_num2 = int_num * long_num2; 
	exit(0);
}
//有符号转换为无符号
#include <iostream>
//有符号转换为无符号
using namespace std;
int main132()
{
	short  i = -3;
	unsigned short u;

	cout << (u = i) << "\n";
	exit(0);
}
// Output: 65533

//类型转换的条件

double dVal;
float fVal;
int iVal;
unsigned long ulVal;

int main133() {
	// 我 Val 转换为 unsigned long
	// 乘法结果转换为双精度
	//dVal = iVal * ulVal;

	// ul Val 转换为浮点数
	// 加法结果转换为双精度
	//dVal = ulVal + fVal;
	exit(0);
}

//指向类的指针
// C2039 expected
class A
{
public:
	int AComponent;
	int AMemberFunc();
};

class B : public A
{
public:
	int BComponent;
	int BMemberFunc();
};
int main134()
{
	B bObject;
	A* pA = &bObject;
	B* pB = &bObject;

	//pA->AMemberFunc();   // OK in class A
	//pB->AMemberFunc();   // OK: inherited from class A
	//pA->BMemberFunc();   //错误：不在 A 类中
	exit(0);
}
//指针表达式转换
char szPath[_MAX_PATH]; // Array of type char.
char* pszPath = szPath; // Equals &szPath[0].

//指向成员转换的 null 指针
class Ab
{
public:
	int i;
};

int Ab::* pai = 0;



int main()
{
	exit(0);
}