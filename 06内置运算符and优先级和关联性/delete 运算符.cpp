// expre_Using_delete.cpp
#include <iostream>
struct UDType
{
};

int main121()
{
	// ����һ���û�����Ķ���UDObject ��һ������
	// ������̵���ʹ�� double ����
	//  new operator.
	UDType* UDObject = new UDType;
	double* dObject = new double(3.14);
	std::cout << " ûɾ��֮ǰ : " << &dObject << std::endl;
	std::cout << " ûɾ��֮ǰ : " << dObject << std::endl;
	std::cout << " ûɾ��֮ǰ : " << *dObject << std::endl;
	// ɾ������������
	delete UDObject;
	delete dObject;
	std::cout << " ����ɾ��û�� : " << &dObject << std::endl; //����ָ�벻��ɾ��
	std::cout << " ����ɾ��û�� : " << dObject << std::endl;  // ����ֵ�ı���ָ�� ��ֵ����ɾ��
	//std::cout << " ����ɾ��û�� : " << *dObject << std::endl;
	// ����һ���û�����Ķ���
	// ʹ�� new ��Ӫ�̵�����̵ꡣ
	UDType(*UDArr)[7] = new UDType[5][7];
	// ʹ�������﷨ɾ���������顣
	delete[] UDArr;

	return 0;
}