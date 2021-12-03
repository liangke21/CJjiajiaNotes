


#include <stdio.h>

void handler() {
    printf_s("in handler\n");
}

void f1(void) throw(int) {
    printf_s("About to throw 1\n");
    if (1)
        throw 1;
}

void f5(void) throw() {
    try {
        f1();
    }
    catch (...) {
        handler();
    }
}

// 无效，不处理从 f1() 抛出的 int 异常
// void f3(void) throw() {
//   f1();
// }

void __declspec(nothrow) f2(void) {
    try {
        f1();
    }
    catch (int) {
        handler();
    }
}


extern "C" void f4(void);
void f4(void) {
    f1();
}

int main180701() {
    f2();

    try {
        f4();
    }
    catch (...) {
        printf_s("Caught exception from f4\n");
    }
    f5();

    return 0;
}
/*
About to throw 1
in handler
About to throw 1
Caught exception from f4

About to throw 1
in handler
*/