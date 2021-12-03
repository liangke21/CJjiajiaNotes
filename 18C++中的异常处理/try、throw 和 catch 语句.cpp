
/*
首先，使用 try 块将一个或多个可能引发异常的语句括起来。

throw表达式发出信号表示异常情况（通常是错误）已在块中发生 try 。
您可以使用任何类型的对象作为表达式的操作数 throw 。
该对象一般用于传达有关错误的信息。 在大多数情况下，
我们建议使用 std：： exception 类或在标准库中定义的一个派生类。
如果不适合这样做，我们建议您从派生自己的异常类 std::exception 。

若要处理可能引发的异常，请在块后面立即实现一个或多个 catch 块 try 。
每个 catch 块指定它可以处理的异常的类型。

此示例显示了一个 try 块及其处理程序。 
假设 GetNetworkResource() 通过网络连接获取数据，
并且两个异常类型是从 std::exception 派生的用户定义的类。 
请注意，异常是通过 const 语句中的引用捕获的 catch 。
我们建议你通过值引发异常并通过常数引用将其捕获。

*/
//MyData md;
//try {
//    // 可能引发异常的代码
//    md = GetNetworkResource();
//}
//catch (const networkIOException& e) {
//// 类型异常时执行的代码
//    // 在 try 块中抛出网络 IOException
//    // ...
//    // 在异常对象中记录错误信息
//    cerr << e.what();
//}
//catch (const myDataFormatException& e) {
//    // 处理另一种异常类型的代码
//    // ...
//    cerr << e.what();
//}
//
//// 以下语法显示了一个 throw 表达式
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