/*

����԰�����̬��Ա���ݺͳ�Ա������ �����ݳ�Ա����Ϊ ʱ��ֻ��Ϊ ������ж��� static ά��һ�����ݸ�����

��̬���ݳ�Ա���Ǹ����������͵Ķ����һ���֡� ��ˣ���̬���ݳ�Ա������������Ϊһ�����塣 ���෶Χ���������ݳ�Ա�������ļ���Χ��ִ�ж��塣 ��Щ��̬���Ա�����ⲿ���ӡ� ����ʾ���Դ˽�����˵����
*/
class BufferedOutput
{
public:
    // ���ش�����κζ���д����ֽ�����
    short BytesWritten()
    {
        return bytecount;
    }

    // ���ü�������
    static void ResetCount()
    {
        bytecount = 0;
    }

    // ��̬��Ա������
    static long bytecount;
};

// ���ļ���Χ�ڶ����ֽ�����
long BufferedOutput::bytecount;

int main1401()
{
    return 0;
}