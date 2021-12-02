

/*函数 Add1Add2 和 在功能上是等效的，尽管它们不是以相同的方式调用的。 区别是 使用 Add1 双重间接，但使用对 Add2 指针的引用的便利性。*/


#include <iostream>
#include <string>

// C++ 标准库命名空间
using namespace std;

enum {
    sizeOfBuffer = 132
};

// 定义二叉树结构。
struct BTree {
    char* szText;
    BTree* Left;
    BTree* Right;
};

// 定义指向树根的指针。
BTree* btRoot = 0;

int Add1(BTree** Root, char* szToAdd);
int Add2(BTree*& Root, char* szToAdd);
void PrintTree(BTree* btRoot);

int main0601(int argc, char* argv[]) {
    // Usage message
    if (argc < 2) {
        cerr << "用法: " << argv[0] << " [1 | 2]" << "\n";
        cerr << "\n在哪里:\n";
        cerr << "1 使用双重间接\n";
        cerr << "2 使用对指针的引用.\n";
        cerr << "\n输入来自标准输入。使用 ^Z 终止输入。\n";
        return 1;
    }

    char* szBuf = new char[sizeOfBuffer];
    if (szBuf == NULL) {
        cerr << "内存不足！\n";
        return -1;
    }

// 从标准输入设备读取文本文件并
    // 构建一个二叉树。
    while (!cin.eof())
    {
        cin.get(szBuf, sizeOfBuffer, '\n');
        cin.get();

        if (strlen(szBuf)) {
            switch (*argv[1]) {
                //方法一：使用双间接寻址。
            case '1':
                Add1(&btRoot, szBuf);
                break;
                //方法 2：使用对指针的引用。
            case '2':
                Add2(btRoot, szBuf);
                break;
            default:
                cerr << "非法值 '"
                    << *argv[1]
                    << "' 为 add 方法提供。\n"
                    << "选择 1 或 2.\n";
                return -1;
            }
        }
    }
    // 显示排序后的列表。
    PrintTree(btRoot);
    return 0;
}

// Print Tree：按顺序显示二叉树。
void PrintTree(BTree* MybtRoot) {
// 递归遍历树的左分支。
    if (MybtRoot->Left)
        PrintTree(MybtRoot->Left);

// 打印当前节点。
    cout << MybtRoot->szText << "\n";

// 递归遍历树的右分支。
    if (MybtRoot->Right)
        PrintTree(MybtRoot->Right);
}
// Add1：向二叉树添加一个节点。
// 使用双重间接。
int Add1(BTree** Root, char* szToAdd) {
    if ((*Root) == 0) {
        (*Root) = new BTree;
        (*Root)->Left = 0;
        (*Root)->Right = 0;
        (*Root)->szText = new char[strlen(szToAdd) + 1];
        strcpy_s((*Root)->szText, (strlen(szToAdd) + 1), szToAdd);
        return 1;
    }
    else {
        if (strcmp((*Root)->szText, szToAdd) > 0)
            return Add1(&((*Root)->Left), szToAdd);
        else
            return Add1(&((*Root)->Right), szToAdd);
    }
}
// Add2：向二叉树添加一个节点。
// 使用对指针的引用
int Add2(BTree*& Root, char* szToAdd) {
    if (Root == 0) {
        Root = new BTree;
        Root->Left = 0;
        Root->Right = 0;
        Root->szText = new char[strlen(szToAdd) + 1];
        strcpy_s(Root->szText, (strlen(szToAdd) + 1), szToAdd);
        return 1;
    }
    else {
        if (strcmp(Root->szText, szToAdd) > 0)
            return Add2(Root->Left, szToAdd);
        else
            return Add2(Root->Right, szToAdd);
    }
}