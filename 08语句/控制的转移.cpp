#include <iostream>
using namespace std;



// ��ȡ���룬ֱ������������ַ���
int main080501()
{
    char MyArray[5] = { '2','2','a','c' };
    int i = 0;
    while (1)
    {
        int total = 0;

        char ch = MyArray[i++];

        if (ch >= '0' && ch <= '9')
        {
           goto Label1;

           //  int i = ch - '0';   //���������ͻ������ⲿ��ͬ���Ƶı���
        Label1:
            total += i;   // C4700: ת�� i �Ĺ�ȥ��ʼ����  //while �ڿ鷶Χ����ʽ������ͬ����ͬ��i,�ⲿ��i��������
            cout << "total1 : " << total << endl;
        } // ��������� goto �����ҽ������ﱻ����
        else
            // Break ��佫����ת�Ƶ�ѭ���⣬
            //  �ƻ��ܺ�ͨ����
            cout << "total : " << total << endl;
            break;
    }

    return 0;
}