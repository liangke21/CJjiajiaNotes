// declaration_matching1.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
void func(int i)
{
    cout << "Called file-scoped func : " << i << endl;
}

void func(const char* sz)
{
    cout << "Called locally declared func : " << sz << endl;
}

int main030501()
{
    // �� func ����Ϊ main �ı��ء�
    extern void func(const char* sz);  //�ⲿ�����غ������ᱻ����

  //  func(3);   // C2664 ���� func( int ) �����صġ�
    func("s");

    return 0;
}



// declaration_matching2.cpp
class Account
{
public:
    Account()
    {
    }
    double Deposit(double dAmount,  const char* szPassword); //����һ������

private:
    double Deposit(double dAmount)
    {
        return 0.0;
    }
    int Validate(const char* szPassword)
    {
        return 0;
    }

};

int main030502()
{
    // Allocate a new object of type Account.
    Account* pAcct = new Account;

    // Deposit $57.22. ���󣺵���˽�к�����
    // pAcct->Deposit( 57.22 );

    // Deposit $57.22 ���ṩ���롣 OK������һ��
    //  ����ְ�ܡ�
    pAcct->Deposit(52.77, "pswd");

    return 0;
}

double Account::Deposit(double dAmount,const char* szPassword) //������������һ������   //���������ǿ��Է��ʵ�
{
    if (Validate(szPassword))
        return Deposit(dAmount);
    else
        return 0.0;
}