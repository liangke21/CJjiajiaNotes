#include <iostream>
using namespace std;

int main311() {
    int intArray[1024];
    for (int i = 0, j = 0; i < 1024; i++)
    {
        intArray[i] = j++;
    }
    cout << &intArray[0] << endl;
    cout <<"intArray[512] : "<< & intArray[512] << endl;

    cout << intArray[512] << endl;   // 512

    cout << 257[intArray] << endl;   // 257

    int* midArray = &intArray[512];  // ָ�������м��ָ��  //���� �±�ֻҪ��0��1024 ����һ��ָ��

    cout <<"midArray : "<< midArray << endl;
    cout <<"midArray[-256] :" <<midArray[-512] << endl;  // 256  //����Ƕ�ά����

    /*
      ���� һ��������1024��,���������� ,һ��Ϊ��,һ��Ϊ��,     ֻ�ܵ� 512��,
      �����˶��� ,��Ҫ�µ�511��,�Ͱ�-1 �Դ����� �µ� 0�� ����512
    */

    cout << "midArray[-256] : "<< & midArray[-256] << endl;
       &intArray[1024];
    cout << intArray[-256] << endl;  // ����Ԥ�⣬���ܻ����   //����ľ��൱�ڵ���ֻ����



    int a = 0;
    printf("%p\n", &a);
    char* b = (char*)&a;
    cout << b << endl;
    *b = 'a';
    printf("%p\n", b);
    printf("%d\n", a);


    char c[4] = { 0 };
    int* d = (int*)&c[0];
    *d = 97;
    printf("%c\n", c[0]);
    return 0;
}