// expre_Bitwise_AND_Operator.cpp
// compile with: /EHsc
// Demonstrate bitwise AND
#include <iostream>
using namespace std;
int main() {
	unsigned short a = 0xFFFF;      // pattern 1111 1111 1111 1111


	unsigned short b = 0xAAAA;      // pattern 1010 1010 1010 1010
	unsigned short c = 0xAAAb;      // pattern 1010 1010 1010 1011 
	/*cout << hex << a << endl;
	cout << hex << b << endl;
	cout << hex << c<< endl;*/

	//cout << hex << (a & b) << endl;   // ��ӡ��aaaa����ͼ�� 1010...

	cout << hex << (c & b) << endl;   // ��ӡ��aaaa����ͼ�� 1010...

	return 0;
}