// template_lambda_expression.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// �����������е�ÿ��Ԫ�ء��ٶ��з����������͡�
template <typename T>
void negate_all(vector<T>& v)
{
    for_each(v.begin(), v.end(), [](T& n) { n = -n; });
}

// ��ʸ�������е�ÿ��Ԫ�ش�ӡ������̨��
template <typename T>
void print_all(const vector<T>& v)
{
    for_each(v.begin(), v.end(), [](const T& n) { cout << n << endl; });
}

int main030501()
{
    // ����һ����������Ԫ�ص��з�������������
    vector<int> v;
    v.push_back(34);
    v.push_back(-43);
    v.push_back(56);

    print_all(v);//34  -43 56
    negate_all(v);//
    cout << "After negate_all():" << endl;
    print_all(v);
    return 0;
}