


#include <iostream>
using namespace std;

int fLogMemory = 0;      // 执行日志记录 (0=no; nonzero=yes)?
int cBlocksAllocated = 0;  // 分配的块数。

// 用户定义的运算符 new。
void* operator new(size_t stAllocateBlock) {
    static int fInOpNew = 0;   // 护旗。

    if (fLogMemory && !fInOpNew) {
        fInOpNew = 1;
        clog << "Memory block " << ++cBlocksAllocated
            << " allocated for " << stAllocateBlock
            << " bytes\n";
        fInOpNew = 0;
    }
    return malloc(stAllocateBlock);
}

// 用户定义的运算符删除。
void operator delete(void* pvMem) {
    static int fInOpDelete = 0;   // 护旗。
    if (fLogMemory && !fInOpDelete) {
        fInOpDelete = 1;
        clog << "Memory block " << cBlocksAllocated--
            << " deallocated\n";
        fInOpDelete = 0;
    }

    free(pvMem);
}

int main030201(int argc, char* argv[]) {
    fLogMemory = 1;   // 开启登录
    if (2 > 1)
        for (int i = 0; i < 1; ++i) {
            char* pMem = new char[10];
            delete[] pMem;
        }
  

    fLogMemory = 0;  // 关闭注销。
    return cBlocksAllocated;
}
/*上述代码可用于检测"内存泄漏"，即，在可用存储上分配但从未释放的内存。 为了检测泄漏，对全局 和 运算符 newdelete 进行重新定义，以计算内存的分配和释放。

编译器支持类声明中的成员 newdelete 数组和运算符。 例如：*/


// spec1_the_operator_delete_function2.cpp
// compile with: /c
class X {
public:
    void* operator new[](size_t) {
        return 0;
    }
        void operator delete[](void*) {}
};

void f() {
    X* pX = new X[5];
    delete[] pX;
}