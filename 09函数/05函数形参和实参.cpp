#include <string>

//默认情况下，参数通过值传递给函数，这意味着函数会收到所传递的对象的副本。 
//对于大型对象，创建副本可能成本高昂，并非始终必要。 若要使参数按引用传递 (特别是左值) ，请向 参数添加引用限定符：

void DoSomething(std::string& input);

//当函数修改通过引用传递的参数时，它会修改原始对象，而不是本地副本。
//若要防止函数修改此类参数，请限定参数为 const&：
void DoSomething2(const std::string& input);

//若要显式处理通过 rvalue-reference 或 lvalue-reference 传递的参数，
//请使用 参数上的 double-ampersand 来指示通用引用：
void DoSomething3(const std::string&& input);

//使用参数声明列表中的单个关键字声明的函数不采用任何参数，只要关键字是参数声明列表的第一个且 void void 唯一的成员。
//列表中其他 void 位置的类型为 的参数会产生错误。 例如：
// OK same as GetTickCount()
long GetTickCount(void);

