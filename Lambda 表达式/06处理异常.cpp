
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main0601()
{
    // 创建一个包含 3 个元素的向量。
    vector<int> elements(3);

    // 创建另一个包含索引值的向量。
    vector<int> indices(3);
    indices[0] = 0;
    indices[1] = -1; // 这不是有效的下标。它会触发异常。
    indices[2] = 2;

     // 使用索引值向量中的值
    // 填充元素向量。这个例子使用了一个
    // try/catch 块来处理无效的访问
    // 元素向量。
    try
    {
        for_each(indices.begin(), indices.end(), [&](int index) {
            cout << index<<endl;
            elements.at(index) = index;
            });
    }
    catch (const out_of_range& e)
    {
        
        cerr << "Caught '" << e.what() << "'." << endl;
    };

    //在lambda里面也是可以监听到异常的
    return 0;
}