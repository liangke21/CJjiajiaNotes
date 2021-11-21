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

/*
alignas是以指定字节对齐，将完整的变量放在指定对齐数的内存中，
比如按照16字节对齐就是在连续的16字节中，里面的变量都是完整的，
不会出现变量的前两字节在这16字节然后后两字节在接下来16字节中的情况
*/
int main12() {

	cout << "B  : " << alignof(B) << endl;

	cout << "A  : " << alignof(A) << endl;
	return 0;
}