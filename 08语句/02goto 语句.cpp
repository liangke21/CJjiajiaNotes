
#include <iostream>
int main2() {
    using namespace std;
    goto Test2;

    cout << "testing" << endl;

Test2:
    cerr << "At Test2 label." << endl;

    return 0;
}

//Output: At Test2 label.



/*
Դ������ ��ʶ�� ��ǩ�����������ǩ�� ֻ�� goto �����Խ�����ת�Ƶ� ��ʶ�� ��ǩ�� ����Ĵ���Ƭ����ʾ���ʹ�� goto ���� ��ʶ�� ��ǩ��

��ǩ�޷��������֣��������Ǹ��ӵ���䡣 �����ǩ��Ҫ�������֣�������ڱ�ǩ�����һ�� null ��䡣

��ǩ���к�����Χ�����Ҳ����ں��������������� ���ǣ���ͬ�����ƿ�������ͬ�����еı�ǩ��

*/