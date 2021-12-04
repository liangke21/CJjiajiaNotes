


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
请注意，就像任何模板类成员函数一样，类的构造函数成员函数的定义包含模板参数列表两次。

成员函数可以是函数模板，并指定附加参数，如下面的示例所示。*/
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