
#include<iostream>

using namespace std;

int fun1() {
	return 4;
}

auto fun2() {

	return 'a';    //���������ĳ� 4 ��ô���;ͻ��Ƶ�Ϊint����
}
//�ڱ���ʱ�Ƶ�һ�����ʽ������,�����ó�ʼ��,
int main11() {

	decltype(fun1()) x;
	decltype(fun2()) y = fun2();

	cout << typeid(x).name() << endl;
	cout << typeid(y).name() << endl;

	//typeid() ��ӡ����

	return 0;
}