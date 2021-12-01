


#include <iostream>
using namespace std;

struct Person
{
    char* Name;
    short Age;
};

int main0201()
{
// 声明一个 Person 对象。
    Person myFriend;

// 声明对Person 对象的引用。
    Person& rFriend = myFriend;


    cout << &myFriend << endl << &rFriend;
// 设置Person 对象的字段。
    // 更新任一变量都会更改相同的对象。
 //   myFriend.Name = "Bill";
    rFriend.Age = 40;

// 将 Person 对象的字段打印到控制台。
    cout << rFriend.Name << " is " << myFriend.Age << endl;

    return 0;
}