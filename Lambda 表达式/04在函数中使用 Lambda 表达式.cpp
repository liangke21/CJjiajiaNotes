


#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Scale
{
public:
    // 构造函数。
    explicit Scale(int scale) : _scale(scale) {}

// 打印向量对象中每个元素的乘积
    // 和控制台的比例值。
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

// 创建一个 Scale 对象，将元素缩放 3 并应用
    // 它到矢量对象。不修改向量。
    Scale s(3);
    s.ApplyScale(values);

    return 0;
}