/*
����ͨǶ�������ռ䲻ͬ�����������ռ�ĳ�Ա�ᱻ��Ϊ�������ռ�ĳ�Ա��
��һ����ʹ������غ������������Ա����Ĳ��ҿ��ԶԸ������ռ��Ƕ�����������ռ��о������صĺ��������á�
���������������������ռ���������ģ��ĸ������ռ�������ר�û��� 
�����ʾ����ʾ��Ĭ������£��ⲿ������ΰ󶨵����������ռ䣺
*/



#include <string>

namespace Test
{
    namespace old_ns
    {
        std::string Func() { return std::string("��ô���"); }
    }

    inline namespace new_ns
    {
        std::string Func() { return std::string("���������"); }
    }
}


#include <string>
#include <iostream>

int main501()
{
    using namespace Test;
    using namespace std;

    string s = Func();
    std::cout << s << std::endl; // "Hello from new"
    return 0;
}