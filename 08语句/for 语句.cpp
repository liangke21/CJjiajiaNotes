#include <iostream>
using namespace std;




int main070301()
{

	for (int a = 0;a <=10;a++) {
		cout << "���ɶ : " << a << endl;

	}

	for (int a = 0;a == 10;a++) { //���ʽ�������
		cout << "���ɶ : " << a << endl;

	}

	int i=0;
	for (i; i < 2; i++) {
		cout << i<<endl;
	}
	int a;
	for (a=0; a < 2; a++) {
		cout << a << endl;
	}

	return 0;
}

int main070302() {
	int i, j;
	for (i = 5, j = 10; i + j < 20; i++, j++) {
		cout << "i + j = " << (i + j) << '\n';
	}
	cout << endl << endl;
	int k;
	for (i = 1;i <=9;i++) {

		for (k = 1;k <= i;k++) {
			cout << k << "*" << i<< " = " << (i * k)<<" ";
		}
		cout << endl;
	}

	return 0;
}