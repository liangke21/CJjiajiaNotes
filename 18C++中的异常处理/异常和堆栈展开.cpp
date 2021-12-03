





#include <string>
#include <iostream>
using namespace std;

class MyException {};
class Dummy
{
public:
    Dummy(string s) : MyName(s) { PrintMsg("Created Dummy:"); }
    Dummy(const Dummy& other) : MyName(other.MyName) { PrintMsg("Copy created Dummy:"); }
    ~Dummy() { PrintMsg("Destroyed Dummy:"); }
    void PrintMsg(string s) { cout << s << MyName << endl; }
    string MyName;
    int level;
};

void C(Dummy d, int i)
{
    cout << "Entering FunctionC" << endl;
    d.MyName = " C";
    throw MyException();

    cout << "Exiting FunctionC" << endl;
}

void B(Dummy d, int i)
{
    cout << "Entering FunctionB" << endl;
    d.MyName = "B";
    C(d, i + 1);
    cout << "Exiting FunctionB" << endl;
}

void A(Dummy d, int i)
{
    cout << "Entering FunctionA" << endl;
    d.MyName = " A";
    //  Dummy* pd = new Dummy("new Dummy"); //Not exception safe!!!
    B(d, i + 1);//ִ�и��ƹ��캯��
    //   delete pd;
    cout << "Exiting FunctionA" << endl;
}

int main180601()
{
    cout << "Entering main" << endl;
    try
    {
        Dummy d(" M");//ִ�й��캯�� ����string���͵Ĳ���
        A(d, 1);//ִ�� ���ƹ��캯��
    }
    catch (MyException& e)
    {
        cout << "Caught an exception of type: " << typeid(e).name() << endl;
    }

    cout << "Exiting main." << endl;
    char c;
    cin >> c;
    return 0;
}

/*
����ʾ����ʾ�����쳣ʱ���չ����ջ��
�߳�ִ�н��� C �е� throw �����ת�� main �е� catch ��䣬
���ڴ˹�����չ��ÿ�������� ��ע�ⴴ�� Dummy �����˳��
���һ������ǳ�����Χʱ�������١� ����ע�⣬���˰��� catch ���� main ֮�⣬����������δ��ɡ�
���� A ���������� B() �ĵ��÷��أ����� B ���������� C() �ĵ��÷��ء�
���ȡ��ע�� Dummy ָ�����Ӧ�� delete ���Ķ��岢���г�����ע�������ɾ����ָ�롣
��˵���˵��������ṩ�쳣��֤ʱ�ᷢ���������
�й���ϸ��Ϣ������ġ���Σ�����쳣������ơ���
���ע�͵� catch ��䣬����Թ۲쵱������δ��������쳣����ֹʱ�������������
*/

/* Output:
    Entering main
    Created Dummy: M
    Copy created Dummy: M
    Entering FunctionA
    Copy created Dummy: A
    Entering FunctionB
    Copy created Dummy: B
    Entering FunctionC
    Destroyed Dummy: C
    Destroyed Dummy: B
    Destroyed Dummy: A
    Destroyed Dummy: M
    Caught an exception of type: class MyException
    Exiting main.

*/