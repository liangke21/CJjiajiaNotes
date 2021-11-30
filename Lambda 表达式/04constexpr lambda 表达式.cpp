#include <iostream>
using namespace std;


//int y = 32;
//auto answer = [y]() constexpr
//{
//    int x = 10;
//    return y + x;
//};

constexpr int Increment(int n)
{
    return [n] { return n + 1; }();
}

int main0104() {

 //int a = Increment(67);// C3615	constexpr 函数“Increment”不能生成常量表达式	11	生成
   // std::cout << a;

    return 0;
}
//如果隐式或显式 lambda constexpr ，则转换为函数指针将产生一个 constexpr 函数：

auto Increment2 = [](int n)
{
    return n + 1;
};

constexpr int(*inc)(int) = Increment2;

int main010402() {

    cout << inc;
    return 0;
}