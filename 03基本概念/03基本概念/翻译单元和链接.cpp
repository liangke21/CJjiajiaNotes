//������Ʊ�ʾһ���������������������ʽ��ʼ����
#include<iostream>;
//����
int i3;
int f(int x);
class C;

//����
int i2{ 42 };
int f2(int x) { return x * i2; }
using namespace std;
class C2 {
	
public:
	void DoSomething3() {
		cout << "DoSomething3 : "<< endl;
	};
};
using namespace std;
int main42()
{
	class C2 c;
	c.DoSomething3();
	i2 = 20;
	cout << "i2 : " << i2 << endl;
	cout << "f2 : " << f2 << endl;
	cout << "f2 : " << f2(20) << endl;

	return 0;
	
}