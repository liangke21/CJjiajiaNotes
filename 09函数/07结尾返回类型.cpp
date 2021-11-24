#include <iostream>
using namespace std;

template<typename Lhs, typename Rhs>
auto Add(const Lhs& lhs, const Rhs& rhs) -> decltype(lhs + rhs) // decltype(lhs + rhs) 推断函数返回了类型
{

  //  cout << typeid(lhs).name << typeid(rhs).name << endl;

    return lhs + rhs;
}

int main010701() {

    Add(6, 4);
    return 0;
}