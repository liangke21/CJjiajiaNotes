//int y = 32;
//auto answer = [y]() constexpr
//{
//    int x = 10;
//    return y + x;
//};

#include <iostream>
constexpr int Increment4(int n)
{
    return [n] { return n + 1; }();
}

//如果 lambda 的结果满足函数的要求， constexpr 则它隐式 constexpr ：




 auto answer = [](int n)
{
    return 32 + n;
};

constexpr int response = answer(12);  //lambda表达式不能返回常量//



 //如果 lambda 是隐式或显式的，并且 constexpr 将其转换为函数指针，则生成的函数也是 constexpr ：

 constexpr auto Increment5 = [](int n)
 {
     return n + 1;
 };

 constexpr int(*inc)(int) = Increment5;

 int main0401() {


     inc(34);

     std::cout << inc(34);//35

     return 0;
 }

