









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
//        n_except != STATUS_FLOAT_OVERFLOW)   // 传递大多数异常
//        return EXCEPTION_CONTINUE_SEARCH;
//
//    // 执行一些代码来清理问题
//    ResetVars(0);   // 将数据初始化为 0
//    return EXCEPTION_CONTINUE_EXECUTION;
//}