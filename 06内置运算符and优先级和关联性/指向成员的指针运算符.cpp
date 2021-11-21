
#include <iostream>

using namespace std;

class Testpm {
public:
    void m_func1() { cout << "m_func1\n"; }
    int m_num;
};

// 定义派生类型 pmfn 和 pmd。
// 这些类型是指向成员 m func1() 和
// 分别为 m num。
void (Testpm::* pmfn)() = &Testpm::m_func1;
int Testpm::* pmd = &Testpm::m_num;

int main25() {
    Testpm ATestpm;
    Testpm* pTestpm = new Testpm;

    // 访问成员函数
    (ATestpm.*pmfn)();
    (pTestpm->*pmfn)();   // 需要括号，因为 * 绑定
                         // 没有函数调用那么紧密。

// 访问成员数据
    ATestpm.*pmd = 1;
    pTestpm->*pmd = 2;

    cout << ATestpm.*pmd << endl//1
        << pTestpm->*pmd << endl;//2
    delete pTestpm;

    return 0;
}