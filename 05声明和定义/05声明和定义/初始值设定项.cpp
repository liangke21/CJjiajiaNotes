#include <initializer_list>
#include<iostream>

//在变量的定义中：
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

int i0;              // 零初始化为 0
int main71() {
    static float f1;  //零初始化为 0.000000000
    double d{};     // 零初始化为 0.00000000000000000
    int* ptr{};     // 初始化为 nullptr
    char s_array[3]{ 'a', 'b' };  // the third char is initialized to '\0'
    int int_array[5] = { 8, 9, 10 };  // 第四个和第五个整数被初始化为 0
    my_struct a_struct{};   // i = 0, c = '\0'
    return 0;
}

//常量变量的默认初始化

class MyClass2 {};
int main73() {
    //const int i2;   // 编译器错误 C2734：如果不是 extern，则必须初始化 const 对象
    //const char c2;  // 同样的错误
   // const MyClass2 mc1; // 编译器错误 C4269：&#39;const 自动数据用编译器生成的默认构造函数初始化produces unreliable results
    return 0;
}

//静态变量的默认初始化

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

//值初始化
class BaseClass {
private:int m_int;

public:int getM_int() {
        return m_int;
    }
};

using namespace std;

int main75() {
    BaseClass bc{};     // 类被初始化
    BaseClass* bc2 = new BaseClass();  //类已初始化，m int 值为 0
    BaseClass bc3; //默认初始化

    cout << "m_int  : " << bc.getM_int() << endl;
    cout << "m_int  : " << bc2->getM_int() << endl;
    cout << "m_int  : " << bc3.getM_int() << endl;

    int int_arr[3]{};  // 所有成员的值为0
    int a{};     // a 的值为 0
    double b{};  // b 的值为 0.00000000000000000

    return 0;
}

//复制初始化

#include <iostream>
#include <functional>
using namespace std;

class MyClass3 {
public:
    MyClass3(int myInt) {}
    void set_int(int myInt) { m_int = myInt; }
    int get_int() const { return m_int; }
private:
    int m_int; // m int 的复制初始化

};
class MyException : public exception {};
int main76() {
    int i = 5;              // 复制初始化 i
    MyClass3 mc1{ i };
    cout << "m_int  : " << mc1.get_int() << endl;
    MyClass3 mc2 = mc1;      // 从 mc1 复制 mc2 的初始化
    cout << "m_int2  : " << mc2.get_int() << endl;

  //  MyClass3 mc1.set_int(i);    // 从 i 复制参数的初始化
    int i2 = mc2.get_int(); // 从 get int() 的返回值复制 i2 的初始化

    try {
        throw MyException();
    }
    catch (MyException ex) { // 复制初始化 ex
        cout << ex.what();
    }
    return 0;
}

//直接初始化

class BaseClass36 {
public:
    BaseClass36(int n) :m_int(n) {} // m int 直接初始化
private:
    int m_int;
public:int get_int() {
    return m_int;
}
};

class DerivedClass : public BaseClass36 {
public:
    // Base Class 和 m char 直接初始化
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
    function<int()> func = [a]() {  return a + 1; }; // a 直接初始化
    int n = func();
    return 0;
}

//计时器
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
    //获取秒
    double getTimerSecond()
    {
        return getTimerMicroSec() * 0.000001;
    }
    //获取毫秒
    double getTimerMilliSec()
    {
        return getTimerMicroSec() * 0.001;
    }
    //获取微妙
    long long getTimerMicroSec()
    {
        //当前时钟减去开始时钟的count
        return std::chrono::duration_cast<std::chrono::microseconds>
            (std::chrono::high_resolution_clock::now() - _start).count();
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock>_start;
};

int main78()
{
    TimerClock ti;
    
    cout << "获取秒" << ti.getTimerMicroSec();
    return 0;
}

//列表初始化

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

//初始化联合和结构

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
    //MyUnion mu5{ 1, 'a', true };  // compiler error: C2078: 初始化器过多
    //MyUnion mu6 = 'a';            // compiler error: C2440: 无法从“字符”转换为“我的联盟”
    //MyUnion mu7 = 1;              // compiler error: C2440: 无法从“int”转换为“My Union”

    MyStruct ms1{ 'a' };            // myInt = 97, myChar = '\0'
    MyStruct ms2{ 1 };              // myInt = 1, myChar = '\0'
    MyStruct ms3{};                 // myInt = 0, myChar = '\0'
    MyStruct ms4{ 1, 'a' };           // myInt = 1, myChar = 'a'
    MyStruct ms5 = { 2, 'b' };      // myInt = 2, myChar = 'b'
    return 0;
}
//引用初始化
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

