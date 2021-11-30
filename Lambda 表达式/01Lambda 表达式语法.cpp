
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;



void  fun(int(*func)(int, int)) {

    for (int a = 0;a <= 10;a++) {

      int c = func(a, a);
      cout << "lambda : ����ֵ " << c<<endl;
    }

 

 }
int main0201()
{

    fun([](int a, int b) {
        cout << a << "  " << b<<"  ";
        return a;
        });





    // ����һ������ 9 ��Ԫ�ص�ʸ������
    vector<int> v;
    for (int i = 1; i < 10; ++i) {
        v.push_back(i);
    }

    // ����������ż���ĸ���
    // ʹ�� for ÿ��������һ�� lambda��
    int evenCount = 0;
    for_each(v.begin(), v.end(), [&evenCount](int n) {
        cout << n;
        if (n % 2 == 0) {
            cout << " �� ż�� " << endl;
            ++evenCount;
        }
        else {
            cout << " �� ����" << endl;
        }
        });

    // ��ż���ļ�����ӡ������̨��
    cout << "��  " << evenCount
        << " �����е�ż����" << endl;


    return 0;
}