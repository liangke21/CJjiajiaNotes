#include <iostream>
using namespace std;
//��ͨ����
struct Trivial
{
	int i;
private:
	int j;
};

struct Trivial2
{
	int i;
	Trivial2(int a, int b) : i(a), j(b) {}
	Trivial2() = default;
private:
	int j;   // ��ͬ�ķ��ʿ���

	
};
int main101()
{
	Trivial2(30, 14);

		cout << "rivial2 : " << Trivial2().i;

	return 0;
}

//��׼��������
struct SL
{
	// All members have same access:
	int i;
	int j;
	SL(int a, int b) : i(a), j(b) {} // �û�����Ĺ��캯�� OK
};



#include <type_traits>
#include <iostream>

using namespace std;

struct B
{
protected:
	virtual void Foo() {}
};

// �Ȳ�ƽ��Ҳ����׼����
struct A : B
{
	int a;
	int b;
	void Foo() override {} // �麯��
};

// ΢����������Ǳ�׼����
struct C
{
	int a;
private:
	int b;   //��ͬ�ķ��ʿ���
};

// ��׼���ֵ�����΢�����
struct D
{
	int a;
	int b;
	D() {} //�û�����Ĺ��캯��
};

struct POD
{
	int a;
	int b;
};

int main()
{
	cout << boolalpha;
	cout << "A ��΢������� " << is_trivial<A>() << endl; // false
	cout << "A is standard-layout is " << is_standard_layout<A>() << endl;  // false

	cout << "C is trivial is " << is_trivial<C>() << endl; // true
	cout << "C is standard-layout is " << is_standard_layout<C>() << endl;  // false

	cout << "D is trivial is " << is_trivial<D>() << endl;  // false
	cout << "D is standard-layout is " << is_standard_layout<D>() << endl; // true

	cout << "POD is trivial is " << is_trivial<POD>() << endl; // true
	cout << "POD is standard-layout is " << is_standard_layout<POD>() << endl; // true

	return 0;
}