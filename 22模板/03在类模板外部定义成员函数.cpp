

/*
������ģ���ⶨ��ģ��ĳ�Ա����ʱ��
����ʹ�ò�ͬ��ģ��������ơ� 
���ģ���Ա����������������ģ�����ʹ���˲�ͬ�����ƣ�


//�ܵ�::���Ҷ�����ʹ�õ�������������������Ա��ͻ����ģ�������еĳ�Ա���ȡ�
*/

#include <iostream>
using namespace std;

template <class T> class C {
public:
    struct Z {
        Z() { cout << "Z::Z()" << endl; }
    };
    void f();
};

template <class Z>
void C<Z>::f() {
// Z ָ���ǽṹ Z��������ģ�� arg��
    // ��ˣ������� struct Z �Ĺ��캯����
    Z z;
}

int main22060301() {
    C<int> c;
    c.f();

    return 0;
}