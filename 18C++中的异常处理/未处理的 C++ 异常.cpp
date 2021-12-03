





/*
如果当前异常 (或省略号处理程序) ，则调用预定义的 catchterminate 运行时函数。 (还可以在任何 terminate handlers.) 中显式调用 的默认操作 terminate 是调用 abort 。 如果你希望 terminate 在退出应用程序之前调用程序中的某些其他函数，则用被调用函数的名称作为其单个自变量调用 set_terminate 函数。 您可以在程序的任何点调用 set_terminate。 例程 terminate 始终调用最后一个作为 的参数给定的函数 set_terminate 。
*/


#include <iostream>
using namespace std;
void term_func() {
    cout << "term func 被终止调用." << endl;
    exit(-1);
}
int main180901() {
    try
    {
        set_terminate(term_func); //不会执行这个函数, 没有处理的异常可以这样操作

        term_func();
        set_terminate(term_func);
        throw "Out of memory!"; // 此异常没有捕获处理程序
    }
    catch (int)
    {
        cout << "引发整数异常." << endl;
    }
    return 0;
}