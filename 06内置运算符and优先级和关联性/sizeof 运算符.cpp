#include <iostream>
using namespace std;

size_t getPtrSize(char* ptr)
{
    cout << "getPtrSize  " << &ptr << endl;

    cout << "getPtrSize  " << sizeof(ptr) << endl;
    return sizeof(ptr);
}

int main()
{
    char szHello[] = "Hello, world!";

    cout << "T一个字符的大小是: "
        << sizeof(char) //1个字节
        << "\n长度 " << szHello << " is: " 
        << sizeof szHello //13 + 1
        << "\n指针的大小是 "
        << getPtrSize(szHello) << endl; //13
}