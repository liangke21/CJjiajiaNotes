
#include<iostream>

using namespace std;

int main(int argc, char* argv[])

{

	char buff[256] = { 0 };sprintf(buff, "play %s", argv[1]);

	system(buff);//�򿪲���

	cout << "����������� argc : " << argc << endl;

	cout << "����������� argv : " << argv[1] << endl;
	return 0;
}
