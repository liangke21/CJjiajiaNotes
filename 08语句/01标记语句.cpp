#include <iostream>
using namespace std;


//有三种标记语句。 它们全都使用冒号将某种标签与语句隔开。 case 和 default 标签特定于 case 语句。
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
    总结 :
    如果 为1  执行goto 标记语句 label1 并且返回//反之执行 goto label2;
    */

    return 0;
}