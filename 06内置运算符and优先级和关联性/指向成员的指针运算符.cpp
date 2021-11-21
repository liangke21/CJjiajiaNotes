
#include <iostream>

using namespace std;

class Testpm {
public:
    void m_func1() { cout << "m_func1\n"; }
    int m_num;
};

// ������������ pmfn �� pmd��
// ��Щ������ָ���Ա m func1() ��
// �ֱ�Ϊ m num��
void (Testpm::* pmfn)() = &Testpm::m_func1;
int Testpm::* pmd = &Testpm::m_num;

int main25() {
    Testpm ATestpm;
    Testpm* pTestpm = new Testpm;

    // ���ʳ�Ա����
    (ATestpm.*pmfn)();
    (pTestpm->*pmfn)();   // ��Ҫ���ţ���Ϊ * ��
                         // û�к���������ô���ܡ�

// ���ʳ�Ա����
    ATestpm.*pmd = 1;
    pTestpm->*pmd = 2;

    cout << ATestpm.*pmd << endl//1
        << pTestpm->*pmd << endl;//2
    delete pTestpm;

    return 0;
}