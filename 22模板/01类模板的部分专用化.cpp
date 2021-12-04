/*
类模板可以部分专用化，生成的类仍是模板。 在类似于下面的情况下，部分专用化允许为特定类型部分自定义模板代码：

模板有多个类型，且只有一部分需要专用化。 结果是基于其余类型参数化的模板。

模板只有一个类型，但指针、引用、指向成员的指针或函数指针类型需要专用化。 专用化本身仍是指向或引用的类型上的模板。

*/



#include <stdio.h>

template <class T> struct PTS {
    enum {
        IsPointer = 0,
        IsPointerToDataMember = 0
    };
};

template <class T> struct PTS<T*> {
    enum {
        IsPointer = 1,
        IsPointerToDataMember = 0
    };
};

template <class T, class U> struct PTS<T U::*> {
    enum {
        IsPointer = 0,
        IsPointerToDataMember = 1
    };
};

struct S {};

int main220501() {
    printf_s("PTS<S>::IsPointer == %d \nPTS<S>::IsPointerToDataMember == %d\n",
        PTS<S>::IsPointer, PTS<S>::IsPointerToDataMember);//0 0
    printf_s("PTS<S*>::IsPointer == %d \nPTS<S*>::IsPointerToDataMember == %d\n"
        , PTS<S*>::IsPointer, PTS<S*>::IsPointerToDataMember);//1 0
    printf_s("PTS<int S::*>::IsPointer == %d \nPTS"
        "<int S::*>::IsPointerToDataMember == %d\n",
        PTS<int S::*>::IsPointer, PTS<int S::*>::
        IsPointerToDataMember);//0  1
    return 0;
}