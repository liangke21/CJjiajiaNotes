


#include <iostream>
using namespace std;

struct PERSON {   //声明 PERSON 结构体类型
    int age;   // 声明成员类型
    long ss;
    float weight;
    char name[25];
} family_member;   //定义 PERSON 类型的对象

struct CELL {   // 声明 CELL 位域
    unsigned short character : 8;  // 00000000 ????????
    unsigned short foreground : 3;  // 00000??? 00000000
    unsigned short intensity : 1;  // 0000?000 00000000
    unsigned short background : 3;  // 0???0000 00000000
    unsigned short blink : 1;  // ?0000000 00000000
} screen[25][80];       // 位域数组

int main0301() {
    struct PERSON sister;   // C风格结构声明
    PERSON brother;   // C++ 风格的结构声明
    sister.age = 13;   // 为成员赋值
    brother.age = 7;
    cout << "sister.age = " << sister.age << '\n';//13
    cout << "brother.age = " << brother.age << '\n';//7

    CELL my_cell;
    my_cell.character =200;
    cout << "my_cell.character = " << my_cell.character;


    return 0;

    //注意位域是在一字节里面

}
