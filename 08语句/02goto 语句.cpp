
#include <iostream>
int main2() {
    using namespace std;
    goto Test2;

    cout << "testing" << endl;

Test2:
    cerr << "At Test2 label." << endl;

    return 0;
}

//Output: At Test2 label.



/*
源程序中 标识符 标签的外观声明标签。 只有 goto 语句可以将控制转移到 标识符 标签。 下面的代码片段演示如何使用 goto 语句和 标识符 标签：

标签无法独立出现，必须总是附加到语句。 如果标签需要独立出现，则必须在标签后放置一个 null 语句。

标签具有函数范围，并且不能在函数中重新声明。 但是，相同的名称可用作不同函数中的标签。

*/