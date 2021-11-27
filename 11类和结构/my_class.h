/*
 
 pimpl 惯例 是一种新式 C++ 技术，用于隐藏实现、最小化耦合和分离接口。 Pimpl 对于"指向实现的指针"是短的。 你可能已熟悉概念，但通过其他名称（如 Che一 cat 或编译器防火墙惯例）了解它。

为何使用 pimpl？
下面是 pimpl 惯例如何改进软件开发生命周期：

最大程度地减少编译依赖项。

接口和实现分离。

可移植性。
 */

//Pimpl 标头

// my_class.h
//class my_class {
//	//  ... 所有公共和受保护的东西都放在这里......
//private:
//	class impl; unique_ptr<impl> pimpl; // 此处不透明类型
//};