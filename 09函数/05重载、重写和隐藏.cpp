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
    // 将 func 声明为 main 的本地。
    extern void func(const char* sz);  //外部的重载函数将会被隐藏

  //  func(3);   // C2664 错误。 func( int ) 是隐藏的。
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
    double Deposit(double dAmount,  const char* szPassword); //声明一个函数

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

    // Deposit $57.22. 错误：调用私有函数。
    // pAcct->Deposit( 57.22 );

    // Deposit $57.22 并提供密码。 OK：调用一个
    //  公共职能。
    pAcct->Deposit(52.77, "pswd");

    return 0;
}

double Account::Deposit(double dAmount,const char* szPassword) //对象派生定义一个函数   //派生函数是可以访问的
{
    if (Validate(szPassword))
        return Deposit(dAmount);
    else
        return 0.0;
}