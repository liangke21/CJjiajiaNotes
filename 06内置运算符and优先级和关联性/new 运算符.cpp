#include <iostream>
using namespace std;
int main231() {
	int dim = 10;
	char(*pchar)[100] = new char[dim][100];

	cout << " pchar左值变量的指针 : " << pchar << endl
		<< " pchar二维数组指针 " <<&(pchar)[0] << endl
		<< " pchar一维数组指针 " << &pchar[0];
	
	return 0;
}

//示例：分配并释放字符数组

// expre_new_Operator.cpp
// compile with: /EHsc
#include <string.h>

class CName {
public:
	enum {
		sizeOfBuffer = 256
	};

	char m_szFirst[sizeOfBuffer];
	char m_szLast[sizeOfBuffer];

public:
	void SetName(const char* pszFirst, const char* pszLast) {
		strcpy_s(m_szFirst, sizeOfBuffer, pszFirst);
		strcpy_s(m_szLast, sizeOfBuffer, pszLast);
	}

};

int main232() {
	// 为数组分配内存
	char* pCharArray = new char[CName::sizeOfBuffer];
	strcpy_s(pCharArray, CName::sizeOfBuffer, "Array of characters");

	// 为数组释放内存
	delete[] pCharArray;
	pCharArray = NULL;

	// 为对象分配内存
	CName* pName = new CName;
	pName->SetName("Firstname", "Lastname");
	//const char* a = "Firstname";
	//const char* b = "Lastname";
	//pName->SetName(a, b);

	// 为对象释放内存
	delete pName;
	pName = NULL;
	return 0;
}