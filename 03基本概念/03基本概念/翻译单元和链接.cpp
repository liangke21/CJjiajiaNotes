//如果名称表示一个变量，则定义会对其进行显式初始化。
#include<iostream>;
//声明
int i3;
int f(int x);
class C;

//定义
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