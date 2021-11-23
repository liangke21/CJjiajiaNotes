// range-based-for.cpp
// compile by using: cl /EHsc /nologo /W4
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //������ 10 Ԫ���������顣
    int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // ���ڷ�Χ�� for ѭ���������顣
    for (int y : x) { // ʹ������Ϊ�ض����͵ĸ�����ֵ���ʡ�
                       // ������ѡ��
        cout << y << " ";
    }
    cout << endl;//1-10

    // auto �ؼ��ֵ���ʹ�������ƶϡ���ѡ��

    for (auto y : x) { // &#39;x&#39; �ĸ������������ǲ��ܻ�ӭ��
        cout << y << " ";
    }
    cout << endl;//1-10

    for (auto& y : x) { // ͨ�����ý��������ƶϡ�
        // �͵ع۲��/���޸ġ���Ҫ�޸�ʱ��ѡ��
        cout << y << " ";
    }
    cout << endl;//1-10 

    for (const auto& y : x) { // Type ͨ���������ý����ƶϡ�
        // �͵ع۲졣����Ҫ�޸�ʱ��ѡ��
        cout << y << " ";//1-10 
    }
    cout << endl;
    cout << "����������Խ���" << endl;
    cout << endl;

    // ����һ������ 10 ��Ԫ�ص�ʸ������
    vector<double> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i + 0.14159);
    }

    // ���ڷ�Χ�� for ѭ�������������͵ع۲졣
    for (const auto& j : v) {
        cout << j << " "; //���� V
    }
    cout << endl;
    cout << "ʸ�����Խ���" << endl;
}