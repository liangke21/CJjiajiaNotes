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

int main9()
{
    std::cout << alignof(struct x_) << std::endl; // output: 16
    return 0;
}

//bool char short int 、和 long 4 字节
//float long long double 边界上、、以及 long double 8 字节边界上。

struct MyStruct
{
    long a;
    long b;
    long c;
    long d;
};
//这里不管有多少个long 都会在4个字节边界上
int main92()
{
    std::cout <<"MyStruct : "<< alignof(MyStruct) << std::endl; // 4

    return 0;
}

struct MyStruct2
{

};
//默认在1的边界上
int main93() {

    std::cout << "MyStruct2 : " << alignof(MyStruct2) << std::endl; // 4

    return 0;
}

struct MyStruct3
{
    long a; //如果是一个long 会在4个字节的边界上对齐

    long long b; //这里的long long 在8个字节的边界上

    //这里会按照大小值 对类和结构对齐  那么一定就回事 8

    long long e[100]; //对齐字节还是8


};

int main94() {

    std::cout << "MyStruct3 : " << alignof(MyStruct3) << std::endl; // 4

    return 0;
}

struct MyStruct4
{

    char a[100];
};

int main95() {

    std::cout << "MyStruct4 : " << alignof(MyStruct4) << std::endl; // 4

    return 0;
}
