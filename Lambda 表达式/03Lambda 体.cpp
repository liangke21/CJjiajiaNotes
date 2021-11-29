
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main0101()
{
	int m = 0;
	int n = 0;
	[&, n](int a) mutable { m = ++n + a; }(4);

	cout << m << endl << n << endl;

    return 0;
}

/*���ڱ��� n ��ͨ��ֵ����ģ�����ڵ��� lambda ���ʽ�󣬱�����ֵ�Ա��� 0 ���䡣 �� mutable �淶������ n lambda ���޸ġ�

*/

void fillVector2(vector<int>& v)
{
    //�ֲ���̬������
    static int nextValue = 1;

// ���������µ����е� lambda ���ʽ
    // ���ɺ����޸Ĳ�ʹ�ñ��ؾ�̬
    // ������һ��ֵ��
    generate(v.begin(), v.end(), [] { return nextValue++; });  //���ﴫ��Ĳ��� ���� lambda��ʾ���صĲ���
    //���棺�ⲻ���̰߳�ȫ�ģ�������˵��
}

/*
����Ĵ���ʾ��ʹ����һʾ���еĺ������������ʹ�� c + + ��׼���㷨�� lambda ���ʽ��ʾ�� generate_n ��
�� lambda ���ʽ�� vector �����Ԫ��ָ�ɸ�ǰ����Ԫ��֮�͡�
mutable ʹ�ùؼ��֣��Ա� lambda ���ʽ����������޸����ⲿ�����ĸ��� x �� y lambda ���ʽͨ��ֵ����ĸ�����
���� lambda ���ʽͨ��ֵ����ԭʼ���� x �� y��������ǵ�ֵ�� lambda ִ�к���Ϊ 1��


*/

// compile with: /W4 /EHsc
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename C> void print(const string& s, const C& c) {
    cout << s;

    for (const auto& e : c) {
        cout << e << " ";
    }

    cout << endl;
}

void fillVector(vector<int>& v)
{
    // �ֲ���̬������
    static int nextValue = 1;

   // ���������µ����е� lambda ���ʽ
    // ���ɺ����޸Ĳ�ʹ�ñ��ؾ�̬
    // ������һ��ֵ��
    generate(v.begin(), v.end(), [] { return nextValue++; });
    //���棺�ⲻ���̰߳�ȫ�ģ�������˵��
}

int main0102()
{
    // �����е�Ԫ������
    const int elementCount = 9;

    // ����һ��ʸ������ÿ��Ԫ�ض�����Ϊ 1��
    vector<int> v(elementCount, 1);

    // ��Щ��������������ǰ����Ԫ�ء�
    int x = 1;
    int y = 1;
    print("v ����  ", v);
    // �������е�ÿ��Ԫ������Ϊ
    // ǰ����Ԫ�ء�
    generate_n(v.begin() + 2,
        elementCount - 2,//7
        [=]() mutable throw() -> int { // lambda �ǵ���������  //2
        // ���ɵ�ǰֵ��
            int n = x + y;
            // ����ǰ����ֵ��
            x = y;  //1
            y = n;  //2
            return n;
        });
    print("���ú������ v generate_n() with lambda: ", v);

  // ��ӡ�ֲ����� x �� y��
    // x �� y ��ֵ�������ǵĳ�ʼֵ����Ϊ
    // �����ǰ�ֵ����ġ�
    cout << "x: " << x << " y: " << y << endl;

    // �����������������
    fillVector(v);
    print("��һ�ε��ú������ v fillVector(): ", v);
    // ����һ�����������������
    fillVector(v);
    print("�ڶ��ε��ú������ v fillVector(): ", v);

    return 0;
}