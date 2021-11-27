

// classes_as_friends1.cpp
// compile with: /c
class B;

class A {
public:
	int Func1(B& b);

private:
	int Func2(B& b);
};

class B {
private:
	int _b;

	// A::Func1 �� B �����Ԫ����
	// so A::Func1 ���Է��� B �����г�Ա
	friend int A::Func1(B&);
	// so A::Func2 ���Է��� B �����г�Ա
	//friend int A::Func2(B&);
};

int A::Func1(B& b) { return b._b; }   // OK
//int A::Func2(B& b) { return b._b; }   // C2248

int main05020301() {

	return 0;
}




//����������£���Ϊ�� A �����г�Ա����������� B ����Ԫ����Ȩ�ޡ� ���´�������Ԫ���ʾ����
#include <iostream>

using namespace std;
class YourClass {
	friend class YourOtherClass;  // ����һ��������
public:
	YourClass() : topSecret(0) {}
	void printMember() { cout << topSecret << endl; }
private:
	int topSecret;
};

class YourOtherClass {
public:
	void change(YourClass& yc, int x) { yc.topSecret = x; }
};

int main05020302() {
	YourClass yc1;
	YourOtherClass yoc1;
	yc1.printMember();//0
	yoc1.change(yc1, 5);
	yc1.printMember();//5

	return 0;
}