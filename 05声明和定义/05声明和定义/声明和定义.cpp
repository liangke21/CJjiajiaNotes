#include <string>

//����
int f(int i); // ��ǰ�걨

int main1()
{
    const double pi = 3.14; //OK
    int i = f(2); //OK. f ��Ԥ��������
    std::string str; // OK std::string �� &lt;string&gt; ��ͷ������
  //  C obj; // ���� C ��δ������
 //   j = 0; // ����δָ�����͡�
    auto k = 0; // �õġ����ͱ��������ƶ�Ϊ int��

    return 0;
}

int f(int i)
{
    return i + 42;
}

namespace N {
    class C {/*...*/ };
}

//����
// �����Ͷ��� int ���� i �� j��
int i;
int j = 10;

// ����ö����װ��
enum suits { Spades = 1, Clubs, Hearts, Diamonds };

// �����ิѡ��
//class CheckBox : public Control
//{
//public:
//   // Boolean IsChecked();
//    virtual int     ChangeState() = 0;
//};

class a {
    //�������⺯��
    virtual int     ChangeState() = 0;
    virtual int     cha() = 0;
};

// ���Ƕ��������
extern int i;
char* strchr(const char* Str, const char Target);