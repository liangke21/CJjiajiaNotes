

//��Ƕ�����������ĳ�Ա���������ļ���Χ�ж��塣 ǰ���ʾ�������ѱ�д��


class BufferedIO
{
public:
    enum IOError { None, Access, General };
    class BufferedInput
    {
    public:
        int read(); // �������������Ա
        int good(); //  ���ܿ��ˣ�����
    private:
        IOError _inputerror;
    };

    class BufferedOutput
    {
        // ��Ա������
    };
};
// �����Ա����read and good in
//  �ļ���Χ��
int BufferedIO::BufferedInput::read()
{
    return(1);
}

int BufferedIO::BufferedInput::good()
{
    return _inputerror == None;
}
int main170201()
{
    return 0;
}