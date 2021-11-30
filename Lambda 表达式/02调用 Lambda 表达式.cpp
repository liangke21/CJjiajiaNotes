

#include <iostream>

int main030201()
{
	using namespace std;
	int n = [](int x, int y) { return x + y; }(5, 4);
	cout << n << endl;//9

	return 0;
}


#include <list>
#include <algorithm>
#include <iostream>

int main030202()
{
    using namespace std;

    // 创建一个带有几个初始元素的整数列表。
    list<int> numbers;
    numbers.push_back(13);
    numbers.push_back(17);
    numbers.push_back(42);
    numbers.push_back(46);
    numbers.push_back(99);

    // 使用 find if 函数和 lambda 表达式来查找
    // 列表中的第一个偶数。
    const list<int>::const_iterator result =
        find_if(numbers.begin(), numbers.end(), [](int n) { return (n % 2) == 0; });

    // 打印结果.
    if (result != numbers.end()) {
        cout << "列表中的第一个偶数是 " << *result << "." << endl;
    }
    else {
        cout << "该列表不包含偶数." << endl;
    }

    return 0;
}
