
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main0101()
{
	int m = 0;
	int n = 0;
	[&, n](int a) mutable { m = ++n + a; }(4);

	cout << m << endl << n << endl;

    return 0;
}

/*由于变量 n 是通过值捕获的，因此在调用 lambda 表达式后，变量的值仍保持 0 不变。 该 mutable 规范允许在 n lambda 中修改。

*/

void fillVector2(vector<int>& v)
{
    //局部静态变量。
    static int nextValue = 1;

// 出现在以下调用中的 lambda 表达式
    // 生成函数修改并使用本地静态
    // 变量下一个值。
    generate(v.begin(), v.end(), [] { return nextValue++; });  //这里传入的参数 就是 lambda表示返回的参数
    //警告：这不是线程安全的，仅用于说明
}

/*
下面的代码示例使用上一示例中的函数，并添加了使用 c + + 标准库算法的 lambda 表达式的示例 generate_n 。
该 lambda 表达式将 vector 对象的元素指派给前两个元素之和。
mutable 使用关键字，以便 lambda 表达式的主体可以修改其外部变量的副本 x 和 y lambda 表达式通过值捕获的副本。
由于 lambda 表达式通过值捕获原始变量 x 和 y，因此它们的值在 lambda 执行后仍为 1。


*/

// compile with: /W4 /EHsc
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename C> void print(const string& s, const C& c) {
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

void fillVector(vector<int>& v)
{
    // 局部静态变量。
    static int nextValue = 1;

   // 出现在以下调用中的 lambda 表达式
    // 生成函数修改并使用本地静态
    // 变量下一个值。
    generate(v.begin(), v.end(), [] { return nextValue++; });
    //警告：这不是线程安全的，仅用于说明
}

int main0102()
{
    // 向量中的元素数。
    const int elementCount = 9;

    // 创建一个矢量对象，每个元素都设置为 1。
    vector<int> v(elementCount, 1);

    // 这些变量保存向量的前两个元素。
    int x = 1;
    int y = 1;
    print("v 向量  ", v);
    // 将向量中的每个元素设置为
    // 前两个元素。
    generate_n(v.begin() + 2,
        elementCount - 2,//7
        [=]() mutable throw() -> int { // lambda 是第三个参数  //2
        // 生成当前值。
            int n = x + y;
            // 更新前两个值。
            x = y;  //1
            y = n;  //2
            return n;
        });
    print("调用后的向量 v generate_n() with lambda: ", v);

  // 打印局部变量 x 和 y。
    // x 和 y 的值保持它们的初始值，因为
    // 它们是按值捕获的。
    cout << "x: " << x << " y: " << y << endl;

    // 用数字序列填充向量
    fillVector(v);
    print("第一次调用后的向量 v fillVector(): ", v);
    // 用下一个数字序列填充向量
    fillVector(v);
    print("第二次调用后的向量 v fillVector(): ", v);

    return 0;
}