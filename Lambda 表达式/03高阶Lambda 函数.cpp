
#include <iostream>
#include <functional>

int main030301()
{
    using namespace std;
// ����Ĵ���������һ�����ص� lambda ���ʽ
    // ��һ��������������ӵ� lambda ���ʽ��
    // ���ص� lambda ���ʽ��ֵ������� x��
    auto addtwointegers = [](int x) -> function<int(int)> {//->��ʾ��������
        return [=](int y) { return x + y; };
    };

// ����Ĵ���������һ�� lambda ���ʽ����������һ��
    // lambda ���ʽ��Ϊ���Ĳ�����
    // lambda ���ʽ������ z Ӧ���ں��� f
    // ������ 2��
    auto higherorder = [](const function<int(int)>& f, int z) {
        return f(z) * 2;
    };

    // ���ð󶨵��߽׵� lambda ���ʽ��
    auto answer = higherorder(addtwointegers(7), 8);

    // ��ӡ������� (7+8)*2.
    cout << answer << endl;//30

    return 0;
}