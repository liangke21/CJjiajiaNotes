


// static_cast_Operator.cpp
// compile with: /LD
class B {};
//�������ʾ���У���Ϊ D* pd2 = static_cast<D*>(pb); 
//�����в��� D �ڵ��ֶκͷ����������� B ����ȫ�� 
//���ǣ���Ϊ B* pb2 = static_cast<B*>(pd); ʼ�հ������� D�������� B �ǰ�ȫ��ת����
class D : public B {};

void f(B* pb, D* pd) {
    //��Ϊ D* pd2 = static_cast<D*>(pb); �����в��� D �ڵ��ֶκͷ����������� B ����ȫ
    D* pd2 = static_cast<D*>(pb);   // ����ȫ��D �������ֶ�
                                    // �Ͳ��� B �еķ�����

    B* pb2 = static_cast<B*>(pd);   // ��ȫת����D ʼ��
                                    // �������� B.
}

int main0401031()
{

    return 0;
}

// ����������ڽ�ָ������ָ��ת��Ϊָ���������ָ�� static_cast �Ȳ����� ����ת������ʼ�հ�ȫ��

class B1 {
public:
    virtual void Test() {}
};
class D1 : public B1 {

    virtual void Test();
};

void f(B1* pb) {

   // B* pb2 = new B;

 //   D* pd1 = dynamic_cast<D*>(pb);
    //���ﲻ�ǻ���
  //  D* pd2 = static_cast<D*>(pb);
}

int main0401032()
{

    int a = 5;

    return 0;
}


// dynamic_cast ����ת��
// 
class B2 { virtual void f(); };
class D2 : public B2 { virtual void f(); };

void f() {
  //  B* pb = new D;   // ����������� //δ����
 //   B* pb2 = new B; //δ����

  //  D* pd = dynamic_cast<D*>(pb);   // ok: pb ʵ����ָ��һ�� D
   // D* pd2 = dynamic_cast<D*>(pb2);   // pb2 ָ�� B ������ D
}