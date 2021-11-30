
#include <functional>
#include <iostream>

int main0301()
{

    using namespace std;

    // ���佫����������ӵ��Զ������� lambda ���ʽ��
    auto f1 = [](int x, int y) { return x + y; };

    cout << f1(2, 3) << endl;

    //����ͬ�� lambda ���ʽ�������������
    function<int(int, int)> f2 = [](int x, int y) { return x + y; };

    cout << f2(3, 4) << endl;

    return 0;
}



#include <functional>
#include <iostream>

int main030102()
{
    using namespace std;

    int i = 3;
    int j = 5;

    // ���� lambda ���ʽ��ֵ���� i ����
    // j �ο���
    function<int(void)> f = [i, &j] { return i + j; };

    // ���� i �� j ��ֵ��
    i = 22;
    j = 44;

    // ���� f ����ӡ������
    cout << f() << endl;

    return 0;
}
/*
�����ñ��ʽʱ��Microsoft C++ �������� lambda ���ʽ�󶨵��䲶��ı������������ڵ��ñ��ʽʱ��
����ʾ����ʾһ��ͨ��ֵ����ֲ����� i ��ͨ�����ò���ֲ����� j �� lambda ���ʽ�� 
���� lambda ���ʽͨ��ֵ���� i������ڳ�����沿��������ָ�� i ��Ӱ��ñ��ʽ�Ľ����
���ǣ����� lambda ���ʽͨ�����ò��� j���������ָ�� j ��Ӱ��ñ��ʽ�Ľ����


*/