#include <string>
#include <iostream>
//
int main1()
{
	int result = 0;              // ��������ʼ��һ��������
	double coefficient = 10.8;   // ��������ʼ��һ������

	auto name = "Lady G.";       // ����һ���������ñ�����
								 // �ƶ����͡�
   // auto address;                // ���󡣱������޷��Ƶ�������
								 // û�г�ʼ��ֵ��
  //  age = 12;                    // ���󡣱�����������
								 // ָ�����ͻ�ʹ�� auto!
   // result = "Kenny G.";         // �����޷����ı������ int��
   // string result = "zero";      // �����޷����¶������
								 //���͡�
   // int maxValue;                //�����飡���ֵ����
								 //����λ��ֱ��������ʼ����
	return 0;
}
using namespace std;
//���������ã�����
int main2()
{
	cout << "type: \t\t" << "************size**************" << endl;
	cout << "bool: \t\t" << "��ռ�ֽ�����" << sizeof(bool);
	cout << "\t���ֵ��" << (numeric_limits<bool>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<bool>::min)() << endl;
	cout << "char: \t\t" << "��ռ�ֽ�����" << sizeof(char);
	cout << "\t���ֵ��" << (numeric_limits<char>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<char>::min)() << endl;
	cout << "signed char: \t" << "��ռ�ֽ�����" << sizeof(signed char);
	cout << "\t���ֵ��" << (numeric_limits<signed char>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<signed char>::min)() << endl;
	cout << "unsigned char: \t" << "��ռ�ֽ�����" << sizeof(unsigned char);
	cout << "\t���ֵ��" << (numeric_limits<unsigned char>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<unsigned char>::min)() << endl;
	cout << "wchar_t: \t" << "��ռ�ֽ�����" << sizeof(wchar_t);
	cout << "\t���ֵ��" << (numeric_limits<wchar_t>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<wchar_t>::min)() << endl;
	cout << "short: \t\t" << "��ռ�ֽ�����" << sizeof(short);
	cout << "\t���ֵ��" << (numeric_limits<short>::max)();
	cout << "\t\t��Сֵ��" << (numeric_limits<short>::min)() << endl;
	cout << "int: \t\t" << "��ռ�ֽ�����" << sizeof(int);
	cout << "\t���ֵ��" << (numeric_limits<int>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<int>::min)() << endl;
	cout << "unsigned: \t" << "��ռ�ֽ�����" << sizeof(unsigned);
	cout << "\t���ֵ��" << (numeric_limits<unsigned>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<unsigned>::min)() << endl;
	cout << "long: \t\t" << "��ռ�ֽ�����" << sizeof(long);
	cout << "\t���ֵ��" << (numeric_limits<long>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<long>::min)() << endl;
	cout << "unsigned long: \t" << "��ռ�ֽ�����" << sizeof(unsigned long);
	cout << "\t���ֵ��" << (numeric_limits<unsigned long>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<unsigned long>::min)() << endl;
	cout << "double: \t" << "��ռ�ֽ�����" << sizeof(double);
	cout << "\t���ֵ��" << (numeric_limits<double>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<double>::min)() << endl;
	cout << "long double: \t" << "��ռ�ֽ�����" << sizeof(long double);
	cout << "\t���ֵ��" << (numeric_limits<long double>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<long double>::min)() << endl;
	cout << "float: \t\t" << "��ռ�ֽ�����" << sizeof(float);
	cout << "\t���ֵ��" << (numeric_limits<float>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<float>::min)() << endl;
	cout << "size_t: \t" << "��ռ�ֽ�����" << sizeof(size_t);
	cout << "\t���ֵ��" << (numeric_limits<size_t>::max)();
	cout << "\t��Сֵ��" << (numeric_limits<size_t>::min)() << endl;
	cout << "string: \t" << "��ռ�ֽ�����" << sizeof(string) << endl;
	// << "\t���ֵ��" << (numeric_limits<string>::max)() << "\t��Сֵ��" << (numeric_limits<string>::min)() << endl;  
	cout << "type: \t\t" << "************size**************" << endl;
	return 0;
}

//const �����޶���
int main3()
{
	/*
	�κ����û��û���������Ͷ����� const �ؼ����޶���
	���⣬��Ա���������� const �޶��ģ������� const ���صġ� ��ʼ������ const ���޷��޸���ֵ
	*/
	const double PI = 3.1415;
	// PI = .75 //�����޷��޸� const ������

	return 0;
}

//�ַ�������
//?

//�û���������
//?

//ָ������
int main()
{

	int* pNumber;       // ����һ��ָ�� int ��ָ�������
  //  *pNumber = 10;      // ������Ȼ����Ա��룬������   �������˼��Ҫһ����ַ������һ��ֵ

						// һ�����صĴ�����������ȡ������һ��
						// û�г�ʼ����ָ�����
						// ������ڴ�ָ��
   // pNumber = 10;   //����

	int name = 23;

	//*pNumber = name; ///����

	//cout << "pNumber : " << pNumber << endl;

	pNumber = &name;

	cout << "pNumber : " << pNumber << endl; //���ָ���ַ

	cout << "pNumber : " << *pNumber << endl; //������ָ���ֵ

	*pNumber = 20;
	cout << "pNumber : " << *pNumber << endl; //�ı����ָ���ַ������ֵ
	return 0;
}