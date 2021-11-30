// template_lambda_expression.cpp
// compile with: /EHsc
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 否定向量对象中的每个元素。假定有符号数据类型。
template <typename T>
void negate_all(vector<T>& v)
{
    for_each(v.begin(), v.end(), [](T& n) { n = -n; });
}

// 将矢量对象中的每个元素打印到控制台。
template <typename T>
void print_all(const vector<T>& v)
{
    for_each(v.begin(), v.end(), [](const T& n) { cout << n << endl; });
}

int main030501()
{
    // 创建一个包含几个元素的有符号整数向量。
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