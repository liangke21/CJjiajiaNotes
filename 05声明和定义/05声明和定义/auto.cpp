//auto ��ʼ�����ʽ���Բ��ö�����ʽ

#include <iostream>
using namespace std;
int main3() {

	auto a{ 4 };

	cout << "a : " << a << endl;

	auto b = 5;
	cout << "b : " << b << endl;

	auto c = { 6 };
	//cout << "c : " << c << endl;

	auto d(44);
	cout << "d : " << d << endl;
	return 0;
}
//���ú� cv �޶���
// cl.exe /analyze /EHsc /W4
#include <iostream>

using namespace std;

int main31()
{
	int count = 10;
	int& countRef = count;
	auto myAuto = countRef;

	countRef = 11;
	cout << count << " ";

	myAuto = 12;
	cout << count << endl;
	return 0;
}

//�ô������ڳ�ʼֵ�趨����������Ƶ�(c + +14)

#include <initializer_list>

int main32()
{
	// std::initializer_list<int>
	auto A = { 1, 2 };

	// std::initializer_list<int>
	auto B = { 3 };

	// int
	auto C{ 4 };

	// C3535: �޷��ӳ�ʼ���б����Ƶ������Զ���������
	//auto D = { 5, 6.7 };

	// C3518 ��ֱ���б��ʼ���������У�&#39;auto&#39; ������
	// ֻ�ܴ�һ����ʼ�����ʽ���Ƶ�����
	//auto E{ 8, 9 };

	return 0;
}

//int j = 0;  // ���� j ����ʽ���� int��
auto k = 0; // ���� k ����ʽ���� int����Ϊ 0 ��һ��������

//����������Ч�����ڶ��������ȵ�һ�����򵥡� ʹ�ùؼ��ֵ�����˵������ԭ��֮һ auto �Ǽ򵥵ġ�
//map<int, list<string>>::iterator i = m.begin();
//auto i = m.begin();

//iter elem �� for �ͷ�Χ for ѭ����ʼʱ�����´���ν��������������͡�

// cl /EHsc /nologo /W4
#include <deque>
#include <deque>
using namespace std;

int main33()
{
	deque<double> dqDoubleData(10, 0.1);

	for (auto iter = dqDoubleData.begin(); iter != dqDoubleData.end(); ++iter)
	{ /* ... */
	}

	// ���ǵ�������Ϣ����ϲ�� range-for ѭ��
	// (���������κδ��Զ��ķ�Χ������������˫�˶���)

	for (auto elem : dqDoubleData) // COPIES Ԫ�أ���ǰ������Ӻò��˶���
	{ /* ... */
		cout << "elem : " << elem << endl;
	}

	for (auto& elem : dqDoubleData) // �͵ع۲��/���޸�Ԫ��
	{ /* ... */
		//cout << "elem : " << elem << endl;
	}

	for (const auto& elem : dqDoubleData) // �͵ع۲�Ԫ��
	{ /* ... */
		//cout << "elem : " << elem << endl;
	}
	return 0;
}

int main341()
{

	double x = 12.34;
	auto* y = new auto(x), ** z = new auto(&x);

	cout << "x�����ָ�� : " <<&x << endl;

	cout << "new auto double �����ĵ�ָ�� : " << y << endl;

	cout << "y�����ָ�� : " << &y << endl;

	cout << "new auto�������һ��x������ָ�� : " << *z << endl;

	cout << "new auto�����ƶ�double ��ָ�� : " << z << endl;

	cout << "z�����ָ�� : " << &z << endl;

	cout << "zָ���ϵ�ֵ : " << **z << endl;
	return 0;
}

int main35()
{

	auto x = 1, * y = &x, ** z = &y; // Resolves to int.
	auto a(2.01), * b(&a);         // Resolves to double.
	auto c = 'a', * d(&c);          // Resolves to char.
	auto m = 1, & n = m;  
	// Resolves to int.

	cout << &x << "==" << y << endl;

	cout << &y << "==" << z << endl;


	return 0;
}

//�˴���Ƭ��ʹ����������� (?:) ������ x ����ΪֵΪ 200 ��������

int main36()
{
	int v1 = 100, v2 = 200;
	auto x = v1 > v2 ? v1 : v2;

	cout << x;
	return 0;
}
//����Ĵ���Ƭ�ν�������ʼ�� x Ϊ���ͣ�����������Ϊ�����͵� int ���ã�����������ʼ��Ϊָ�� y const int fp �������͵ĺ�����ָ�� int ��
int f2(int x) { return x; }
int main37()
{
	auto x = f2(0);
	const auto& y = f2(1);
	int (*p)(int x);
	p = f2;
	auto fp = p;
	return 0;
}