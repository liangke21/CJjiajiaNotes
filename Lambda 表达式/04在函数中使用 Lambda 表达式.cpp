


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Scale
{
public:
    // ���캯����
    explicit Scale(int scale) : _scale(scale) {}

// ��ӡ����������ÿ��Ԫ�صĳ˻�
    // �Ϳ���̨�ı���ֵ��
    void ApplyScale(const vector<int>& v) const
    {
        for_each(v.begin(), v.end(), [=](int n) { cout << n * _scale << endl; });
    }

private:
    int _scale;
};

int main030401()
{
    vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);

// ����һ�� Scale ���󣬽�Ԫ������ 3 ��Ӧ��
    // ����ʸ�����󡣲��޸�������
    Scale s(3);
    s.ApplyScale(values);

    return 0;
}