



/*
ͨ��ʹ����ʽ�������Ͷ���ö�� (�����Χ) ��������ö������ʵ���Ͽ������벻�����κ��������͵���ʽת�������������͡� 
ͨ��ʹ�ô����ͣ������������û������ͣ����������������е���ʽת�����µ�ϸ΢����Ŀ����ԡ�



enum class byte : unsigned char { };


�������ǻ������͵ľ�ȷ��������˾�����ͬ�ĵ���Լ��������ζ�ſ��� Abi ��ʹ�ã�����������κ�������ʧ�� 
ʹ��ֱ���б��ʼ������ʼ�����͵ı���ʱ����Ҫǿ��ת���� �����ʾ����ʾ����ڲ�ͬ���������г�ʼ��û��ö������ö�٣�
*/

enum class byte : unsigned char { };

enum class E : int { };
E e1{ 0 };
E e2 = E{ 0 };

struct X
{
    E e{ 0 };
    X() : e{ 0 } { }
};

E* p = new E{ 0 };

void f(E e) {};

int main1()
{
    f(E{ 0 });
    byte i{ 42 };
    byte j = byte{ 42 };

    // unsigned char c = j; // C2440: 'initializing': cannot convert from 'byte' to 'unsigned char'
    return 0;
}