#include <iostream>
using namespace std;

size_t getPtrSize(char* ptr)
{
    cout << "getPtrSize  " << &ptr << endl;

    cout << "getPtrSize  " << sizeof(ptr) << endl;
    return sizeof(ptr);
}

int main311()
{
    char szHello[] = "Hello, world!";

    cout << "Tһ���ַ��Ĵ�С��: "
        << sizeof(char) //1���ֽ�
        << "\n���� " << szHello << " is: " 
        << sizeof szHello //13 + 1
        << "\nָ��Ĵ�С�� "
        << getPtrSize(szHello) << endl; //13

    return 0;
}