

#include <iostream>

int main030201()
{
	using namespace std;
	int n = [](int x, int y) { return x + y; }(5, 4);
	cout << n << endl;//9

	return 0;
}


#include <list>
#include <algorithm>
#include <iostream>

int main030202()
{
    using namespace std;

    // ����һ�����м�����ʼԪ�ص������б�
    list<int> numbers;
    numbers.push_back(13);
    numbers.push_back(17);
    numbers.push_back(42);
    numbers.push_back(46);
    numbers.push_back(99);

    // ʹ�� find if ������ lambda ���ʽ������
    // �б��еĵ�һ��ż����
    const list<int>::const_iterator result =
        find_if(numbers.begin(), numbers.end(), [](int n) { return (n % 2) == 0; });

    // ��ӡ���.
    if (result != numbers.end()) {
        cout << "�б��еĵ�һ��ż���� " << *result << "." << endl;
    }
    else {
        cout << "���б�����ż��." << endl;
    }

    return 0;
}
