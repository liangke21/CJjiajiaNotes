#include <iostream>
using namespace std;
int main231() {
	int dim = 10;
	char(*pchar)[100] = new char[dim][100];

	cout << " pchar��ֵ������ָ�� : " << pchar << endl
		<< " pchar��ά����ָ�� " <<&(pchar)[0] << endl
		<< " pcharһά����ָ�� " << &pchar[0];
	
	return 0;
}

//ʾ�������䲢�ͷ��ַ�����

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
	// Ϊ��������ڴ�
	char* pCharArray = new char[CName::sizeOfBuffer];
	strcpy_s(pCharArray, CName::sizeOfBuffer, "Array of characters");

	// Ϊ�����ͷ��ڴ�
	delete[] pCharArray;
	pCharArray = NULL;

	// Ϊ��������ڴ�
	CName* pName = new CName;
	pName->SetName("Firstname", "Lastname");
	//const char* a = "Firstname";
	//const char* b = "Lastname";
	//pName->SetName(a, b);

	// Ϊ�����ͷ��ڴ�
	delete pName;
	pName = NULL;
	return 0;
}