
//��С���� ���� �����������͡��������ƺͲ����б� (����Ϊ��) �Լ���������ṩ����ָ��Ŀ�ѡ�ؼ��֡� ����ʾ���Ǻ���������
int sum2(int a, int b);

//���������������� ���� ��ɣ������Ǵ�����֮������д��룺
int sum2(int a, int b)
{
    return a + b;
}

//constexpr��ָʾ�����ķ���ֵ�ǳ���ֵ�������ڱ���ʱ���㡣

constexpr float exp(float x, int n)
{
    return n == 0 ? 1 :
        n % 2 == 0 ? exp(x * x, n / 2) :
        exp(x * x, (n - 1) / 2) * x;
};

//�����ӹ淶�� extern static ��

//ʹ�� C �������� printf��
extern "C" int printf(const char* fmt, ...);

//inline��ָʾ��������������ÿ�ε����滻Ϊ�������뱾�� ��ĳ����������ִ�в��������ܹؼ���������ظ����õ�����£��������԰���������ܡ�

//inline double Account::GetBalance()
//{
//    return balance;
//}

// һ noexcept �����ʽ��ָ�������Ƿ���������쳣�� �������ʾ���У�������ʽ������Ϊ �� is_pod �������������쳣 true ��

/*

#include <type_traits>

template <typename T>
T copy_object(T& obj) noexcept(std::is_pod<T>) { ... }

*/