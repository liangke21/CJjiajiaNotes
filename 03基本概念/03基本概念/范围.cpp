//��������
#include <iostream>
using namespace std;

// ��ȫ�ַ�Χ�������� Account��
class Account   
{
public:
    Account(double InitialBalance)
    {
        balance = InitialBalance;
    }
    double GetBalance() //Ҫͨ����������
    {
        return balance;
    }
private:
    double balance; //�����������
};

double Account = 15.37;            // ���������ʻ�

int main21()
{
    class Account Checking(Account); // ���ʻ���Ϊ
                                       //  �༶����

    cout << "�������Ϊ: "
        << Checking.GetBalance() << "\n";

    class Account* Checking2 = new class Account(Account);

    cout << "�������Ϊ: " << Checking2->GetBalance();

    return 0;
    //������������Ϊ��15.37
}

//���ؾ���ȫ�ַ�Χ������

#include <iostream>

int i = 7;   // ����ȫ�ַ�Χ�������п�֮��
using namespace std;

int main22(int argc, char* argv[]) {
    int i = 5;   // i �п������򣬽� i ������ȫ��������
    cout << "�鷶Χ�� i ����ֵ: " << i << "\n";
    cout << "ȫ�ַ�Χ�� i ����ֵ: " << ::i << "\n";   //����ȫ�ֱ��� ::
    return 0;
}