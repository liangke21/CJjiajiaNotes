

// switch_statement1.cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int main() {
    const char* buffer = "�����ַ���";
    int uppercase_A, lowercase_a, other;
    char c;
    uppercase_A = lowercase_a = other = 0;

    cout << "buffer222 : " << buffer<< endl;

    while (c = *buffer++)   // ����������ֱ�� NULL
    {
        cout << "buffer : " << buffer<<c<<endl;

        switch (c)
        {
        case 'A':
            uppercase_A++;
            break;
        case 'a':
            lowercase_a++;
            break;
        default:
            other++;
        }
    }
    printf_s("\nUppercase A: %d\nLowercase a: %d\nTotal: %d\n",
        uppercase_A, lowercase_a, (uppercase_A + lowercase_a + other));
}