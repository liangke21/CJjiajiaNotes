/*lambda ���ʽ�Ĳ����Ӿ䲻�ܰ��������й����͵ı����� 
���ǣ�����Խ������й����͵�ʵ�ʲ������ݵ� lambda ���ʽ����ʽ�����б� 
����ʾ������һ�� lambda ���ʽ����ͨ��ֵ����ֲ����йܱ��� ch�������� System.String ������Ϊ�������*/
//using namespace System;
//
//int main()
//{
//    char ch = '!'; // a local unmanaged variable
//
//    // The following lambda expression captures local variables
//    // by value and takes a managed String object as its parameter.
//    [=](String^ s) {
//        Console::WriteLine(s + Convert::ToChar(ch));
//    }("Hello");
//}