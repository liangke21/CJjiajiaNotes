


// ����һ�����д������������ĳ�����ࡣ
// ������򵥵ĳ����ࡣ
class base
{
public:
    base() {}
    // �����ⶨ����������������
    virtual ~base() = 0;

//  virtual ~base() = 0 {};
};

base::~base() {} // �����ʹ�� Microsoft ��չ������Ҫ

class derived : public base
{
public:
    derived() {}
    ~derived() {}
};

int main1501()
{
    derived aDerived; // ������Χʱ������������
    return 0;
}
/*
 ��ע

��ǰ���ʾ���У����麯�� base::~base �Ǵ� derived::~derived ��ʽ���õġ� Ҳ��ʹ����ȫ�޶��ĳ�Ա����������ʽ���ô����⺯���� ���ຯ���������ʵ�֣�������ûᵼ������ʱ����
*/