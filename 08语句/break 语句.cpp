#include <iostream>
using namespace std;

int main08011()
{
    //标准 for 循环示例
    for (int i = 1; i < 10; i++)
    {
        if (i == 4) {
            break;  //跳出
        }
        cout << i << '\n';
    }

    // 基于范围的 for 循环示例
    int nums[]{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for (int i : nums) {
        if (i == 4) {
            break; //跳出
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
   
        // 假设为手设置了一些枚举值
        // 在这个例子中，每个案例都是单独处理的
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
    // 在这个例子中，菱形和心形以一种方式处理，并且
    // 梅花、黑桃和默认值以另一种方式处理
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