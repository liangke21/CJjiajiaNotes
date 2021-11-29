
/*
ʹ�� override �����ڷ�ֹ�����г�������ļ̳���Ϊ�� 
�����ʾ����ʾ�ڲ�ʹ�� ��д ������£�������δ���������ĳ�Ա������Ϊ�� 
���������ᷢ���˴�����κδ���

*/


class BaseClass
{
    virtual void funcA();
    virtual void funcB() const;
    virtual void funcC(int = 0);
    void funcD();
};

class DerivedClass : public BaseClass
{
    virtual void funcA(); // �õģ���Ԥ�ڹ���

    virtual void funcB(); // DerivedClass::funcB() �Ƿǳ����ģ���������
                          // override BaseClass::funcB() const������һ���µĳ�Ա����

    virtual void funcC(double = 0.0); // DerivedClass::funcC(double) has a different
                                      // �������ͱ� Base Class::func C(int)������
                                      // Derived Class::func C(double) ��һ���µĳ�Ա����
};

//ʹ�� override ʱ�������������ɴ��󣬶�����������ʾ��ʽ�����µĳ�Ա������

class BaseClass2
{
    virtual void funcA();
   virtual void funcB() const;
    virtual void funcC(int = 0);
    void funcD();
};

class DerivedClass2 : public BaseClass2
{
    virtual void funcA() override; // ok

  //  virtual void funcB() override; // ����������������::func B() û��
                                   // ���ǻ���::func B() const

   // virtual void funcC(double = 0.0) override; // compiler error:
                                                 // DerivedClass::funcC(double) does not
                                                 // override BaseClass::funcC(int)

   // void funcD() override; // ����������������::func D() û��
                           // ���Ƿ��������::func D()

    //���� �����ԭ���ǻ���û�����⹹�캯��
};

int main1203() {

    return 0;
}