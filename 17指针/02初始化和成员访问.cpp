#include <iostream>
#include <string>

class MyClass
{
public:
    int num;
    std::string name;
    void print() { std::cout << name << ":" << num << std::endl; }
};

// ����һ�� My Class ָ��
void func_A(MyClass* mc)
{
// �޸� mc ָ��Ķ���
    // ָ������и�������ָ��
    // ��ͬ���޸Ķ���
    mc->num = 3;
}

// Accepts a MyClass object
void func_B(MyClass mc)
{
// ����� mc ��һ����ͨ���󣬶�����һ��ָ�롣
    // ʹ�� ����������Ա���ʳ�Ա��
    // �����ֻ�޸� mc �ı��ظ�����
    mc.num = 21;
    std::cout << "Local copy of mc:";
    mc.print(); // "Erika, 21"
}


int main0201()
{
// ʹ�� * ���������ָ������
    // ʹ��new������ͳ�ʼ���ڴ�
    MyClass* pmc = new MyClass{ 108, "Nick" };

// ��ӡ�ڴ��ַ��ͨ����������Ҫ�ġ�
    std::cout << pmc << std::endl;

// ͨ��������ָ�븴��ָ��Ķ���
    // �����ڴ�λ�õ����ݡ�
    // mc ��һ�������Ķ������������ջ��
    MyClass mc = *pmc;

// ʹ�� addressof ����������һ��ָ�� mc ��ָ��
    MyClass* pcopy = &mc;
    std::cout << &pcopy << std::endl;
// ʹ��-&gt; ���������ʶ���Ĺ�����Ա
    pmc->print(); // "Nick, 108"
// ����ָ�롣���� pmc �� pmc2 ָ��ͬһ������
    MyClass* pmc2 = pmc;

// ʹ�ø��Ƶ�ָ���޸�ԭʼ����
    pmc2->name = "Erika";
    pmc->print(); // "Erika, 108"
    pmc2->print(); // "Erika, 108"

// ��ָ�봫�ݸ�������
    func_A(pmc);
    pmc->print(); // "Erika, 3"
    pmc2->print(); // "Erika, 3"

// ȡ������ָ�벢����һ������
    // ָ�����Ķ���
    func_B(*pmc);
    pmc->print(); // ��Erika, 3����ԭ��δ�������޸ģ�

    delete(pmc); // ��Ҫ���ǽ��ڴ滹������ϵͳ��
   // ɾ����pmc2���� //��ײ���ڴ�λ���ѱ�ɾ��

    return 0;
}