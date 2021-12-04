#include <string>
#include <iostream>
#include <vector>
using namespace std;


//类型参数的数量没有实际限制。 用逗号分隔多个参数：

template <typename T, typename U, typename V> class Foo {};

//关键字与 classtypename 此上下文中的等效。 您可以将上一个示例表示为：

//template <class T, class U, class V> class Foo {};

//您可以使用省略号运算符 ( ... ) 来定义使用任意数量的零个或多个类型参数的模板：
template<typename... Arguments> class vtclass;

//vtclass< > vtinstance1;
//vtclass<int> vtinstance2;
//vtclass<float, bool> vtinstance3;


template <typename T>
T minimum2(const T& lhs, const T& rhs)
{
    return lhs;
}

class MyClass
{
public:
    int num;
    std::wstring description;
};

int main220102012()
{
    MyClass mc1{ 1, L"hello" };
    MyClass mc2{ 2, L"goodbye" };
    auto result = minimum2(mc1, mc2); // Error! C2678

    cout << result.num << endl;


    return 0;

}