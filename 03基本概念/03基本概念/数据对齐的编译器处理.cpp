#include <iostream>
using namespace std;
struct x_
{
	char a;     // 1 byte
	int b;      // 4 bytes
	short c;    // 2 bytes
	char d;     // 1 byte
} bar[3];


// compile with: cl /EHsc alignas_alignof.cpp
#include <iostream>

struct alignas(16) Bar
{
    int i;       // 4 bytes
    int n;      // 4 bytes
    alignas(4) char arr[3];
    short s;          // 2 bytes
};

int main()
{
    std::cout << alignof(Bar) << std::endl; // output: 16
}