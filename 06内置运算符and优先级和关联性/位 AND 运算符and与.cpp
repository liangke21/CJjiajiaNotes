// expre_Bitwise_AND_Operator.cpp
// compile with: /EHsc
// Demonstrate bitwise AND
#include <iostream>
//按位 AND 运算符 () 操作数的每个位和第二个操作数的相应 & 位进行比较。
//如果两个位均为 1，则对应的结果位将设置为 1。 否则，将对应的结果位设置为 0。
using namespace std;
int main6() {
	unsigned short a = 0xFFFF;      // pattern 1111 1111 1111 1111


	unsigned short b = 0xAAAA;      // pattern 1010 1010 1010 1010
	unsigned short c = 0xAAAb;      // pattern 1010 1010 1010 1011 
	/*cout << hex << a << endl;
	cout << hex << b << endl;
	cout << hex << c<< endl;*/

	//cout << hex << (a & b) << endl;   // 打印“aaaa”，图案 1010...

	cout << hex << (c & b) << endl;   // 打印“aaaa”，图案 1010 1010 1010 1010

	

	return 0;
}