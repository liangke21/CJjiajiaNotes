//�� module ��������ģ��ʵ���ļ��Ŀ�ͷ����ָ�����ļ���������������ģ�顣

//export module Module;
//
//export void MyFunc();

//�ڽӿ��ļ��У���Ҫ export ��Ϊ�����ӿڵ�һ���ֵ�����ʹ�����η���


// ModuleA.ixx

export module ModuleA;

namespace Bar22
{
	export int f();
	export double d();
	double internal_f(); // not exported
}