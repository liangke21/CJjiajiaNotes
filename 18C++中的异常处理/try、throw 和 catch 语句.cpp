
/*
���ȣ�ʹ�� try �齫һ���������������쳣�������������

throw���ʽ�����źű�ʾ�쳣�����ͨ���Ǵ������ڿ��з��� try ��
������ʹ���κ����͵Ķ�����Ϊ���ʽ�Ĳ����� throw ��
�ö���һ�����ڴ����йش������Ϣ�� �ڴ��������£�
���ǽ���ʹ�� std���� exception ����ڱ�׼���ж����һ�������ࡣ
������ʺ������������ǽ������������Լ����쳣�� std::exception ��

��Ҫ��������������쳣�����ڿ��������ʵ��һ������ catch �� try ��
ÿ�� catch ��ָ�������Դ�����쳣�����͡�

��ʾ����ʾ��һ�� try �鼰�䴦����� 
���� GetNetworkResource() ͨ���������ӻ�ȡ���ݣ�
���������쳣�����Ǵ� std::exception �������û�������ࡣ 
��ע�⣬�쳣��ͨ�� const ����е����ò���� catch ��
���ǽ�����ͨ��ֵ�����쳣��ͨ���������ý��䲶��

*/
//MyData md;
//try {
//    // ���������쳣�Ĵ���
//    md = GetNetworkResource();
//}
//catch (const networkIOException& e) {
//// �����쳣ʱִ�еĴ���
//    // �� try �����׳����� IOException
//    // ...
//    // ���쳣�����м�¼������Ϣ
//    cerr << e.what();
//}
//catch (const myDataFormatException& e) {
//    // ������һ���쳣���͵Ĵ���
//    // ...
//    cerr << e.what();
//}
//
//// �����﷨��ʾ��һ�� throw ���ʽ
//MyData GetNetworkResource()
//{
//    // ...
//    if (IOSuccess == false)
//        throw networkIOException("Unable to connect");
//    // ...
//    if (readError)
//        throw myDataFormatException("Format error");
//    // ...
//}