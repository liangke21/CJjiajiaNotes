
/*
�麯����Ӧ�������������¶���ĳ�Ա������ ��ʹ��ָ���Ի�������������������������ʱ������Ϊ�ö�������麯����ִ�иú�����������汾��

�麯��ȷ��Ϊ�ö��������ȷ�ĺ������������ڽ��к������õı��ʽ�޹ء�

��������������Ϊ virtual �ĺ������������ඨ����ͬ�ĺ�����
Ϊ������Ķ�������������еĺ�������ʹ����ʹ��ָ���Ի�������������õġ� 
����ʾ����ʾ��һ�����࣬���ṩ�� PrintBalance �����������������ʵ��
*/



#include <iostream>
using namespace std;

class Account {
public:
    Account(double d) { _balance = d; }
    virtual ~Account() {}
    virtual double GetBalance() { return _balance; }
    virtual void PrintBalance() { cerr << "����ƽ�ⲻ�����ڻ�������." << endl; }
private:
    double _balance;
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double d) : Account(d) {}
    void PrintBalance() { cout << "����ʻ����: " << GetBalance() << endl; }
};

class SavingsAccount : public Account {
public:
    SavingsAccount(double d) : Account(d) {}
    void PrintBalance() { cout << "�����˻����: " << GetBalance(); }
};

int main130201() {
    // ��������Ϊ Checking Account �� Savings Account �Ķ���
    CheckingAccount checking(100.00);
    SavingsAccount  savings(1000.00);

    // ʹ��ָ�� Account ��ָ����� Print Balance��
    Account* pAccount = &checking;
    pAccount->PrintBalance();//��ѯ�˻����

    // ʹ��ָ�� Account ��ָ����� Print Balance��
    pAccount = &savings;
    pAccount->PrintBalance();//�����˻����
    return 0;
}
/*
��ǰ��Ĵ����У��� PrintBalance �ĵ�������ͬ�ģ�pAccount ��ָ��Ķ�����⡣ ���� PrintBalance ������ģ���˽�����Ϊÿ��������ĺ����汾�� ������ PrintBalance �� CheckingAccount �е� SavingsAccount ��������д������ Account �еĺ�����

����������಻�ṩ PrintBalance ��������дʵ�֣���ʹ�û��� Account �е�Ĭ��ʵ�֡�

�������еĺ������ڻ����е��麯����������ͬʱ��д��Щ�麯���� �������еĺ�������ֻ�����䷵�������еĻ�����麯����ͬ�������б�Ҳ���벻ͬ��

��ʹ��ָ������õ��ú���ʱ�����¹������ã�

����Ϊ����õĶ���Ļ����������������麯���ĵ��á�

����ָ������õ������������Է��麯���ĵ��á�

����ʾ��˵����ͨ��ָ�����ʱ�麯���ͷ��麯������Ϊ��
*/

#include <iostream>
using namespace std;

class BaseX {
public:
    virtual void NameOf();   //�麯����
    void InvokingClass();   // ���麯����
};

// ʵ�����������ܡ�
void BaseX::NameOf() {
    cout << "Base::NameOf\n";
}

void BaseX::InvokingClass() {
    cout << "Invoked by Base\n";
}

class Derived : public BaseX {
public:
    void NameOf();   // �麯����
    void InvokingClass();   // ���麯����
};

// ʵ�����������ܡ�
void Derived::NameOf() {
    cout << "Derived::NameOf\n";
}

void Derived::InvokingClass() {
    cout << "Invoked by Derived\n";
}

int main130210() {
    //����һ�� Derived ���͵Ķ���
    Derived aDerived;

    // ��������ָ�룬һ���� Derived * ���ͣ���һ����
    // Base * ���ͣ��������ǳ�ʼ��Ϊָ�� Derived��
    Derived* pDerived = &aDerived;
    BaseX* pBase = &aDerived;

    // ���ú�����
    pBase->NameOf();           //�����麯���� //Derived::NameOf
    pBase->InvokingClass();    // ���÷��麯����//Invoked by Base   �������⺯�������о���ִ�л����
    pDerived->NameOf();        // �����麯����//Derived::NameOf
    pDerived->InvokingClass(); // ���÷��麯����//   Invoked by Derived

    return 0;
}