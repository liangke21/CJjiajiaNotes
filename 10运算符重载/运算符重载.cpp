

//operator �ؼ�������һ���������ú���ָ��Ӧ�������ʵ��ʱ�� ������� �⽫Ϊ������ṩ������壬���߽������ء����� ������ͨ�����������������������������ͬ�ĺ��塣


//�����ʾ������ + �����������������������ؽ����



#include <iostream>
using namespace std;

struct Complex {
	Complex(double r, double i) : re(r), im(i) {}
	Complex operator+(Complex& other);
	void Display() { cout << re << ", " << im << endl; }
private:
	double re, im;
};

// ʹ�ó�Ա�������ص������
Complex Complex::operator+(Complex& other) {
	return Complex(re + other.re, im + other.im);
}

int main0101() {
	Complex a = Complex(1.2, 3.4);
	Complex b = Complex(5.6, 7.8);
	Complex c = Complex(0.0, 0.0);

	c = a + b;
	c.Display();

	return 0;
}