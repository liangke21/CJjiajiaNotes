
//�﷨
//static_assert(constant - expression, string - literal);

//static_assert(constant - expression); // C++17 (Visual Studio 2017 and later)

/*
����
constant-expression
����ת��Ϊ����ֵ�����ͳ������ʽ�� ���������ʽΪ�� (false) ���� ��ʾ�ַ��� �ı�����������ʧ�ܲ����ִ��� ������ʽΪ���� (Ϊ true) �� static_assert ��������Ч��

string-literal
��� constant-expression ����Ϊ�㣬����ʾһ����Ϣ�� ��Ϣ�Ǳ������Ļ��ַ� �����ַ� �ַ���;�������� ���ֽڻ���ַ���

��ע
���� �� constant-expression ������ʾ��� ���ԡ� �������ָ���ڳ����ĳ���ض���Ӧ����������� �������Ϊ true�� static_assert ��������Ч�� �������Ϊ false������ʧ�ܣ����������� �ַ����ı� ��������ʾ��Ϣ������ʧ�ܲ����ִ��� �� Visual Studio 2017 �����߰汾�У�string-literal �����ǿ�ѡ�ġ�

���� static_assert �ڱ���ʱ����������ԡ� �෴�� ���Ժ�_assert_wassert ����������ʱ����������ԣ��������ռ��ʱ�������ʱ�ɱ��� static_assert�������ڵ���ģ���ر����ã���Ϊģ��������԰�����static_assert�С�

��������ʱ static_assert ������������������﷨���� ����������ʽ������������ģ�� ���� �������������������ò����� ���򣬱�������ʵ����ģ��ʱ���� constant-expression ������ ��ˣ�����������ʱ������������һ�η���һ�������Ϣ�����ڶ�ģ�����ʵ����ʱҲ����ˡ�

�����������ռ� static_assert �����鷶Χ��ʹ�� �ؼ��֡� (�ؼ����ڼ���������������ʹ�������ڳ��������������ƣ���Ϊ�������� static_assert �����ռ� scope.)

*/

//static_assert �����෶Χ

#include <type_traits>
#include <iosfwd>
namespace std {
    template <class CharT, class Traits = std::char_traits<CharT> >
    class basic_string {
        static_assert(std::is_pod<CharT>::value,
            "ģ����� Char T ��������ģ������ַ����е� POD ����");
        // ...
    };
}


struct NonPOD {
    NonPOD(const NonPOD&) {}
    virtual ~NonPOD() {}
};

int main()
{
    std::basic_string<char> bs;
}
//ʾ���� static_assert �ڿ鷶Χ��
//#include <sys/param.h> // ���� PAGESIZE
//class VMMClient {
//public:
//    struct VMPage { // ...
//    };
//    int check_pagesize() {
//        static_assert(sizeof(VMPage) == PAGESIZE,
//            "Struct VMPage must be the same size as a system virtual memory page.");
//        // ...
//    }
//    // ...
//};