/*
ͨ�����غ�����������ֵ const ���û���ֵ���ã�
����Ա�д���������ֲ����޸ĵĶ��� (��ֵ) �Ϳ��޸ĵ���ʱֵ (��) ��
������󱻱��Ϊ������Խ����󴫵ݵ�������ֵ���õĺ��� const ��
����ʾ����ʾ�˺��� f���ú������������Բ�����ֵ���ú���ֵ���á�
main ����ͬʱʹ����ֵ����ֵ������ f��

*/



#include <iostream>
using namespace std;

// �����ڴ���Դ���ࡣ
class MemoryBlock
{
	// TODO: �ڴ˴�Ϊ�༶�����Դ��
};

void f(const MemoryBlock&)
{
	cout << "�� f(const Memory Block&amp;) �С�����汾�����޸Ĳ���." << endl;
}

void f(MemoryBlock&&)
{
	cout << "�� f���ڴ��&amp;&amp;���С�����汾�����޸Ĳ���." << endl;
}

int main030201()
{
	MemoryBlock block;
	f(block); //�����޸Ĳ���
	f(MemoryBlock());//�����޸Ĳ���

	return 0;
}




namespace aa {


#include <iostream>
using namespace std;

// �����ڴ���Դ���ࡣ
class MemoryBlock
{
	// TODO: �ڴ˴�Ϊ�༶�����Դ��
};

void g(const MemoryBlock&)
{
	cout << "�� g(const Memory Block&amp;) �С�" << endl;
}

void g(MemoryBlock&&)
{
	cout << "In g(MemoryBlock&&)." << endl;
}

MemoryBlock&& f(MemoryBlock&& block)
{
	g(block);
	return move(block);
}

}
int main030202()
{
	using namespace aa;

	aa::g(f(aa::MemoryBlock()));//In g(MemoryBlock&&).

	return 0;
}







// cast-reference.cpp
// Compile with: /EHsc
#include <iostream>
namespace bb {



// A class that contains a memory resource.
class MemoryBlock
{
	// TODO: Add resources for the class here.
};

void g(const MemoryBlock&)
{
	cout << "In g(const MemoryBlock&)." << endl;
}

void g(MemoryBlock&&)
{
	cout << "In g(MemoryBlock&&)." << endl;
}
}
int main0302()
{
	using namespace bb;

	bb::MemoryBlock block;
	g(block);//In g(const MemoryBlock&)
	g(static_cast<bb::MemoryBlock&&>(block));//In g(MemoryBlock&&).

	return 0;
}



