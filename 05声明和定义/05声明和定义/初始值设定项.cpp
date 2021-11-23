#include <initializer_list>
#include<iostream>

//�ڱ����Ķ����У�
//int i = 3;
//Point p1{ 1, 2 };



struct Point {
    int x;
    int y;
};
class PointConsumer {
public:
    void set_point(Point p) {};
    void set_points(std::initializer_list<Point> my_list) {};
};
int main72() {
    PointConsumer pc{};
   // PointConsumer pc;
    pc.set_point({});
    pc.set_point({ 3, 4 });
    pc.set_points({ { 3, 4 }, { 5, 6 } });
    return 0;
}


struct my_struct {
    int i;
    char c;
};

int i0;              // ���ʼ��Ϊ 0
int main71() {
    static float f1;  //���ʼ��Ϊ 0.000000000
    double d{};     // ���ʼ��Ϊ 0.00000000000000000
    int* ptr{};     // ��ʼ��Ϊ nullptr
    char s_array[3]{ 'a', 'b' };  // the third char is initialized to '\0'
    int int_array[5] = { 8, 9, 10 };  // ���ĸ��͵������������ʼ��Ϊ 0
    my_struct a_struct{};   // i = 0, c = '\0'
    return 0;
}

//����������Ĭ�ϳ�ʼ��

class MyClass2 {};
int main73() {
    //const int i2;   // ���������� C2734��������� extern��������ʼ�� const ����
    //const char c2;  // ͬ���Ĵ���
   // const MyClass2 mc1; // ���������� C4269��&#39;const �Զ������ñ��������ɵ�Ĭ�Ϲ��캯����ʼ��produces unreliable results
    return 0;
}

//��̬������Ĭ�ϳ�ʼ��

class MyClass21 {
private:
    int m_int;
    char m_char;
};

int main74() {
    static int int1;       // 0
    static char char1;     // '\0'
    static bool bool1;   // false
    static MyClass21 mc1;     // {0, '\0'}
    return 0;
}

//ֵ��ʼ��
class BaseClass {
private:int m_int;

public:int getM_int() {
        return m_int;
    }
};

using namespace std;

int main75() {
    BaseClass bc{};     // �౻��ʼ��
    BaseClass* bc2 = new BaseClass();  //���ѳ�ʼ����m int ֵΪ 0
    BaseClass bc3; //Ĭ�ϳ�ʼ��

    cout << "m_int  : " << bc.getM_int() << endl;
    cout << "m_int  : " << bc2->getM_int() << endl;
    cout << "m_int  : " << bc3.getM_int() << endl;

    int int_arr[3]{};  // ���г�Ա��ֵΪ0
    int a{};     // a ��ֵΪ 0
    double b{};  // b ��ֵΪ 0.00000000000000000

    return 0;
}

//���Ƴ�ʼ��

#include <iostream>
#include <functional>
using namespace std;

class MyClass3 {
public:
  //  MyClass3(int myInt) {}
    void set_int(int myInt) { m_int = myInt; }
    int get_int() const { return m_int; }
private:
    int m_int; // m int �ĸ��Ƴ�ʼ��

};
class MyException : public exception {};
int main76() {
    int i = 5;              // ���Ƴ�ʼ�� i
    MyClass3 mc1{ i };
    cout << "m_int  : " << mc1.get_int() << endl;
    MyClass3 mc2 = mc1;      // �� mc1 ���� mc2 �ĳ�ʼ��
    cout << "m_int2  : " << mc2.get_int() << endl;

  //  MyClass3 mc1.set_int(i);    // �� i ���Ʋ����ĳ�ʼ��
    int i2 = mc2.get_int(); // �� get int() �ķ���ֵ���� i2 �ĳ�ʼ��

    try {
        throw MyException();
    }
    catch (MyException ex) { // ���Ƴ�ʼ�� ex
        cout << ex.what();
    }
    return 0;
}

//ֱ�ӳ�ʼ��

class BaseClass36 {
public:
    BaseClass36(int n) :m_int(n) {} // m int ֱ�ӳ�ʼ��
private:
    int m_int;
public:int get_int() {
    return m_int;
}
};

class DerivedClass : public BaseClass36 {
public:
    // Base Class �� m char ֱ�ӳ�ʼ��
    DerivedClass(int n, char c) : BaseClass36(n), m_char(c) {
        cout << "m_char : " << get_char() <<"m_int : "<<n<< endl;
    }
private:
    char m_char;

public:char get_char() {
    return m_char;
}
};
int main77() {
    BaseClass36 bc1(5);
    cout << "m_int : " << bc1.get_int() << endl;

    DerivedClass dc12{ 1, 'c' };
    

    BaseClass36* bc2 = new BaseClass36(7);

    cout << "m_int : " << bc2->get_int() << endl;

    BaseClass36 bc3 = static_cast<BaseClass36>(dc12);
    cout << "m_int : " << bc3.get_int() << endl;

    int a = 1;
    function<int()> func = [a]() {  return a + 1; }; // a ֱ�ӳ�ʼ��
    int n = func();
    return 0;
}

//��ʱ��
#include <chrono>

