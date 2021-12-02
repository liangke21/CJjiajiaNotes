

/*���� Add1Add2 �� �ڹ������ǵ�Ч�ģ��������ǲ�������ͬ�ķ�ʽ���õġ� ������ ʹ�� Add1 ˫�ؼ�ӣ���ʹ�ö� Add2 ָ������õı����ԡ�*/


#include <iostream>
#include <string>

// C++ ��׼�������ռ�
using namespace std;

enum {
    sizeOfBuffer = 132
};

// ����������ṹ��
struct BTree {
    char* szText;
    BTree* Left;
    BTree* Right;
};

// ����ָ��������ָ�롣
BTree* btRoot = 0;

int Add1(BTree** Root, char* szToAdd);
int Add2(BTree*& Root, char* szToAdd);
void PrintTree(BTree* btRoot);

int main0601(int argc, char* argv[]) {
    // Usage message
    if (argc < 2) {
        cerr << "�÷�: " << argv[0] << " [1 | 2]" << "\n";
        cerr << "\n������:\n";
        cerr << "1 ʹ��˫�ؼ��\n";
        cerr << "2 ʹ�ö�ָ�������.\n";
        cerr << "\n�������Ա�׼���롣ʹ�� ^Z ��ֹ���롣\n";
        return 1;
    }

    char* szBuf = new char[sizeOfBuffer];
    if (szBuf == NULL) {
        cerr << "�ڴ治�㣡\n";
        return -1;
    }

// �ӱ�׼�����豸��ȡ�ı��ļ���
    // ����һ����������
    while (!cin.eof())
    {
        cin.get(szBuf, sizeOfBuffer, '\n');
        cin.get();

        if (strlen(szBuf)) {
            switch (*argv[1]) {
                //����һ��ʹ��˫���Ѱַ��
            case '1':
                Add1(&btRoot, szBuf);
                break;
                //���� 2��ʹ�ö�ָ������á�
            case '2':
                Add2(btRoot, szBuf);
                break;
            default:
                cerr << "�Ƿ�ֵ '"
                    << *argv[1]
                    << "' Ϊ add �����ṩ��\n"
                    << "ѡ�� 1 �� 2.\n";
                return -1;
            }
        }
    }
    // ��ʾ�������б�
    PrintTree(btRoot);
    return 0;
}

// Print Tree����˳����ʾ��������
void PrintTree(BTree* MybtRoot) {
// �ݹ�����������֧��
    if (MybtRoot->Left)
        PrintTree(MybtRoot->Left);

// ��ӡ��ǰ�ڵ㡣
    cout << MybtRoot->szText << "\n";

// �ݹ���������ҷ�֧��
    if (MybtRoot->Right)
        PrintTree(MybtRoot->Right);
}
// Add1������������һ���ڵ㡣
// ʹ��˫�ؼ�ӡ�
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
// Add2������������һ���ڵ㡣
// ʹ�ö�ָ�������
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