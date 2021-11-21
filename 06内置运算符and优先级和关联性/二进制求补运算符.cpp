// expre_One_Complement_Operator.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
















int main241() {
	unsigned short y = 0xFFFF; // 1111 1111 1111
	cout << hex << y << endl; //fff
	//1的补数运算符 (~) ，有时称为 按位求补 运算符，产生其操作数的按位二进制反码。 即，操作数中为 1 的每个位在结果中为 0。 相反，操作数中为 0 的每个位在结果中为 1。 二进制反码运算符的操作数必须为整型。
	//1111 1111 1111
	//0000 0000 0000

	y = ~y;   // 取自己的补充   
	cout << hex << y << endl;

	return 0;
}