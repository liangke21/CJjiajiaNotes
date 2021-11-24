#include <string>
#include <iostream>
//封装命名类或结构对象中的值。 要求类或结构定义对调用方可见：
using namespace std;

struct S
{
    string name;
    int num;
};

S g()
{
    string t{ "hello" };
    int u{ 42 };
    return { t, u };
}

int main010801()
{
    S s = g();
    cout << s.name << " " << s.num << endl;
    return 0;
}

//返回 std：：元组或 std：:p air 对象：
//返回多个参数
#include <tuple>
#include <string>
#include <iostream>

using namespace std;

tuple<int, string, double> f()
{
    int i{ 108 };
    string s{ "Some text" };
    double d{ .01 };
    return { i,s,d };
}

int main010901()
{
    auto t = f();
    cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << endl;

    // --or--

    int myval;
    string myname;
    double mydecimal;
    tie(myval, myname, mydecimal) = f();
    cout << myval << " " << myname << " " << mydecimal << endl;

    return 0;
}


#include <tuple>
#include <string>
#include <iostream>

using namespace std;

tuple<int, string, double> f2()
{
    int i{ 108 };
    string s{ "Some text" };
    double d{ .01 };
    return { i,s,d };
}
struct S2
{
    string name;
    int num;
};

S2 g2()
{
    string t{ "hello" };
    int u{ 42 };
    return { t, u };
}

int main()
{
    auto [x, y, z] = f2(); // 从元组初始化
    cout << x << " " << y << " " << z << endl;  //108  Some text 0.01

    auto [a, b] = g2(); // init 来自 POD 结构
    cout << a << " " << b << endl; // "hello"  42
    return 0;
}