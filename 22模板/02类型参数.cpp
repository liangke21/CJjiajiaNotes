#include <string>
#include <iostream>
#include <vector>
using namespace std;


//���Ͳ���������û��ʵ�����ơ� �ö��ŷָ����������

template <typename T, typename U, typename V> class Foo {};

//�ؼ����� classtypename ���������еĵ�Ч�� �����Խ���һ��ʾ����ʾΪ��

//template <class T, class U, class V> class Foo {};

//������ʹ��ʡ�Ժ������ ( ... ) ������ʹ����������������������Ͳ�����ģ�壺
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