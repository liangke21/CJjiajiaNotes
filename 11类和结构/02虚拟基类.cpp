
/*

由于一个类可能多次成为派生类的间接基类，因此 C++ 提供了一种优化这种基类的工作方式的方法。 虚拟基类提供了一种节省空间和避免使用多重继承的类层次结构中出现多义性的方法。

每个非虚拟对象包含在基类中定义的数据成员的一个副本。 这种重复浪费了空间，并要求您在每次访问基类成员时都必须指定所需的基类成员的副本。

当将某个基类指定为虚拟基时，该基类可以多次作为间接基而无需复制其数据成员。 基类的数据成员的单个副本由将其用作虚拟基的所有基类共享。

声明虚拟基类时， virtual 关键字显示在派生类的基列表中。

请考虑下图中的类层次结构，它演示了模拟的午餐排队。
*/



class Queue {};
class CashierQueue : virtual public Queue {};
class LunchQueue : virtual public Queue {};
class LunchCashierQueue : public LunchQueue, public CashierQueue {};

//初始化构造函数试是从左到右;