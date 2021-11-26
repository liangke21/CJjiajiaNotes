

//operator 关键字声明一个函数，该函数指定应用于类的实例时的 运算符。 这将为运算符提供多个含义，或者将“重载”它。 编译器通过检查其操作数类型来区分运算符不同的含义。


//下面的示例重载 + 运算符以添加两个复数并返回结果。



#include <iostream>
using namespace std;

struct Complex {
	Complex(double r, double i) : re(r), im(i) {}
	Complex operator+(Complex& other);
	void Display() { cout << re << ", " << im << endl; }
private:
	double re, im;
};

// 使用成员函数重载的运算符
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