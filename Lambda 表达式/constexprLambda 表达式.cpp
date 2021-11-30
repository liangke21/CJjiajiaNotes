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

//��� lambda �Ľ�����㺯����Ҫ�� constexpr ������ʽ constexpr ��




 auto answer = [](int n)
{
    return 32 + n;
};

constexpr int response = answer(12);  //lambda���ʽ���ܷ��س���//



 //��� lambda ����ʽ����ʽ�ģ����� constexpr ����ת��Ϊ����ָ�룬�����ɵĺ���Ҳ�� constexpr ��

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

