









//#include <windows.h>
//int main() {
//    int Eval_Exception(int);
//
//    __try {}
//
//    __except (Eval_Exception(GetExceptionCode())) {
//        ;
//    }
//
//}
//void ResetVars(int) {}
//int Eval_Exception(int n_except) {
//    if (n_except != STATUS_INTEGER_OVERFLOW &&
//        n_except != STATUS_FLOAT_OVERFLOW)   // ���ݴ�����쳣
//        return EXCEPTION_CONTINUE_SEARCH;
//
//    // ִ��һЩ��������������
//    ResetVars(0);   // �����ݳ�ʼ��Ϊ 0
//    return EXCEPTION_CONTINUE_EXECUTION;
//}