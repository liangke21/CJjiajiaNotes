//���� :: ��������ռ�

#include <iostream>
namespace NamespaceA {
    int x;
    class ClassA {
    public:
        int x;
    };
}

int main291() {

    // ������������������ռ�����
    NamespaceA::x = 1;

    //�����������������
    NamespaceA::ClassA a1;
    a1.x = 2;

    return 0;
}
//û�з�Χ�޶����ķ�Χ�����������ʾȫ�������ռ䡣
namespace NamespaceB {
    int x;
}

int x;

int main292() {
    int x;

    // main() �е� x
    x = 0;
    // ȫ�������ռ��е� x
    ::x = 1;

    // A �����ռ��е� x
    NamespaceB::x = 2;

    return 0;
}
/*
����ʹ�÷�Χ�����������ʶ�ĳ�Ա namespace ��
���ʶ��ָ���� nominates ��Ա�������ռ�������ռ� using �� 
�������ʾ���У������ʹ�� NamespaceC ���޶� ClassB ��
��ʹ ClassB ���������ռ��������ģ� 
NamespaceB ��Ϊ NamespaceB �� NamespaceC ��ָ������������ using ��
*/
namespace NamespaceD {
 
    class ClassB {
    public:
        int x;
    };
}

namespace NamespaceC {
    using namespace NamespaceD;
}

int main293() {
    NamespaceD::ClassB b_b;
    NamespaceC::ClassB c_b;

    b_b.x = 3;
    c_b.x = 4;
    return 0;
}
/*
��ʹ�÷�Χ������������� 
������ʾ���У�NamespaceD::NamespaceD1 ����ʶǶ�׵������ռ� NamespaceD1��
���� NamespaceE::ClassE::ClassE1 ����ʶǶ�׵��� ClassE1��
*/
namespace NamespaceD {
    namespace NamespaceD1 {
        int x;
    }
}

namespace NamespaceE {
    class ClassE {
    public:
        class ClassE1 {
        public:
            int x;
        };
    };
}

int main294() {
    NamespaceD::NamespaceD1::x = 6;
    NamespaceE::ClassE::ClassE1 e1;
    e1.x = 7;
    return 0;
}
