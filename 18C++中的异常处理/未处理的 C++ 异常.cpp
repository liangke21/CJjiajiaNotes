





/*
�����ǰ�쳣 (��ʡ�ԺŴ������) �������Ԥ����� catchterminate ����ʱ������ (���������κ� terminate handlers.) ����ʽ���� ��Ĭ�ϲ��� terminate �ǵ��� abort �� �����ϣ�� terminate ���˳�Ӧ�ó���֮ǰ���ó����е�ĳЩ�������������ñ����ú�����������Ϊ�䵥���Ա������� set_terminate ������ �������ڳ�����κε���� set_terminate�� ���� terminate ʼ�յ������һ����Ϊ �Ĳ��������ĺ��� set_terminate ��
*/


#include <iostream>
using namespace std;
void term_func() {
    cout << "term func ����ֹ����." << endl;
    exit(-1);
}
int main180901() {
    try
    {
        set_terminate(term_func); //����ִ���������, û�д�����쳣������������

        term_func();
        set_terminate(term_func);
        throw "Out of memory!"; // ���쳣û�в��������
    }
    catch (int)
    {
        cout << "���������쳣." << endl;
    }
    return 0;
}