

// switch_statement1.cpp
#include <stdio.h>
#include <iostream>
using namespace std;

int main06030101() {
    const char* buffer = "任意字符流";
    int uppercase_A, lowercase_a, other;
    char c;
    uppercase_A = lowercase_a = other = 0;

    cout << "buffer222 : " << buffer<< endl;

    while (c = *buffer++)   // 遍历缓冲区直到 NULL
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

    return 0;
}