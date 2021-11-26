

//在下面的类声明中，Account 构造函数是内联函数。 成员函数 GetBalance 、 Deposit 和 Withdraw 不指定为 ， inline 但可以作为内联函数实现。


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