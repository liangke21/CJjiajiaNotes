/*

��ת�����캯������Ϊ ʱ����ֻ������ִ�ж����ֱ�ӳ�ʼ�� explicit ��ִ����ʽǿ��ת����
�⽫��ֹ���������͵��Ա����ĺ���ͬ����ʽ����ת�����캯����Դ���͵��Ա�����
���ҽ���ֹ�Ӹ�Դ���͵�ֵ���Ƴ�ʼ��������͡�
����ʾ����ʾ����ζ�����ʽת�����캯����
�Լ������ĸ������ʽ��ȷ��������Ӱ�졣

*/

#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    explicit Money(double _amount) : amount{ _amount } {};

    double amount;
};

void display_balance(const Money balance)
{
    std::cout << "The balance is: " << balance.amount << std::endl;
}

int main150301(int argc, char* argv[])
{
    Money payable{ 79.99 };        //�Ϸ���ֱ�ӳ�ʼ������ʽ�ġ�

    display_balance(payable);      // �Ϸ�������ת��
    //display_balance(49.95);        // ���󣺲����ڴ� double ת��Ϊ Money �ĺ���ת����
    display_balance((Money)9.99f); // �Ϸ�����ʽת��Ϊ Money

    return 0;
}