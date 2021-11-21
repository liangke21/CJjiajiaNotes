/*
按位 "异或" 运算符 (|) 将其第一个操作数的每个位与其第二操作数的相应位进行比较。 
如果其中一个位是 1，则将对应的结果位设置为 1。 否则，将对应的结果位设置为 0。
*/

// expre_Bitwise_Inclusive_OR_Operator.cpp
// compile with: /EHsc
// Demonstrate bitwise inclusive OR
#include <iostream>
using namespace std;

int main09() {
	unsigned short a = 0x5555;      // pattern 0101 ...
	unsigned short b = 0xAAAA;      // pattern 1010 ...

	cout << hex << (a | b) << endl;   // prints "ffff" pattern 1111 ...

	return 0;
}