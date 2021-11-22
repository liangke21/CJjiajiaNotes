// dynamic_cast_8.cpp
// compile with: /GR /EHsc
#include <stdio.h>
#include <iostream>
using namespace std;

struct A {
    virtual void test() {
        printf_s("in A\n");
    }
};

struct B : A {
    virtual void test() {
        printf_s("in B\n");
    }

    void test2() {
        printf_s("test2 in B\n");
    }
};

struct C : B {
    virtual void test() {
        printf_s("in C\n");
    }

    void test2() {
        printf_s("test2 in C\n");
    }
};

void Globaltest(A& a) {
    try {
        C& c = dynamic_cast<C&>(a);
        printf_s("in GlobalTest\n");
    }
    catch (std::bad_cast) {
        printf_s("Can't cast to C\n");
    }
}

int main041() {
    A* pa = new C;
    A* pa2 = new B;

    cout << "pa : " << pa << endl;
    cout << "pa2 : " << pa2 << endl;




    pa->test();

    B* pb = dynamic_cast<B*>(pa);
    if (pb)
        pb->test2();  //ָ��B ��C ��ʵ�� ��ӡ //  test2 in B ����ת��
    cout << "pb : " << pb << endl;


    try {
        C* pc = dynamic_cast<C*>(pa2);
        if (pc)          //ָ�� B    //����ת��  ʵ��ָ����Ǹ������
            pc->test2();
        cout << "ת���ɹ� : " << endl;    //    ��֪����ɶԭ�� ��ӡʧ��
    }
    catch (std::bad_cast) {
        cout << "ʧ�� : " << endl;
    }


    C ConStack;
    Globaltest(ConStack);  // ָ��  C // ��ӡ in GlobalTest 

    // ��ʧ�ܣ���Ϊ B �� C һ����֪
    B BonStack;
    Globaltest(BonStack); //�������������, �޷�תΪ C& ����

    return 0;
}