class CanInit
{
public:
    long num{ 7 };       // OK in C++11
    int k = 9;          // OK in C++11
   // static int i = 9; // ���󣺱��붨��ͳ�ʼ��
                      //��������֮�⡣

    // �� num ��ʼ��Ϊ 7���� k ��ʼ��Ϊ 9
    CanInit() {}

// ���� num ��ԭʼ��ʼ��ֵ��
    CanInit(int val) : num(val) {}
};
int main0401()
{
    //����ڹ��캯���ж�һ����Ա������һ��ֵ�����ֵ����������ʱ���ڳ�ʼ���ó�Ա��ֵ��

    return 0;
}


class CanInit2
{
public:
    CanInit2() {} // ������Ϊ�¶���ʱ�� num ��ʼ��Ϊ 7
                 //  ���Գ�ʼ��������
    long     num{ 7 };
    static int i;
    static int j;
};

// At file scope:

// i ���ļ���Χ�ڶ��岢��ʼ��Ϊ 15��
// ��ʼ�������� Can Init �ķ�Χ�ڽ���������
int CanInit2::i = 15;

// ��ʼ�������Ҳ��ڷ�Χ��
// ����ʼ���Ķ���
int CanInit2::j = i;

//���� CanInit2 ��ǰ������� i ��ָ��������� i ���� CanInit2 �ĳ�Ա��