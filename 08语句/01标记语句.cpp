#include <iostream>
using namespace std;


//�����ֱ����䡣 ����ȫ��ʹ��ð�Ž�ĳ�ֱ�ǩ���������� case �� default ��ǩ�ض��� case ��䡣
void test_label(int x) {

    if (x == 1) {
        goto label1;
    }
    goto label2;

label1:
    cout << "in label1" << endl;
    return;

label2:
    cout << "in label2" << endl;
    return;
}

int main0301() {
    test_label(1);  // in label1
    test_label(2);  // in label2

    /*
    �ܽ� :
    ��� Ϊ1  ִ��goto ������ label1 ���ҷ���//��ִ֮�� goto label2;
    */

    return 0;
}