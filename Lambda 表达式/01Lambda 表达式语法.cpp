
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;



void  fun(int(*func)(int, int)) {

    for (int a = 0;a <= 10;a++) {

      int c = func(a, a);
      cout << "lambda : 返回值 " << c<<endl;
    }

 

 }
int main0201()
{

    fun([](int a, int b) {
        cout << a << "  " << b<<"  ";
        return a;
        });





    // 创建一个包含 9 个元素的矢量对象。
    vector<int> v;
    for (int i = 1; i < 10; ++i) {
        v.push_back(i);
    }

    // 计算向量中偶数的个数
    // 使用 for 每个函数和一个 lambda。
    int evenCount = 0;
    for_each(v.begin(), v.end(), [&evenCount](int n) {
        cout << n;
        if (n % 2 == 0) {
            cout << " 是 偶数 " << endl;
            ++evenCount;
        }
        else {
            cout << " 是 奇数" << endl;
        }
        });

    // 将偶数的计数打印到控制台。
    cout << "有  " << evenCount
        << " 向量中的偶数。" << endl;


    return 0;
}