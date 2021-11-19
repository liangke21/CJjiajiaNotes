//const 关键字还可以在指针声明中使用

// constant_values3.cpp
#include <iostream>
using namespace std;
int main4() {
	char a = 'b';
	char* mybuf = &a, * yourbu = mybuf;
	char* const aptr = mybuf;
	*aptr = 'a';   // OK
	cout << "aptr : " << *aptr<<endl;
	*aptr = 'b';
	cout << "aptr : " << *aptr << endl;
	//aptr = yourbuf;   // C3892
	return 0;

}

// constant_values4.cpp
#include <stdio.h>
int main5() {
	const char* mybuf = "test";
	//char* yourbuf = "test2";

	printf_s("%s\n", mybuf);

	const char* bptr = mybuf;   // Pointer to constant data
	printf_s("%s\n", bptr);

	// *bptr = 'a';   // Error
	return 0;
}


// constant_member_function.cpp
//class Date
//{
//public:
//	Date(int mn, int dy, int yr);
//	int getMonth() const;     //只读函数
//	void setMonth(int mn) ;   // 一个写函数；不能是常量
//private:
//	int month;
//};
//
//int Date::getMonth() const
//{
//	return month;        // Doesn't modify anything
//}
//void Date::setMonth(int mn) 
//{
//	month = mn;          // Modifies data member
//}
//int main52()
//{
//	//Date MyDate(7, 4, 1998);
//	const Date BirthDate(1, 18, 1953);
//	//MyDate.setMonth(4);    // Okay
//	//BirthDate.getMonth();    // Okay
//	//BirthDate.setMonth(4); // C2662 Error
//	return 0;
//}