
/*
���ܾ���ȫ�ַ�Χ�ĺ�����������ԭ��֮ǰ����Ϊ��Ԫ���������ǳ�Ա���������ǵ���������������ǰ��������Ϊ��Ԫ������ ���´�����ʾ��ʧ�ܵ�ԭ��
*/

class ForwardDeclared;   // Class name is known.
class HasFriends
{
  //  friend int ForwardDeclared::IsAFriend();   // C2039 error expected
};
//ǰ���ʾ�������� ForwardDeclared ���뵽��Χ�У�����������������������ԣ��������� IsAFriend �Ĳ��֣���δ֪�ġ� ��ˣ� friend ���е������� HasFriends ���ɴ���


//friend class F;
//friend F;

/*
��������ڲ�������ռ����Ҳ��������Ƶ������࣬���һ����ʽ�������µ��� F�� C + + 11���ڶ�����ʽ����������;���Ѿ�������ʱ������ʹ�����������ڽ�ģ�����Ͳ����� typedef ����Ϊ��Ԫʱ����ʹ������

friend class F����δ�������õ�����ʱʹ�ã�
*/

namespace NS
{
    class M
    {
        friend class F;  //���� F ��û�ж�����
    };
}

namespace NSs
{
    class M
    {
       // friend F; // error C2433: 'NS::F': 'friend' not permitted on data declarations
    };
}

//�������ʾ���У� friend F ������ F NS ��Χ֮���������ࡣ
class F {};
namespace NSa
{
    class M
    {
        friend F;  // OK
    };
}

// ʹ�� friend F ��ģ���������Ϊ friend��
template <typename T>
class my_class
{
    friend T;
    //...
};
//ʹ�� friend F �� typedef ����Ϊ friend��
class Foo {};
typedef Foo Fa;

class G
{
    friend Fa; // OK
    //friend class Fa // Error C2371 --���¶���
};

int main050201() {
    return 0;
}