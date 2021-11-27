



#include <iostream>

using namespace std;
class IntVector {
public:
    IntVector(int cElements);
    ~IntVector() { delete[] _iElements; }
    int& operator[](int nSubscript);
private:
    int* _iElements;
    int _iUpperBound;
};

// 构造一个整数向量。
IntVector::IntVector(int cElements) {
    _iElements = new int[cElements];
    _iUpperBound = cElements;
}

// Int Vector 的下标运算符。
int& IntVector::operator[](int nSubscript) {
    static int iErr = -1;

    if (nSubscript >= 0 && nSubscript < _iUpperBound)
        return _iElements[nSubscript];
    else {
        clog << "数组边界违规。" << endl;
        return iErr;
    }
}
/*
当 i 在上一个程序中达到 10 时 ，operator[] 检测到使用了边界外下标，并发出错误消息。

请注意，函数 运算符[] 返回引用类型。 这会使它成为左值，从而使您可以在赋值运算符的任何一侧使用下标表达式。

*/
// 测试 Int Vector 类。
int main0601() {
    IntVector v(10);
    int i;

    for (i = 0; i <= 10; ++i)
        v[i] = i;

    v[3] = v[9];  //重点把v[9]角标上的值复制给v[3];

    for (i = 0; i <= 10; ++i)
        cout << "Element: [" << i << "] = " << v[i] << endl;

    return 0;
}

/*
Array bounds violation.
Element: [0] = 0
Element: [1] = 1
Element: [2] = 2
Element: [3] = 9       //值变了
Element: [4] = 4
Element: [5] = 5
Element: [6] = 6
Element: [7] = 7
Element: [8] = 8
Element: [9] = 9
Array bounds violation.
Element: [10] = 10

*/