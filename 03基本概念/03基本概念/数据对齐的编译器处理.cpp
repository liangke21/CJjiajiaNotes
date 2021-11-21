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

//bool char short int ���� long 4 �ֽ�
//float long long double �߽��ϡ����Լ� long double 8 �ֽڱ߽��ϡ�

struct MyStruct
{
    long a;
    long b;
    long c;
    long d;
};
//���ﲻ���ж��ٸ�long ������4���ֽڱ߽���
int main92()
{
    std::cout <<"MyStruct : "<< alignof(MyStruct) << std::endl; // 4

    return 0;
}

struct MyStruct2
{

};
//Ĭ����1�ı߽���
int main93() {

    std::cout << "MyStruct2 : " << alignof(MyStruct2) << std::endl; // 4

    return 0;
}

struct MyStruct3
{
    long a; //�����һ��long ����4���ֽڵı߽��϶���

    long long b; //�����long long ��8���ֽڵı߽���

    //����ᰴ�մ�Сֵ ����ͽṹ����  ��ôһ���ͻ��� 8

    long long e[100]; //�����ֽڻ���8


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
