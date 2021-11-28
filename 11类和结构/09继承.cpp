







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
    // 从 Base 继承所有构造函数
    using Base::Base;

private:
    // 无法从 Base 构造函数初始化新成员。
    int newMember{ 0 };
};

int main10010901()
{
  //  cout << "派生的 d1(5) 调用: ";
    Derived d1(5);
  //  cout << "派生的 d1(&#39;c&#39;) 调用: ";
    Derived d2('c');
  //  cout << "派生 d3 = d2 调用： ";
    Derived d3 = d2;
  //  cout << "派生的 d4 调用: ";
    Derived d4;

    return 0;
}

/* 输出：
派生的 d1(5) 调用：Base(int)
派生的 d1(&#39;c&#39;) 调用： Base(char)
派生 d3 = d2 调用：Base(Base&amp;)
派生的 d4 调用：Base()*/