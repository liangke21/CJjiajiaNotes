// even_functor.cpp
// compile with: /EHsc
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class FunctorClass
{
public:
    // ��ʾ������Ĺ��캯����
    explicit FunctorClass(int& evenCount)
        : m_evenCount(evenCount) { }

    // ���������������ӡ�����Ƿ�Ϊ
    // ż�������������������ż������˷�������
    //��̨��
    void operator()(int n) const {
        cout << n;

        if (n % 2 == 0) {
            cout << " is even " << endl;
            ++m_evenCount;
        }
        else {
            cout << " is odd " << endl;
        }
    }

private:
    // Ĭ�ϸ�ֵ�����ʹ���� C4512 ������
    FunctorClass& operator=(const FunctorClass&);

    int& m_evenCount; // ������ż��������������
};

int main0202()
{
    // ����һ������ 9 ��Ԫ�ص�ʸ������
    vector<int> v;
    for (int i = 1; i < 10; ++i) {
        v.push_back(i);
    }

// ����������ż���ĸ���
    // ʹ�� for ÿ��������һ����������
    int evenCount = 0;
    for_each(v.begin(), v.end(), FunctorClass(evenCount));

    // ��ż���ļ�����ӡ������̨��
    cout << "There are " << evenCount
        << " even numbers in the vector." << endl;
    return 0;
}