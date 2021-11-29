

struct Document {
    char* Name;
    void PrintNameOf() {}
};

class PaperbackBook : public Document {};

int main130301() {
    Document* DocLib[10];   // 十个文档库。
    for (int i = 0; i < 5; i++)
        DocLib[i] = new Document;
    for (int i = 5; i < 10; i++)
        DocLib[i] = new PaperbackBook;

    return 0;
}
/*
在前面的示例中，创建了不同的类型。 但是，由于这些类型都派生自 Document 类，因此存在对 Document * 的隐式转换。 因此，DocLib 是“异类列表”（其中包含的所有对象并非属于同一类型），该列表包含不同类型的对象。

由于 Document 类具有一个 PrintNameOf 函数，因此它可以打印库中每本书的名称，但它可能会忽略某些特定于文档类型的信息（Book 的页计数、HelpFile 的字节数等）。

 备注

强制使用基类来实现函数（如 PrintNameOf）通常不是最佳设计。 虚拟函数 提供其他设计替代方法。
*/