// constexpr.cpp

#include <iostream>

using namespace std;

//按值传递
constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
}

// 通过引用传递
constexpr float exp2(const float& x, const int& n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp2(x * x, n / 2) :
        exp2(x * x, (n - 1) / 2) * x;
}

// 数组长度的编译时计算
template<typename T, int N>
constexpr int length(const T(&)[N])
{
    return N;
}

// 递归 constexpr 函数
constexpr int fac(int n)
{
    return n == 1 ? 1 : n * fac(n - 1);
}

// 用户自定义类型
class Foo
{
public:
    constexpr explicit Foo(int i) : _i(i) {}
    constexpr int GetValue() const
    {
        return _i;
    }
private:
    int _i;
};

int main()
{
    // foo 是常量：
    constexpr Foo foo(5);
    // foo = Foo(6); //Error!

    // 编译时间：
    constexpr float x = exp(5, 3);
    constexpr float y{ exp(2, 5) };
    constexpr int val = foo.GetValue();
    constexpr int f5 = fac(5);
    const int nums[]{ 1, 2, 3, 4 };
    const int nums2[length(nums) * 2]{ 1, 2, 3, 4, 5, 6, 7, 8 };

    // 运行：
    cout << "The value of foo is " << foo.GetValue() << endl;
}