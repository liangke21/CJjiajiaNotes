class Point
{
public:
    Point(int, int);// �����������캯����
        Point();// ��������Ĭ�Ϲ��캯����
    int& x(int); // ����������������
    int& y(int); // ����������������

private:                 // ����˽��״̬������
    int _x;
    int _y;

protected:      // ��Ϊ�����������ܱ����ĺ�����
    Point ToWindowCoords();
};

/*

Ĭ�Ϸ���λ�� private ���У��� public �ṹ�������С� ���еķ���˵�����ɰ��κ�˳��ʹ����������� �����͵Ķ���Ĵ洢������ȡ����ʵ�ֵģ�����Աһ���ܷ��䵽����˵����֮����������ߵ��ڴ��ַ��

��Ա���ʿ���
��Ա���ʿ���
��������	����
private	����Ϊ �����Աֻ���ɳ�Ա��������Ԫ (private �����) ����Ԫʹ�á�
protected	����Ϊ �����Ա�����ɳ�Ա��������Ԫ (protected ���) �����ʹ�á� ���⣬���ǻ����������Ը������ʹ�á�
public	����Ϊ �� public ���Ա�������κκ�����
���ʿ�����������ֹ��ͨ�����ʵ��ķ�ʽʹ�ö��� ��ִ����ʽ����ת����ǿ��ת����ʱ���˱�������ʧ��

 ��ע

���ʿ���ͬ���������������ƣ���Ա��������Ա���ݡ�Ƕ�����ö������
*/


/*
https://docs.microsoft.com/zh-cn/cpp/cpp/member-access-control-cpp?view=msvc-170#member-access-in-base-class
�����еĳ�Ա����
�����еĳ�Ա����
private	   protected	����
������������Ȩ����Σ�ʼ�ղ��ɷ���	���ʹ��˽��������������������Ϊ˽��	���ʹ��˽��������������������Ϊ˽��
���ʹ���ܱ���������������������Ϊ�ܱ���	���ʹ���ܱ���������������������Ϊ�ܱ���
���ʹ�ù���������������������Ϊ�ܱ���	���ʹ�ù���������������������Ϊ����
����ʾ���Դ˽�����˵����
*/


// access_specifiers_for_base_classes.cpp
class BaseClass
{
public:
    int PublicFunc(); // ����һ��������Ա.
protected:
    int ProtectedFunc(); // ����һ���ܱ����ĳ�Ա��
private:
    int PrivateFunc(); // ����һ��˽�г�Ա��
};

// �������������� Base Class ���ࡣ
class DerivedClass1 : public BaseClass
{
    void foo()
    {
        PublicFunc();
        ProtectedFunc();
       // PrivateFunc(); // �����޷�����
    }
};

class DerivedClass2 : private BaseClass
{
    void foo()
    {
        PublicFunc();
        ProtectedFunc();
       // PrivateFunc(); // �����޷�����
    }
};

int main050101()
{
   // DerivedClass1 derived_class1;
  //  DerivedClass2 derived_class2;
   // derived_class1.PublicFunc();
   // derived_class2.PublicFunc(); // �����޷�����  ֻ�����������з���//

    return 0;
}