class TimerClock
{
public:
    TimerClock()
    {
        update();
    }

    ~TimerClock()
    {
    }

    void update()
    {
        _start = std::chrono::high_resolution_clock::now();
    }
    //��ȡ��
    double getTimerSecond()
    {
        return getTimerMicroSec() * 0.000001;
    }
    //��ȡ����
    double getTimerMilliSec()
    {
        return getTimerMicroSec() * 0.001;
    }
    //��ȡ΢��
    long long getTimerMicroSec()
    {
        //��ǰʱ�Ӽ�ȥ��ʼʱ�ӵ�count
        return std::chrono::duration_cast<std::chrono::microseconds>
            (std::chrono::high_resolution_clock::now() - _start).count();
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock>_start;
};

int main78()
{
    TimerClock ti;
    
    cout << "��ȡ��" << ti.getTimerMicroSec();
    return 0;
}

//�б��ʼ��

class MyClass23 {
public:
    MyClass23(int myInt, char myChar) /*:m_int{ myInt }, m_char(myChar)*/ {
        this->m_int[0] = myInt;
        this->m_char = myChar;


        cout << "MyClassConsumer m_int : " << m_int[0] << "  m_char : " << m_char << endl;
    }
public:
    int m_int[1]{ 3 };
    char m_char;


};

class MyClass {
public:
    MyClass(int myInt, char myChar) /*:m_int{ myInt }, m_char(myChar)*/{
        this->m_int[0] = myInt;
        this->m_char = myChar;
    
    }
public:
    int m_int[1]{ 3 };
    char m_char;


};
class MyClassConsumer {
public:
    void set_class(MyClass23 c) {}
    MyClass23 get_class() { return MyClass23{ 0, '\0' }; }
};
struct MyStruct2 {
    int my_int;
    char my_char;
    MyClass my_class;
};
int main79() {
    MyClass mc1{ 1, 'a' };
    cout << "m_int : " << mc1.m_int[0] << "  m_char : " << mc1.m_char << endl;


    MyClass* mc2 = new MyClass{ 2, 'b' };
    cout << "m_int : " << mc2->m_int[1] << "  m_char : " << mc2->m_char << endl;

    MyClass* mc4 = new MyClass(2, 'b');
    cout << "m_int : " << mc4->m_int[1] << "  m_char : " << mc4->m_char << endl;

    MyClass mc3 = { 3, 'c' };

    cout << "m_int3333 : " << mc3.m_int[0] << "  mc4->m_char : " << mc3.m_char << endl;


    MyClassConsumer mcc;
    mcc.set_class(MyClass23{ 3, 'c' });
    mcc.set_class({ 4, 'd' });

    MyStruct2 ms1{ 1, 'a', { 2, 'b' } };

    cout <<"  MyStruct : my_int  "<<ms1.my_int<<"  my-char : "<<ms1.my_char<< endl<<"my_class : m_int: " << ms1.my_class.m_int[0] 
        << "  m_char : " << ms1.my_class.m_char << endl;
    return 0;
}

//��ʼ�����Ϻͽṹ

struct MyStruct {
    int myInt;
    char myChar;
};
union MyUnion {
    int my_int;
    char my_char;
    bool my_bool;
    MyStruct my_struct;
};

int main710() {
    MyUnion mu1{ 'a' };  // my_int = 97, my_char = 'a', my_bool = true, {myInt = 97, myChar = '\0'}
    MyUnion mu2{ 1 };   // my_int = 1, my_char = 'x1', my_bool = true, {myInt = 1, myChar = '\0'}
    MyUnion mu3{};      // my_int = 0, my_char = '\0', my_bool = false, {myInt = 0, myChar = '\0'}
    MyUnion mu4 = mu3;  // my_int = 0, my_char = '\0', my_bool = false, {myInt = 0, myChar = '\0'}
    //MyUnion mu5{ 1, 'a', true };  // compiler error: C2078: ��ʼ��������
    //MyUnion mu6 = 'a';            // compiler error: C2440: �޷��ӡ��ַ���ת��Ϊ���ҵ����ˡ�
    //MyUnion mu7 = 1;              // compiler error: C2440: �޷��ӡ�int��ת��Ϊ��My Union��

    MyStruct ms1{ 'a' };            // myInt = 97, myChar = '\0'
    MyStruct ms2{ 1 };              // myInt = 1, myChar = '\0'
    MyStruct ms3{};                 // myInt = 0, myChar = '\0'
    MyStruct ms4{ 1, 'a' };           // myInt = 1, myChar = 'a'
    MyStruct ms5 = { 2, 'b' };      // myInt = 2, myChar = 'b'
    return 0;
}
//���ó�ʼ��
// initializing_references.cpp
int iVar;
long lVar;
int main711()
{
    long& LongRef1 = lVar;        // No conversion required.
  //  long& LongRef2 = iVar;        // Error C2440
    const long& LongRef3 = iVar;  // OK
    LongRef1 = 23L;               // Change lVar through a reference.
    //LongRef2 = 11L;               // Change iVar through a reference.
    //LongRef3 = 11L;               // Error C3892
    return 0;
}

