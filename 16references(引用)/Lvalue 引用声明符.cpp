


#include <iostream>
using namespace std;

struct Person
{
    char* Name;
    short Age;
};

int main0201()
{
// ����һ�� Person ����
    Person myFriend;

// ������Person ��������á�
    Person& rFriend = myFriend;


    cout << &myFriend << endl << &rFriend;
// ����Person ������ֶΡ�
    // ������һ�������������ͬ�Ķ���
 //   myFriend.Name = "Bill";
    rFriend.Age = 40;

// �� Person ������ֶδ�ӡ������̨��
    cout << rFriend.Name << " is " << myFriend.Age << endl;

    return 0;
}