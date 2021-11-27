

/*


��ע
protected �ؼ���ָ���Գ�Ա�б��е����Ա�ķ��ʣ�ֱ����һ������˵�� (��) �� public private �ඨ���ĩβ�� ����Ϊ �� protected ���Աֻ����������ʹ�ã�

���������Щ��Ա����ĳ�Ա������

���������Щ��Ա�������Ԫ��

ʹ�ù������ܱ������ʣ����������������Щ��Ա���ࣩ�������ࡣ

Ҳ���ܱ�����Ա����ר�÷���Ȩ�޵���˽�з�ʽ������ֱ���ࡣ

�ڻ��������ǰ�棬 �ؼ���ָ������Ĺ�����Ա���ܱ�����Ա�� protected ��������ܱ�����Ա��

�ܱ����ĳ�Ա�����Աһ��˽�У�ֻ�������ܱ����ĳ�Ա����ĳ�Ա���Է�����Щ��Ա�������ǲ���Ϊ��Ա��������Щ��Ա�����κκ��� private public �з��ʡ�

������Ϊ ���ܱ�����Ա�ɹ���������κ� static ��Ԫ���Ա�������ʡ� δ����Ϊ ���ܱ�����Ա����ͨ��ָ���������ָ�롢������������û�����������������е���Ԫ�ͳ�Ա static ������

�й������Ϣ������Ŀ��ƶ����Ա�ķ����е���Ԫ��������˽�кͳ�Ա���ʱ�

*/


// keyword_protected.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class X {
public:
    void setProtMemb(int i) { m_protMemb = i; }
    void Display() { cout << m_protMemb << endl; }
protected:
    int  m_protMemb;
    void Protfunc() { cout << "\nAccess allowed\n"; }
} x;

class Y : public X {
public:
    void useProtfunc() { Protfunc(); }
} y;

int main050401() {
    // x.m_protMemb;         ����m prot ��Ա�ܵ�����
    x.setProtMemb(0);   // OK��ʹ�ù������ʹ���
    x.Display();
    y.setProtMemb(5);   // OK, ʹ�ù������ʹ���
    y.Display();
    // x.Protfunc();         ����Protfunc() ������
    y.useProtfunc();    // OK,ʹ�ù������ʹ���         //Access allowed
                         // ����������
    return 0;
}