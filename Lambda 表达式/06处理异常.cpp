
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main0601()
{
    // ����һ������ 3 ��Ԫ�ص�������
    vector<int> elements(3);

    // ������һ����������ֵ��������
    vector<int> indices(3);
    indices[0] = 0;
    indices[1] = -1; // �ⲻ����Ч���±ꡣ���ᴥ���쳣��
    indices[2] = 2;

     // ʹ������ֵ�����е�ֵ
    // ���Ԫ���������������ʹ����һ��
    // try/catch ����������Ч�ķ���
    // Ԫ��������
    try
    {
        for_each(indices.begin(), indices.end(), [&](int index) {
            cout << index<<endl;
            elements.at(index) = index;
            });
    }
    catch (const out_of_range& e)
    {
        
        cerr << "Caught '" << e.what() << "'." << endl;
    };

    //��lambda����Ҳ�ǿ��Լ������쳣��
    return 0;
}