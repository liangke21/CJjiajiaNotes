

/*
������������ģ�Ҳ����˵�������ڲ�ʹ�� ��ʶ�� ��������������ǡ� 
�������滻Ϊ����ʱ���������� typedef ��������ʾ��
*/

typedef struct
{
    unsigned x;
    unsigned y;
} POINT;

/*
 ��ע

����ʾ������ʾ����������÷����ڱ��������� C ����ļ����Ժ����á� ��ĳЩ C �����У��� typedef �������ṹ���ʹ�÷ǳ��ձ顣
*/

struct PTValue
{
    POINT ptLoc;
    union
    {
        int  iValue;
        long lValue;
    };
};

int main1801() {

    PTValue ptv;
    int i = ptv.iValue;

    return 0;
}