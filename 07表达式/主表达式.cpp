
class Example
{
public:
    void Func();          //  * const this
    void Func() const;    //  const * const this
    void Func() volatile; //  volatile * const this
};

//�����ʽ��ʾ��������

//100// literal
//'c' // literal
//this // �ڳ�Ա�����У�ָ����ʵ����ָ��
//::func // ȫ�ֺ���
//::operator + // ȫ�����������
//::A::B // ȫ���޶�����
//(i + 1) // a parenthesized expression


//MyClass // ��ʶ��
//MyClass::f // һ���ϸ������
//operator = // �����������
//operator char* // ת���������������
//~MyClass // ������������
//A::B   // һ���ϸ������
//A<int> // ģ���ʶ