#include <iostream>
using namespace std;

int main08011()
{
    //��׼ for ѭ��ʾ��
    for (int i = 1; i < 10; i++)
    {
        if (i == 4) {
            break;  //����
        }
        cout << i << '\n';
    }

    // ���ڷ�Χ�� for ѭ��ʾ��
    int nums[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i : nums) {
        if (i == 4) {
            break; //����
        }
        cout << i << '\n';
    }

    return 0;
}

#include <iostream>
using namespace std;

int main08012() {
    int i = 0;

    while (i < 10) {
        if (i == 4) {
            break;
        }
        cout << i << '\n';
        i++;
    }

    i = 0;
    do {
        if (i == 4) {
            break;
        }
        cout << i << '\n';
        i++;
    } while (i < 10);

    return 0;
}

#include <iostream>
using namespace std;

enum Suit { Diamonds, Hearts, Clubs, Spades };

int main08013() {

    Suit hand = Spades;
   
        // ����Ϊ��������һЩö��ֵ
        // ����������У�ÿ���������ǵ��������
        switch (hand)
        {
        case Diamonds:
            cout << "got Diamonds \n";
            break;
        case Hearts:
            cout << "got Hearts \n";
            break;
        case Clubs:
            cout << "got Clubs \n";
            break;
        case Spades:
            cout << "got Spades \n";
            break;
        default:
            cout << "didn't get card \n";
        }
    // ����������У����κ�������һ�ַ�ʽ��������
    // ÷�������Һ�Ĭ��ֵ����һ�ַ�ʽ����
    switch (hand)
    {
    case Diamonds:
    case Hearts:
        cout << "got a red card \n";
        break;
    case Clubs:
    case Spades:
    default:
        cout << "didn't get a red card \n";
    }

    return 3;
}