// static2.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class CMyClass {
public:
	static int m_i;
};

int CMyClass::m_i = 5;
CMyClass myObject1;
CMyClass myObject2;

int main21() {
	cout << myObject1.m_i << endl;
	cout << myObject2.m_i << endl;

	myObject1.m_i = 1;
	cout << myObject1.m_i << endl;
	cout << myObject2.m_i << endl;

	myObject2.m_i = 2;
	cout << myObject1.m_i << endl;
	cout << myObject2.m_i << endl;

	CMyClass::m_i = 3;
	cout << myObject1.m_i << endl;
	cout << myObject2.m_i << endl;

	return 0;
}