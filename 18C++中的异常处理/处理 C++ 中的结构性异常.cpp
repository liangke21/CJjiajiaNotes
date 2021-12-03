






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
//        cout << "���� C �쳣." << endl;
//    }
//}
//
//void SEHFunc() {
//    __try {
//        int x, y = 0;
//        x = 5 / y;
//    }
//    __finally {
//        cout << "�����." << endl;
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
        printf_s("�����\n");
    }
}

void trans_func(unsigned int u, _EXCEPTION_POINTERS* pExp) {
    printf_s("�ڷ�ʽ������.\n");
    throw SE_Exception(u);
}

int main() {
    _set_se_translator(trans_func);
    try {
        SEFunc();
    }
    catch (SE_Exception e) {
        printf_s("ʹ�� SE Exception ���� try �쳣.\n");
        printf_s("nSE = 0x%x\n", e.getSeNumber());
    }
}