#include <string>

//Ĭ������£�����ͨ��ֵ���ݸ�����������ζ�ź������յ������ݵĶ���ĸ����� 
//���ڴ��Ͷ��󣬴����������ܳɱ��߰�������ʼ�ձ�Ҫ�� ��Ҫʹ���������ô��� (�ر�����ֵ) ������ ������������޶�����

void DoSomething(std::string& input);

//�������޸�ͨ�����ô��ݵĲ���ʱ�������޸�ԭʼ���󣬶����Ǳ��ظ�����
//��Ҫ��ֹ�����޸Ĵ�����������޶�����Ϊ const&��
void DoSomething2(const std::string& input);

//��Ҫ��ʽ����ͨ�� rvalue-reference �� lvalue-reference ���ݵĲ�����
//��ʹ�� �����ϵ� double-ampersand ��ָʾͨ�����ã�
void DoSomething3(const std::string&& input);

//ʹ�ò��������б��еĵ����ؼ��������ĺ����������κβ�����ֻҪ�ؼ����ǲ��������б�ĵ�һ���� void void Ψһ�ĳ�Ա��
//�б������� void λ�õ�����Ϊ �Ĳ������������ ���磺
// OK same as GetTickCount()
long GetTickCount(void);

