#include <iostream>
using namespace std;
//ָ������֮���ת��
// ���ػ��ڵ�ַ�Ĺ�ϣ��
unsigned short Hash(void* p) {

    cout <<"p���� : "<< typeid(p).name()<<"    :";


    unsigned int val = reinterpret_cast<unsigned int>(p);  //�������
    return (unsigned short)(val ^ (val >> 16));
}

int main0401051() {
    int a[20];
    for (int i = 0; i < 20; i++)
        cout << Hash(a + i) << endl;

    return 0;
}
