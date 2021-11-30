/*lambda 表达式的捕获子句不能包含具有托管类型的变量。 
但是，你可以将具有托管类型的实际参数传递到 lambda 表达式的形式参数列表。 
以下示例包含一个 lambda 表达式，它通过值捕获局部非托管变量 ch，并采用 System.String 对象作为其参数。*/
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