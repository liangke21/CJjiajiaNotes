#include <exception>
#include <iostream>
#include <iostream>
using namespace std;

/*

noexcept-expression��һ��noexcept-expression�����������ĺ�׺����ʾһ�����ͣ������˳��������κ��쳣����Щ���Ϳ������쳣����������ƥ�䡣 �� ���� ʱ��һԪ�������������������ͬ��� ָ�������˳�������Ǳ���쳣���� noexcept(constant_expression)constant_expressiontruenoexcept ��Ϊ�ա� Ҳ����˵���ú�����Զ���������쳣��Ҳ��Զ���������쳣�����������⴫���� �� ���� ʱ�� �������������������ͷź���) ֮��û���쳣�淶 (��ʾ�����˳�������Ǳ���쳣�����������͵ļ��� noexcept(constant_expression)constant_expressionfalse

ֻ�е��������õ����к�����ֱ�ӻ��ӣ�Ҳ�� �� ʱ���Ž����� noexcept ���Ϊ noexceptconst �� ��������һ�����ÿ������·�����Ƿ��п�������ð�ݵ������� noexcept �쳣�� ����쳣ȷʵ�˳����Ϊ �ĺ������ⲿ���������������� �������޷���֤�������κη�Χ�ڶ���� noexceptstd::terminate ���������� ʹ�� noexcept �����Ƕ�̬�쳣˵���� throw() �� ��̬ �쳣�淶����淶���� C++11 �������ã��� C++17 ����ɾ������ ���⣬���� �� throw() ���� noexcept(true) �� ����Ӧ���ڴӲ������쳣���ϴ������ö�ջ noexcept ���κκ����� ��������ʱ noexcept ����ʹ�������ܹ��ڶ����ͬ�������������ɸ���Ч�Ĵ��롣
*/

//noexcept(bool�������ʽ)
class name {
public:
	void func() { throw 1; }

	void func2() noexcept{}
	void func21() noexcept(true){}//����func ��Ч

	void func3() noexcept { func(); }
};

int main() {
	name a;
	try
	{
		a.func();
	}
	catch (...)
	{
		cout << "func�쳣" << endl;
	}


	try
	{
		a.func2();
	}
	catch (...) //����ִ���쳣 ��ֹ����
	{
		cout << "func2�쳣" << endl;
	}


	try
	{
		a.func3();
	}
	catch (...) //����ִ���쳣 ��ֹ����
	{
		cout << "func3�쳣" << endl;
	}





}