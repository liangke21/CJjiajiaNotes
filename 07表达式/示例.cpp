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
        pb->test2();  //指向B 是C 的实例 打印 //  test2 in B 向上转型
    cout << "pb : " << pb << endl;


    try {
        C* pc = dynamic_cast<C*>(pa2);
        if (pc)          //指向 B    //向下转型  实际指向的是父类对象
            pc->test2();
        cout << "转换成功 : " << endl;    //    不知道是啥原因 打印失败
    }
    catch (std::bad_cast) {
        cout << "失败 : " << endl;
    }


    C ConStack;
    Globaltest(ConStack);  // 指向  C // 打印 in GlobalTest 

    // 会失败，因为 B 对 C 一无所知
    B BonStack;
    Globaltest(BonStack); //错误这里的引用, 无法转为 C& 引用

    return 0;
}