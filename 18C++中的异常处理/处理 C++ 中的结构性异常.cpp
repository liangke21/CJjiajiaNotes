






//#include <iostream>
//
//using namespace std;
//void SEHFunc(void);
//
//int main() {
//    try {
//        SEHFunc();
//    }
//    catch (...) {
//        cout << "捕获 C 异常." << endl;
//    }
//}
//
//void SEHFunc() {
//    __try {
//        int x, y = 0;
//        x = 5 / y;
//    }
//    __finally {
//        cout << "在最后." << endl;
//    }
//}



#include <stdio.h>
#include <eh.h>
#include <windows.h>

class SE_Exception {
private:
    SE_Exception() {}
    unsigned int nSE;
public:
    SE_Exception(SE_Exception& e) : nSE(e.nSE) {}
    SE_Exception(unsigned int n) : nSE(n) {}
    ~SE_Exception() {}
    unsigned int getSeNumber() { return nSE; }
};

void SEFunc() {
    __try {
        int x, y = 1;
        x = 5 / y;
    }
    __finally {
        printf_s("在最后\n");
    }
}

void trans_func(unsigned int u, _EXCEPTION_POINTERS* pExp) {
    printf_s("在反式函数中.\n");
    throw SE_Exception(u);
}

int main() {
    _set_se_translator(trans_func);
    try {
        SEFunc();
    }
    catch (SE_Exception e) {
        printf_s("使用 SE Exception 捕获 try 异常.\n");
        printf_s("nSE = 0x%x\n", e.getSeNumber());
    }
}