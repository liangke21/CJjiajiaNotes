

/*

����������������С����ʹ�ã��������˽�����ݳ�Ա�� ��Щ���л�˫��"������"��������Ҫ��;�Ƿ����йض����״̬��Ϣ�� 
�̺����Ժ������õĿ������С� �ϳ��ĺ��������ڵ��úͷ��������ϵ�ʱ�䰴�������٣����Ҵ��������л�����١�

Point����Զ������£�

*/


// when_to_use_inline_functions.cpp
class Point
{
public:
    // ���������������ܶ���Ϊ
    //  �ο����͡�
    unsigned& x();
    unsigned& y();
private:
    unsigned _x;
    unsigned _y;
};

inline unsigned& Point::x()
{
    return _x;
}
inline unsigned& Point::y()
{
    return _y;
}
int main070201()
{

    return 0;
}