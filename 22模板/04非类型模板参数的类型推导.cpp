

//ģ�������ģ������� �ڴ�ʾ���У�MyClass2 ��������ģ������� typename ���� T ��ģ����� Arr��

template<typename T, template<typename U, int I> class Arr>
class MyClass2
{
    T t; //OK
    Arr<T, 10> a;
   // U u; //�����㲻�ڷ�Χ��
};
//���� Arr ��������û�����ģ���˲���Ҫ���Ĳ������ơ� ��ʵ�ϣ����� Arr�� typename ������������Ǵ���� �� ���ڴ�ԭ�򣬿���ʡ�� Arr�����Ͳ������ƣ�������ʾ������ʾ��
template<typename T, template<typename, int> class Arr>
class MyClass3
{
    T t; //OK
    Arr<T, 10> a;
};

int main220104() {

    return 0;
}