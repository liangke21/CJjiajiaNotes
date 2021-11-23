#include <iostream>
using namespace std;
//指针类型之间的转换
// 返回基于地址的哈希码
unsigned short Hash(void* p) {

    cout <<"p类型 : "<< typeid(p).name()<<"    :";


    unsigned int val = reinterpret_cast<unsigned int>(p);  //不做检查
    return (unsigned short)(val ^ (val >> 16));
}

int main() {
    int a[20];
    for (int i = 0; i < 20; i++)
        cout << Hash(a + i) << endl;
}
