

//模板可以是模板参数。 在此示例中，MyClass2 具有两个模板参数： typename 参数 T 和模板参数 Arr：

template<typename T, template<typename U, int I> class Arr>
class MyClass2
{
    T t; //OK
    Arr<T, 10> a;
   // U u; //错误。你不在范围内
};
//由于 Arr 参数本身没有正文，因此不需要它的参数名称。 事实上，引用 Arr的 typename 或类参数名称是错误的 。 出于此原因，可以省略 Arr的类型参数名称，如以下示例中所示：
template<typename T, template<typename, int> class Arr>
class MyClass3
{
    T t; //OK
    Arr<T, 10> a;
};

int main220104() {

    return 0;
}