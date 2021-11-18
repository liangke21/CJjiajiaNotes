// using_exit_or_return1.cpp






#include <stdlib.h>
#include <stdio.h>
//return ��� main
int main61()
{
    exit(3);
  //  return 3;  ���Բ�д
}

//��̬���������
class ShowData {
public:
    // ���캯����һ���ļ���
    ShowData(const char* szDev) {
        errno_t err;    //�������� 
        err = fopen_s(&OutputDev, szDev, "w"); //���ļ�
		/* fopen_s ����
		��һ������ :ָ���ļ�ָ���ָ�룬�ļ�ָ�뽫����ָ���Ѵ��ļ���ָ�롣
		�ڶ������� :�ļ���
		���������� :�ַ���ָ��Ϊ mode �ļ�����ķ������ͣ�������ʾ
			mode	Access
        "r"	���Ա��ȡ�� ����ļ������ڻ��Ҳ��������ý� fopen_s ʧ�ܡ�
        "w"	������д��Ŀ��ļ��� ��������ļ����ڣ��������ݻᱻ���١�
        "a"	���ļ�ĩβ���Խ���д�루׷�ӣ�����������д�뵽�ļ�֮ǰ���Ƴ��ļ�ĩβ (EOF) ��ǡ� ����ļ������ڣ��򴴽��ļ���
        "r+"	���Ա��ȡ��д�롣 �ļ�������ڡ�
        "w +"	�����ڶ�ȡ��д��Ŀ��ļ��� ����ļ����ڣ��������ݻᱻ���١�
        "a+"	���Խ��ж�ȡ��׷�ӡ� ׷�Ӳ���������������д���ļ�֮ǰ�Ƴ� EOF ��ǡ� д����ɺ�EOF ��ǲ��ỹԭ�� ����ļ������ڣ��򴴽��ļ���
		*/
    }

    // ���������ر��ļ���
    ~ShowData() { fclose(OutputDev); }  //����
        /*  �ر��� (fclose) ��ر����д򿪵��� (_fcloseall) ��
         ���� :  �� (stream)
                ָ�� �ļ� �ṹ��ָ�롣
        */
    // Disp ����������豸����ʾһ���ַ�����
    void Disp(const char* szData) {
        fputs(szData, OutputDev);  //���ַ���д������

        /*
        ��һ������Ҫ������ַ���
        �ڶ������� :stream
        ָ�� �ṹ�� FILE ָ�롣
        */
    }
private:
    FILE* OutputDev;   //������� I/O ����
};

//  ����һ�� Show Data ���͵ľ�̬��������豸
//   ѡ����ǡ�CON��������׼����豸��
ShowData sd1 = "CON";

//  ������һ����ʾ�������͵ľ�̬�������
//   ������һ����Ϊ��HELLO.DAT�����ļ�
ShowData sd2 = "hello.dat";
/*
�ܽ� :
������ �������ȳ�ʼ���ľ��Ǿ�̬�����mai������,
�������ʾ���У����� sd1 sd2 ����֮ǰ��������ʼ����̬����� main ��
�˳���ʹ�������ֹ�� return ������ sd2 ���٣�Ȼ�������� sd1 �� ShowData ��������������ر�����Щ��̬����������ļ���
*/


int main62() {
    sd1.Disp("hello to default device\n");
    sd2.Disp("hello to file hello.dat\n");

    return 0;
}
//��һ�ֱ�д�˴���ķ�ʽΪ��ʹ�ÿ鷶Χ���� ShowData ���󣬲����������ǳ�����Χʱ�������٣�
//int main() {
//    ShowData sd1("CON"), sd2("hello.dat");
//
//    sd1.Disp("hello to default device\n");
//    sd2.Disp("hello to file hello.dat\n");
//}