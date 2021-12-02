/*
https://docs.microsoft.com/zh-cn/cpp/cpp/how-to-create-and-use-ccomptr-and-ccomqiptr-instances?view=msvc-170
��δ�����ʹ��CComPtr��CComQIPtr ʵ��
2021/12/01
��ҳ���а�����?
�ھ��� Windows ����У���ͨ����Ϊ COM ���󣨸�׼ȷ��˵�� COM ��������ʵ�֡� �ܶ� Windows ����ϵͳ�������Ϊ COM ������ʵ�֣���ˣ��ܶ��������������ʽ�ṩ�⡣ �й� COM �Ļ���֪ʶ����Ϣ������� Component Object Model (COM)��

��ʵ�����������ģ�� (COM) ����ʱ���뽫�ӿ�ָ��洢�� COM ����ָ���У����߽�ʹ�� AddRef �� Release ִ�����ü����� �����ʹ���˻ģ��� (ATL) �� Microsoft ������� (MFC)����ʹ�� CComPtr ����ָ�롣 ���û��ʹ�� ATL �� MFC����ʹ�� _com_ptr_t�� ����û�е�Ч�� std::unique_ptr�� COM����Ե��������ߺͶ�������ߵ������ʹ����Щ����ָ�롣 CComPtr �� ComQIPtr ��֧�־��� rvalue ���õ��ƶ�������

ʾ���� CComPtr
����ʾ����ʾ���ʹ�� CComPtr ʵ���� COM ���󲢻�ȡָ����ӿڵ�ָ�롣 ��ע�⣬ CComPtr::CoCreateInstance ��Ա�������ڴ��� COM ���󣬶�����ͬ���� Win32 ������
*/

