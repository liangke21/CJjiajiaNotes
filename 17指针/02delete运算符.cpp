


#include <iostream>
using namespace std;

int fLogMemory = 0;      // ִ����־��¼ (0=no; nonzero=yes)?
int cBlocksAllocated = 0;  // ����Ŀ�����

// �û����������� new��
void* operator new(size_t stAllocateBlock) {
    static int fInOpNew = 0;   // ���졣

    if (fLogMemory && !fInOpNew) {
        fInOpNew = 1;
        clog << "Memory block " << ++cBlocksAllocated
            << " allocated for " << stAllocateBlock
            << " bytes\n";
        fInOpNew = 0;
    }
    return malloc(stAllocateBlock);
}

// �û�����������ɾ����
void operator delete(void* pvMem) {
    static int fInOpDelete = 0;   // ���졣
    if (fLogMemory && !fInOpDelete) {
        fInOpDelete = 1;
        clog << "Memory block " << cBlocksAllocated--
            << " deallocated\n";
        fInOpDelete = 0;
    }

    free(pvMem);
}

int main030201(int argc, char* argv[]) {
    fLogMemory = 1;   // ������¼
    if (2 > 1)
        for (int i = 0; i < 1; ++i) {
            char* pMem = new char[10];
            delete[] pMem;
        }
  

    fLogMemory = 0;  // �ر�ע����
    return cBlocksAllocated;
}
/*������������ڼ��"�ڴ�й©"�������ڿ��ô洢�Ϸ��䵫��δ�ͷŵ��ڴ档 Ϊ�˼��й©����ȫ�� �� ����� newdelete �������¶��壬�Լ����ڴ�ķ�����ͷš�

������֧���������еĳ�Ա newdelete ������������ ���磺*/


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