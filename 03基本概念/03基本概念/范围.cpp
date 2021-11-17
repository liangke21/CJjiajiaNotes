//隐藏类名
#include <iostream>
using namespace std;

// 在全局范围内声明类 Account。
class Account   
{
public:
    Account(double InitialBalance)
    {
        balance = InitialBalance;
    }
    double GetBalance() //要通过函数访问
    {
        return balance;
    }
private:
    double balance; //这个被隐藏了
};

double Account = 15.37;            // 隐藏类名帐户

int main21()
{
    class Account Checking(Account); // 将帐户作为
                                       //  班级名称

    cout << "开户余额为: "
        << Checking.GetBalance() << "\n";

    class Account* Checking2 = new class Account(Account);

    cout << "开户余额为: " << Checking2->GetBalance();

    return 0;
    //输出：开户余额为：15.37
}

//隐藏具有全局范围的名称

#include <iostream>

int i = 7;   // 我有全局范围，在所有块之外
using namespace std;

int main22(int argc, char* argv[]) {
    int i = 5;   // i 有块作用域，将 i 隐藏在全局作用域
    cout << "块范围的 i 具有值: " << i << "\n";
    cout << "全局范围的 i 具有值: " << ::i << "\n";   //访问全局变量 ::
    return 0;
}