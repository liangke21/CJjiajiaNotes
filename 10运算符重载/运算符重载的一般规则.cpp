


class Point
{
public:
    Point operator<(Point&);  // ����һ����Ա������
                                 //  overload.
    // �����ӷ��������
    friend Point operator+(Point&, int);
    friend Point operator+(int, Point&);
};

int main0201()
{

    return 0;
}


/*
ǰ��Ĵ���ʾ����С�����������Ϊ��Ա���������ǣ��ӷ������������Ϊ������Ԫ���ʵ�ȫ�ֺ�����
��ע�⣬����Ϊ����������ṩ���ʵ�֡� ����ǰ��ļӷ�����������ṩ����ʵ���Ա��ڽ����� ͬ��������ӵ����������ӵ��� Point �ȵ�Ҳ Point int Point ���ܻ�ʵ�֡�

*/