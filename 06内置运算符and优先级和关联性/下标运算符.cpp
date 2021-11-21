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

    int* midArray = &intArray[512];  // 指向数组中间的指针  //这里 下标只要在0到1024 都是一个指针

    cout <<"midArray : "<< midArray << endl;
    cout <<"midArray[-256] :" <<midArray[-512] << endl;  // 256  //这个是二维数组

    /*
      假如 一个电梯有1024层,有两批按键 ,一批为上,一批为下,     只能到 512层,
      当到了顶层 ,你要下到511层,就按-1 以此类推 下到 0层 就是512
    */

    cout << "midArray[-256] : "<< & midArray[-256] << endl;
       &intArray[1024];
    cout << intArray[-256] << endl;  // 不可预测，可能会崩溃   //这里的就相当于电梯只能上



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