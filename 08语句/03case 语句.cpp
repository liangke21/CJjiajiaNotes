#include <iostream>
using namespace std;



int main3()
{
    int msg = 3;

    const  int WM_TIMER = 1;
    const  int WM_PAINT = 2;
   

    // �ؼ��ֺ���ʾ case �ı�ǩҲ������ʾ�� ��� switch �ⲿ�� (������Ҳ������ keyword.) ���´���Ƭ����ʾ�� default ��ǩ����ȷ case ʹ�ã�
 switch (msg)
    {
    case WM_TIMER:    // ����ʱ���¼���
        cout << "����1" << endl;
        break;

    case WM_PAINT:
        cout << "����2" << endl;
        break;

    default:
        // ��ѡ�����������з��ض���Ϣ
        //  �������������ǡ�
        cout << "����Ĭ��" << endl;
        return  3;
        break;
    }

    return 0;
}