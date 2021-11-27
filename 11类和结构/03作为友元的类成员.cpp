

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

	// A::Func1 是 B 类的友元函数
	// so A::Func1 可以访问 B 的所有成员
	friend int A::Func1(B&);
	// so A::Func2 可以访问 B 的所有成员
	//friend int A::Func2(B&);
};

int A::Func1(B& b) { return b._b; }   // OK
//int A::Func2(B& b) { return b._b; }   // C2248

int main05020301() {

	return 0;
}




//在这种情况下，将为类 A 中所有成员函数授予对类 B 的友元访问权限。 以下代码是友元类的示例：
#include <iostream>

using namespace std;
class YourClass {
	friend class YourOtherClass;  // 声明一个朋友类
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