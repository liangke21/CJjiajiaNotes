// expre_Bitwise_Exclusive_OR_Operator.cpp
// compile with: /EHsc
// Demonstrate bitwise exclusive OR
#include <iostream>
/*
��λ��ռ OR ����� () ��һ����������ÿ��λ��ڶ������� ^ ������Ӧλ���бȽϡ�
�������һ���������е�λΪ 0����һ���������е�λΪ 1������Ӧ�Ľ��λ����Ϊ 1�� 
���򣬽���Ӧ�Ľ��λ����Ϊ 0��
*/

using namespace std;
int main7() {
	unsigned short a = 0x5555;      // pattern 0101 ...
	unsigned short b = 0xFFFF;      // pattern 1111 ...

	cout << hex << (a ^ b) << endl;   // prints "aaaa" pattern 1010 ...
	return 0;
}