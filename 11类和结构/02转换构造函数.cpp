
//ת�����캯�������˴��û���������ͻ��������͵��û���������͵�ת���� �����ʾ����ʾ����������ת��Ϊ�û��������͵� double ת�����캯�� Money ��



#include <iostream>

class Money
{
public:
    Money() : amount{ 0.0 } {};
    Money(double _amount) : amount{ _amount } {};

    double amount;
};

void display_balance(const Money balance)
{
    std::cout << "The balance is: " << balance.amount << std::endl;
}

int main150201(int argc, char* argv[])
{
    Money payable{ 79.99 };

    display_balance(payable);
    display_balance(49.95);
    display_balance(9.99f);

    return 0;
}

/*
��ע�⣬�Ժ��� display_balance ���״ε��ã������������� Money ���Ա���������Ҫת������Ϊ�����Ա���������ȷ�� ���ǣ��ڶ��ε��� ʱ����Ҫת������Ϊ ���������ͣ�ֵΪ �����Ǻ��� display_balance double 49.95 ���������͡� ��������ֱ��ʹ�ô�ֵ�������ڴ��ڴӲ������͵�ƥ��������͵�ת����������͵���ʱֵ�� �������첢���� double Money ��ɺ��� Money ���á� �ڶ� �ĵ����ε����У���ע�� �������� ������ֵΪ �� �������������Կ���ɣ���Ϊ����������ִ�д� �� �ı�׼ת����Ȼ��ִ�д� �� ���û�����ת������� display_balance double float 9.99 float double double Money ��Ҫ��ת����
*/



