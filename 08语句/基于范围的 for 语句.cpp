// range-based-for.cpp
// compile by using: cl /EHsc /nologo /W4
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //基本的 10 元素整数数组。
    int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // 基于范围的 for 循环遍历数组。
    for (int y : x) { // 使用声明为特定类型的副本按值访问。
                       // 不是首选。
        cout << y << " ";
    }
    cout << endl;//1-10

    // auto 关键字导致使用类型推断。首选。

    for (auto y : x) { // &#39;x&#39; 的副本，几乎总是不受欢迎的
        cout << y << " ";
    }
    cout << endl;//1-10

    for (auto& y : x) { // 通过引用进行类型推断。
        // 就地观察和/或修改。需要修改时首选。
        cout << y << " ";
    }
    cout << endl;//1-10 

    for (const auto& y : x) { // Type 通过常量引用进行推断。
        // 就地观察。不需要修改时首选。
        cout << y << " ";//1-10 
    }
    cout << endl;
    cout << "整数数组测试结束" << endl;
    cout << endl;

    // 创建一个包含 10 个元素的矢量对象。
    vector<double> v;
    for (int i = 0; i < 10; ++i) {
        v.push_back(i + 0.14159);
    }

    // 基于范围的 for 循环遍历向量，就地观察。
    for (const auto& j : v) {
        cout << j << " "; //遍历 V
    }
    cout << endl;
    cout << "矢量测试结束" << endl;
}