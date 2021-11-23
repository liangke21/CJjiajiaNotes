#include <iostream>
using namespace std;



int main3()
{
    int msg = 3;

    const  int WM_TIMER = 1;
    const  int WM_PAINT = 2;
   

    // 关键字后显示 case 的标签也不能显示在 语句 switch 外部。 (此限制也适用于 keyword.) 以下代码片段显示了 default 标签的正确 case 使用：
 switch (msg)
    {
    case WM_TIMER:    // 处理定时器事件。
        cout << "我是1" << endl;
        break;

    case WM_PAINT:
        cout << "我是2" << endl;
        break;

    default:
        // 此选择适用于所有非特定消息
        //  案例陈述所涵盖。
        cout << "我是默认" << endl;
        return  3;
        break;
    }

    return 0;
}