// even_functor.cpp
// compile with: /EHsc
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class FunctorClass
{
public:
    // 此示例所需的构造函数。
    explicit FunctorClass(int& evenCount)
        : m_evenCount(evenCount) { }

    // 函数调用运算符打印数字是否为
    // 偶数或奇数。如果数字是偶数，则此方法更新
    //柜台。
    void operator()(int n) const {
        cout << n;

        if (n % 2 == 0) {
            cout << " is even " << endl;
            ++m_evenCount;
        }
        else {
            cout << " is odd " << endl;
        }
    }

private:
    // 默认赋值运算符使警告 C4512 静音。
    FunctorClass& operator=(const FunctorClass&);

    int& m_evenCount; // 向量中偶数变量的数量。
};

int main0202()
{
    // 创建一个包含 9 个元素的矢量对象。
    vector<int> v;
    for (int i = 1; i < 10; ++i) {
        v.push_back(i);
    }

// 计算向量中偶数的个数
    // 使用 for 每个函数和一个函数对象。
    int evenCount = 0;
    for_each(v.begin(), v.end(), FunctorClass(evenCount));

    // 将偶数的计数打印到控制台。
    cout << "There are " << evenCount
        << " even numbers in the vector." << endl;
    return 0;
}