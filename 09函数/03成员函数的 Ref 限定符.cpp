















#include <iostream>
#include <vector>

using namespace std;


/*
ͨ�������޶��������Ը���ָ��Ķ��� this ����ֵ������ֵ�������س�Ա������ ����ѡ���ṩ�����ݵ�ָ�����Ȩ��ʱ������ʹ�ô˹��������ⲻ��Ҫ�ĸ��Ʋ����� ���磬������ C ���乹�캯���г�ʼ��ĳЩ���ݣ����ڳ�Ա�����з��ظ����ݵĸ��� get_data() �� �������Ϊ�Ķ��� C ��Ҫ���ٵ���ֵ�����������ѡ�� get_data() && ���أ�����ƶ����ݶ����Ǹ������ݡ�

*/

class C
{

public:
    C() {/*����ĳ�ʼ��*/ }
    vector<unsigned> get_data()&
    {
        cout << "lvalue\n";
        return _data;
    }
    vector<unsigned> get_data()&&
    {
        cout << "rvalue\n";
        return _data;
    }

private:
    vector<unsigned> _data;
};

int main010301()
{
    C c;
    auto v = c.get_data(); // ��һ�ݡ���ӡ����ֵ".
    auto v2 = C().get_data(); // �õ�ԭ������ӡ����ֵ��


    return 0;
}