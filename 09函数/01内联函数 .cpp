

//��������������У�Account ���캯�������������� ��Ա���� GetBalance �� Deposit �� Withdraw ��ָ��Ϊ �� inline ��������Ϊ��������ʵ�֡�


//
class Account
{
public:
    Account(double initial_balance) { balance = initial_balance; }
    double GetBalance();
    double Deposit(double Amount);
    double Withdraw(double Amount);
private:
    double balance;
};

inline double Account::GetBalance()
{
    return balance;
}

inline double Account::Deposit(double Amount)
{
    return (balance += Amount);
}

inline double Account::Withdraw(double Amount)
{
    return (balance -= Amount);
}
int main0701()
{

    return 0;
}