







#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base()" << endl; }
    Base(const Base& other) { cout << "Base(Base&)" << endl; }
    explicit Base(int i) : num(i) { cout << "Base(int)" << endl; }
    explicit Base(char c) : letter(c) { cout << "Base(char)" << endl; }

private:
    int num;
    char letter;
};

class Derived : Base
{
public:
    // �� Base �̳����й��캯��
    using Base::Base;

private:
    // �޷��� Base ���캯����ʼ���³�Ա��
    int newMember{ 0 };
};

int main10010901()
{
  //  cout << "������ d1(5) ����: ";
    Derived d1(5);
  //  cout << "������ d1(&#39;c&#39;) ����: ";
    Derived d2('c');
  //  cout << "���� d3 = d2 ���ã� ";
    Derived d3 = d2;
  //  cout << "������ d4 ����: ";
    Derived d4;

    return 0;
}

/* �����
������ d1(5) ���ã�Base(int)
������ d1(&#39;c&#39;) ���ã� Base(char)
���� d3 = d2 ���ã�Base(Base&amp;)
������ d4 ���ã�Base()*/