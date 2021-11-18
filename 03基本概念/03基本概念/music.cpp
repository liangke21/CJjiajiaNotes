
#include<iostream>

using namespace std;

int main(int argc, char* argv[])

{

	char buff[256] = { 0 };sprintf(buff, "play %s", argv[1]);

	system(buff);//打开播放

	cout << "输出参数个数 argc : " << argc << endl;

	cout << "输出参数参数 argv : " << argv[1] << endl;
	return 0;
}
