#include <string>



// TestRun.h

class TestRun
{
    // ��ʼ��Ա�б�

    //���е����߶����Է��ʵ���ӿڡ�
public:
    // ʹ�ñ��������ɵ�Ĭ�Ϲ��캯����
    TestRun() = default;
    // ��Ҫ���ɸ��ƹ��캯����
    TestRun(const TestRun&) = delete;
    TestRun(std::string name);
    void DoSomething();
    int Calculate(int a, double d);
    virtual ~TestRun();
    enum class State { Active, Suspended };

    // ���ɷ��ʴ���������ࡣ
protected:  //������Է���
    virtual void Initialize();
    virtual void Suspend();
    State GetState();

    // ���˿γ̿ɷ��ʡ�
private:
    // ʵ����Ա��Ĭ�ϻ����ų�ʼ����
    State _state{ State::Suspended };
    std::string _testName{ "" };
    int _index{ 0 };

    //�ǳ�����̬��Ա��
    static int _instances;
    // ������Ա������
};

// ���岢��ʼ����̬��Ա��
int TestRun::_instances{ 0 };

/*


��Ա�ɷ�����
�ڳ�Ա�б���������ĳ�Ա�� ��ĳ�Ա�б���Է�Ϊ�������� private �� protected �� public ʹ�ùؼ��ֳ�Ϊ����˵������ ð�� �� ������ѭ����˵������ ��Щ���ֲ���Ҫ�������ģ�Ҳ����˵����Щ�ؼ����е��κ�һ���������ڳ�Ա�б��ж�γ��֡� �ؼ���ָ�����г�Աֱ����һ������˵�������Ҵ����ŵķ��ʡ� �й���ϸ��Ϣ������� ��Ա���ʿ��� (c + +) ��

��̬��Ա
�ɽ����ݳ�Ա����Ϊ��̬�����ʾ������ж�����Ȩ��������ͬһ������ ��Ա������������Ϊ��̬������������£���ֻ�ܷ�����ľ�̬���ݳ�Ա (���Ҳ�) �� ָ�롣 �й���ϸ��Ϣ������� ��̬���ݳ�Ա��




*/