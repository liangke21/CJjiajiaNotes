


#include <iostream>
using namespace std;

struct PERSON {   //���� PERSON �ṹ������
    int age;   // ������Ա����
    long ss;
    float weight;
    char name[25];
} family_member;   //���� PERSON ���͵Ķ���

struct CELL {   // ���� CELL λ��
    unsigned short character : 8;  // 00000000 ????????
    unsigned short foreground : 3;  // 00000??? 00000000
    unsigned short intensity : 1;  // 0000?000 00000000
    unsigned short background : 3;  // 0???0000 00000000
    unsigned short blink : 1;  // ?0000000 00000000
} screen[25][80];       // λ������

int main0301() {
    struct PERSON sister;   // C���ṹ����
    PERSON brother;   // C++ ���Ľṹ����
    sister.age = 13;   // Ϊ��Ա��ֵ
    brother.age = 7;
    cout << "sister.age = " << sister.age << '\n';//13
    cout << "brother.age = " << brother.age << '\n';//7

    CELL my_cell;
    my_cell.character =200;
    cout << "my_cell.character = " << my_cell.character;


    return 0;

    //ע��λ������һ�ֽ�����

}
