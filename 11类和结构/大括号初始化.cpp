//并不总是需要为类定义构造函数，特别是相对比较简单的类。 用户可以使用统一初始化来初始化类或结构的对象，如下面的示例所示：


#include <time.h>

//没有建设者
struct TempData
{
    int StationId;
    time_t timeSet;
    double current;
    double maxTemp;
    double minTemp;
};

// 有一个构造函数
struct TempData2
{
    TempData2(double minimum, double maximum, double cur, int id, time_t t) :
        stationId{ id }, timeSet{ t }, current{ cur }, maxTemp{ maximum }, minTemp{ minimum } {}
    int stationId;
    time_t timeSet;
    double current;
    double maxTemp;
    double minTemp;
};

int main050601()
{
    time_t time_to_set;

    // 成员初始化（按声明顺序）：
    TempData td{ 45978, time(&time_to_set), 28.9, 37.0, 16.7 };

    // 默认初始化 = {0,0,0,0,0}
    TempData td_default{};

    // 未初始化 = 如果使用，发出警告 C4700 未初始化的局部变量
  //  TempData td_noInit;

    // 成员声明（按ctor参数顺序）
    TempData2 td2{ 16.7, 37.0, 28.9, 45978, time(&time_to_set) };

    return 0;
}

/*
请注意，当类或结构没有构造函数时，将按在类中声明成员的顺序提供列表元素。 如果类具有构造函数，请按参数的顺序提供元素。
如果类型具有隐式或显式声明的默认构造函数，则您可以使用默认大括号初始化（具有空大括号）。 例如，可通过使用默认和非默认大括号初始化来初始化以下类：
*/

#include <string>
using namespace std;

class class_a {
public:
    class_a() {}
    class_a(string str) : m_string{ str } {}
    class_a(string str, double dbl) : m_string{ str }, m_double{ dbl } {}
    double m_double;
    string m_string;
};

int main0602()
{
    class_a c1{};
    class_a c1_1;

    class_a c2{ "ww" };  //走默认指定声明构造函数
    class_a c2_1("xx");  //走默认指定声明构造函数

    // 参数顺序与构造函数相同
    class_a c3{ "yy", 4.4 };  //走默认指定声明构造函数
    class_a c3_1("zz", 5.5);  //走默认指定声明构造函数

    return 0;
}

/*
如果类具有非默认构造函数，则类成员在大括号初始值设定项中的显示顺序是对应参数在构造函数中的显示顺序，
而不是成员的声明顺序（如上一示例中的 class_a 一样）。 否则，如果类型没有声明的构造函数，
则成员在大括号初始值设定项中的显示顺序与其声明顺序一样，在这种情况下，您可初始化所需数量的公共成员，
但无法跳过任何成员。 以下示例演示了在无声明的构造函数时在大括号初始化中使用的顺序：
*/


class class_d {
public:
    float m_float;
    string m_string;
    wchar_t m_char;
};

int main0603()
{
    class_d d1{};
    class_d d1{ 4.5 };
    class_d d2{ 4.5, "string" };
    class_d d3{ 4.5, "string", 'c' };

  //  class_d d4{ "string", 'c' }; // 编译器错误  //没有按顺序对应初始化参数
  //  class_d d5{ "string", 'c', 2.0 }; // 编译器错误 ////没有按顺序对应初始化参数

    return 0;
}

//如果默认构造函数已显式声明，但标记为“已删除”，则无法使用默认大括号初始化：

class class_f {
public:
    class_f() = delete;
    class_f(string x) : m_string{ x } {}
    string m_string;
};
int main0604()
{
    class_f cf{ "hello" };
  //  class_f cf1{}; //编译器错误 C2280：试图引用已删除的函数

    return 0;
}