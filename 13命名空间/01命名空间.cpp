
/*�����ռ���һ������������Ϊ���ڲ��ı�ʶ�������͡������ͱ����ȵ����ƣ��ṩһ����Χ�� 
�����ռ����ڽ�������֯���߼����У��������ڱ������Ƴ�ͻ���������ڻ���������������ʱ�� 
�����ռ䷶Χ�ڵ����б�ʶ���˴˿ɼ�����û���κ����ơ� 
�����ռ�֮��ı�ʶ������ͨ����ÿ����ʶ��ʹ����ȫ�޶����������ʳ�Ա��
���� std::vector<std::string> vec; ����ͨ���Ե�����ʶ�� () ʹ�� ���� �� 
using std::string ��������ռ��е����б�ʶ��ʹ�� using ָ�� (using namespace std;) ��
ͷ�ļ��еĴ���Ӧʼ��ʹ����ȫ�޶��������ռ����ơ�

�����ʾ����ʾ��һ�������ռ������������ռ�֮��Ĵ���ɷ������Ա�����ַ�����*/

namespace ContosoData
{
    class ObjectManager
    {
    public:
        void DoSomething() {}
    };
    void Func(ObjectManager) {}
}
//ʹ����ȫ�޶�����
int main0101() {

    ContosoData::ObjectManager mgr;
    mgr.DoSomething();
    ContosoData::Func(mgr);
    return 0;
}
//ʹ�� using �������Խ�һ����ʶ�����뷶Χ��
int main0102() {

    using ContosoData::ObjectManager;
    ObjectManager mgr;
    mgr.DoSomething();
    return 0;

    return 0;
}
//ʹ�� using ָ��Խ������ռ��е������������뷶Χ��
int main0103() {

    using namespace ContosoData;

    ObjectManager mgr;
    mgr.DoSomething();
    Func(mgr);

    return 0;
}