#include <iostream>

using namespace std;

typedef struct {
	int a;double b; int c; int d;int e;
	char f;
	char g;
	char h;
	char j;
	char k;
} S;
//alignof 值与 sizeof 用于基本类型的值相同
int main1() {
		S ms;
		///ms.a = 3;
		//ms.b = 3.4;
	
	
//	cout << "int : " << ms.a<< endl; //语法错误标识符
	cout << "S : " << alignof(S) << endl;   //对齐为 8个字节
	cout << "S : " << sizeof(S) << endl<<endl;  

	cout << "int : " << alignof(int) << endl;
	cout << "int : " << sizeof(int) << endl;
		return 0;
}

typedef __declspec(align(32)) struct { int a; } A;  //



struct alignas(16) B //最大值的说明符
{
	int i;       // 4 bytes
	int n;      // 4 bytes
	alignas(4) char arr[3];
	short s;          // 2 bytes
};
int main() {

	cout << "B  : " << alignof(B) << endl;

	cout << "A  : " << alignof(A) << endl;
	return 0;
}