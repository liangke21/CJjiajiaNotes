// expre_Bitwise_Exclusive_OR_Operator.cpp
// compile with: /EHsc
// Demonstrate bitwise exclusive OR
#include <iostream>
/*
按位独占 OR 运算符 () 第一个操作数的每个位与第二个操作 ^ 数的相应位进行比较。
如果其中一个操作数中的位为 0，另一个操作数中的位为 1，则相应的结果位设置为 1。 
否则，将对应的结果位设置为 0。
*/

using namespace std;
int main7() {
	unsigned short a = 0x5555;      // pattern 0101 ...
	unsigned short b = 0xFFFF;      // pattern 1111 ...

	cout << hex << (a ^ b) << endl;   // prints "aaaa" pattern 1010 ...
	return 0;
}