

/*
������һ����ķ�Χ��������һ���ࡣ ���������Ϊ��Ƕ���ࡱ��
Ƕ���౻��Ϊ�ڷ����ķ�Χ���ҿ��ڸ÷�Χ��ʹ�á�
��Ҫ��Ƕ����ļ�ʱ��շ�Χ֮���ĳ����Χ���ø��࣬�����ʹ����ȫ�޶�����
*/


class BufferedIO
{
public:
    enum IOError { None, Access, General };

    //����Ƕ���໺�����롣
    class BufferedInput
    {
    public:
        int read();
        int good()
        {
            return _inputerror == None;
        }
    private:
        IOError _inputerror;
    };

    // ����Ƕ���໺�������
    class BufferedOutput
    {
        // ��Ա����
    };
};

int main1701()
{

    return 0;
}


class C
{
public:
    typedef class U u_t; // U ���� C �෶Χ֮��ɼ�
    typedef class V {} v_t; // V ���� C ���ⲻ�ɼ�
};

int main1703()
{
    // �õģ�����ʹ����ǰ�����������ʹ�����ļ���Χ
    U* pu;

    // ������������ֻ������ C ����������
  //  u_t* pu2; // C2065

    // �������涨����������� C ��Χ
   // V* pv; // C2065

    // �õģ���ȫ�޶�����
    C::V* pv2;

    return 0;
}
/*
 ��ע

Ƕ��������෶Χ���������͡� ���ǲ��ᵼ�´���Ƕ����İ������� ǰ���ʾ����������Ƕ���࣬��δ������Щ�����͵��κζ���
*/