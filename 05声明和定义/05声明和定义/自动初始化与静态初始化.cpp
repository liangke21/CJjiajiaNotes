// initialization_of_objects.cpp
// compile with: /EHsc
#include <iostream>
#include <string.h>
using namespace std;

// 定义一个记录初始化和销毁​​的类。
class InitDemo {
public:
    InitDemo(const char* szWhat);
    ~InitDemo();

private:
    char* szObjName;
    size_t sizeofObjName;
};

// 类 Init Demo 的构造函数
InitDemo::InitDemo(const char* szWhat) :
    szObjName(NULL), sizeofObjName(0) {   //初始化
    if (szWhat != 0 && strlen(szWhat) > 0) {  //strlen 字符的长度
        // 为 sz Obj Name 分配存储空间，然后复制
        // 初始化器 sz 将什么转化为 sz 对象名称，使用
        // 保护 CRT 功能。
        sizeofObjName = strlen(szWhat) +1;  //获取字符占用长度

        //cout << "sizeofObjName: " << sizeofObjName << "\n";

        szObjName = new char[sizeofObjName];  // new一个 char 数组

        strcpy_s(szObjName, sizeofObjName, szWhat);//复制字符串

        cout << "Initializing: " << szObjName << "\n";
    }
    else {
        szObjName = 0;
    }
}

// Init Demo 的析构函数
InitDemo::~InitDemo() {
    if (szObjName != 0) {
        cout << "Destroying: " << szObjName << "\n";
        delete szObjName;
    }
}
//static InitDemo I3("Static I4");
//进入主函数
int main34() {
    InitDemo I1("Auto I1"); {
        cout << "In block.\n";
        InitDemo I2("Auto I2");
        static InitDemo I3("Static I3");
    }
    cout << "Exited block.\n";

    return 0;
}