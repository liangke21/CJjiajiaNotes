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
//alignof ֵ�� sizeof ���ڻ������͵�ֵ��ͬ
int main1() {
		S ms;
		///ms.a = 3;
		//ms.b = 3.4;
	
	
//	cout << "int : " << ms.a<< endl; //�﷨�����ʶ��
	cout << "S : " << alignof(S) << endl;   //����Ϊ 8���ֽ�
	cout << "S : " << sizeof(S) << endl<<endl;  

	cout << "int : " << alignof(int) << endl;
	cout << "int : " << sizeof(int) << endl;
		return 0;
}

typedef __declspec(align(32)) struct { int a; } A;  //



struct alignas(16) B //���ֵ��˵����
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