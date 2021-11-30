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

 //int a = Increment(67);// C3615	constexpr ������Increment���������ɳ������ʽ	11	����
   // std::cout << a;

    return 0;
}
//�����ʽ����ʽ lambda constexpr ����ת��Ϊ����ָ�뽫����һ�� constexpr ������

auto Increment2 = [](int n)
{
    return n + 1;
};

constexpr int(*inc)(int) = Increment2;

int main010402() {

    cout << inc;
    return 0;
}