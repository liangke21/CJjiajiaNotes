#include <iostream>

using namespace std;
//省略号和可变参数模板 
void print() {
    cout << endl;
}

template <typename T> void print(const T& t) {
    cout << t << endl;
}

template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {
    cout << first << ", ";
    print(rest...); // 使用包扩展语法的递归调用
}

int main01021()
{
    print(); // 调用第一个重载，只输出一个换行符
    print(1); // 调用第二次重载

    // 这些调用第三个重载，可变参数模板，
    // 根据需要使用递归。
    print(10, 20);
    print(100, 200, 300);
    print("first", 2, "third", 3.14159);

    return  0;

    //总结 可变参数,适用于,不知道用户要给多少个参数
}