/*
一 unique_ptr 不共享其指针。 它不能复制到另一个 ，按值传递给函数，也不能在需要创建副本的任何 C++ 标准库算法 unique_ptr 中使用。 只能移动 unique_ptr。 这意味着，内存资源所有权将转移到另一 unique_ptr，并且原始 unique_ptr 不再拥有此资源。 我们建议你将对象限制为由一个所有者所有，因为多个所有权会使程序逻辑变得复杂。 因此，当需要纯 C++ 对象的智能指针时，请使用 ，在构造 时，请使用 make_unique unique_ptrunique_ptr 程序函数。 unique_ptr

下图演示了两个 unique_ptr 实例之间的所有权转换。



unique_ptr 在 <memory> C++ 标准库的 标头中定义。 它的效率与原始指针完全相同，可用于 C++ 标准库容器。 向 C++ 标准库容器添加 实例非常高效，因为 的移动构造函数无需 unique_ptrunique_ptr 复制操作。
*/

//示例 1 以下示例演示如何创建 unique_ptr 实例并在函数之间传递这些实例。


#include <string>
#include <memory>
#include <vector>
#include <iostream>
using namespace std;

//class a {
//
//    unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title)
//    {
//        // 隐式移动操作到存储结果的变量中。
//        return make_unique<Song>(artist, title);
//    }
//
//    void MakeSongs()
//    {
//        // 使用新对象创建一个新的唯一 ptr。
//        auto song = make_unique<Song>(L"Mr. Children", L"Namonaki Uta");
//
//        // 使用唯一的ptr。
//        vector<wstring> titles = { song->title };
//
//        // 将原始指针从一个唯一的 ptr 移动到另一个.
//        unique_ptr<Song> song2 = std::move(song);
//
//        // 从按值返回的函数中获取唯一的ptr。
//        auto song3 = SongFactory(L"Michael Jackson", L"Beat It");
//    }
//};

//示例 2 以下示例演示如何创建 unique_ptr 实例并在向量中使用这些实例。
//void SongVector()
//{
//    vector<unique_ptr<Song>> songs;
//
//    // Create a few new unique_ptr<Song> instances
//    // and add them to vector using implicit move semantics.
//    songs.push_back(make_unique<Song>(L"B'z", L"Juice"));
//    songs.push_back(make_unique<Song>(L"Namie Amuro", L"Funky Town"));
//    songs.push_back(make_unique<Song>(L"Kome Kome Club", L"Kimi ga Iru Dake de"));
//    songs.push_back(make_unique<Song>(L"Ayumi Hamasaki", L"Poker Face"));
//
//// 尽可能通过常量引用来避免复制。
//    for (const auto& song : songs)
//    {
//        wcout << L"Artist: " << song->artist << L"   Title: " << song->title << endl;
//    }
//}

//示例 3 以下示例演示如何初始化类成员 unique_ptr。
//class MyClass
//{
//private:
//    // 我的班级拥有唯一的ptr。
//    unique_ptr<ClassFactory> factory;
//public:
//
//    // 使用具有类工厂默认构造函数的 make unique 进行初始化。
//    MyClass() : factory(make_unique<ClassFactory>())
//    {
//    }
//
//    void MakeClass()
//    {
//        factory->DoSomething();
//    }
//};

// 示例 4 可以使用 make_unique 创建数组的 ，但不能使用 make_unique 初始化数组元素。


int main170501() {

    // 为包含 5 个整数的数组创建唯一的 ptr。
    auto p = make_unique<int[]>(5);
    wcout << p << endl;
    wcout << &p << endl;
    wcout << "------------" << endl;
    // 初始化数组。
    for (int i = 0; i <5; ++i)
    {
        p[i] = i;
        wcout << &p[i] << endl;
    }
    return  0;
}