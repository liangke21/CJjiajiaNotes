


template<class T, int i> class MyStack
{
    T* pStack;
    T StackBuffer[i];
    static const int cItems = i * sizeof(T);
public:
    MyStack(void);
    void push(const T item);
    T& pop(void);
};

template< class T, int i > MyStack< T, i >::MyStack(void)
{
};

template< class T, int i > void MyStack< T, i >::push(const T item)
{
};

template< class T, int i > T& MyStack< T, i >::pop(void)
{
};

class name {
public:
    int a = 10;
    int b = 20;

};

int main220301()
{
  auto  a=new MyStack<name, 30> ;

  return 0;
}

/*
��ע�⣬�����κ�ģ�����Ա����һ������Ĺ��캯����Ա�����Ķ������ģ������б����Ρ�

��Ա���������Ǻ���ģ�壬��ָ�����Ӳ������������ʾ����ʾ��*/
template<typename T>
class X
{
public:
    template<typename U>
    void mf(const U& u);
};

template<typename T> template <typename U>
void X<T>::mf(const U& u)
{
}

int main220302()
{

    return 0;
}