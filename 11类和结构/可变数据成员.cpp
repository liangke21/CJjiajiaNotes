



//�˹ؼ���ֻ��Ӧ������ķǾ�̬�ͷǳ������ݳ�Ա�� ������������ݳ�Ա����ӳ�Ա������ mutable �����ݳ�Ա��ֵ const �ǺϷ��ġ�
//���´��뽫�������������Ϊ ������Ϊ ����˼�ʹ �� const ��Ա������Ҳ���� m_accessCount mutable �޸� GetFlag GetFlag ��

class X
{
public:
    bool GetFlag() const
    {
        m_accessCount++;
        return m_flag;
    }
private:
    bool m_flag;
    mutable int m_accessCount;
};

int main1601()
{
    return 0;
}