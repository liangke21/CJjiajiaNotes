










// 以下示例假定这些声明：
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct MediaAsset
{
    virtual ~MediaAsset() = default; // 使其多态
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring& artist_, const std::wstring& title_) :
        artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring& date_,
        const std::wstring& location_,
        const std::wstring& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

using namespace std;

int main170601()
{
// 示例放在这里，按顺序：
    // 示例 1
 // 尽可能使用 make shared 函数。
    auto sp1 = make_shared<Song>(L"The Beatles", L"Im Happy Just to Dance With You");

// 好的，但效率稍低。
    // 注意：使用 new 表达式作为构造函数参数
    // 不创建命名变量供其他代码访问。
    shared_ptr<Song> sp2(new Song(L"Lady Gaga", L"Just Dance"));

// 当初始化必须与声明分开时，例如班级成员，
    // 使用 nullptr 进行初始化以使您的编程意图明确。
    shared_ptr<Song> sp5(nullptr);
//相当于：shared ptr&lt;Song&gt; sp5;
    //...
    sp5 = make_shared<Song>(L"Elton John", L"I'm Still Standing"); //复制



    // Example 2  以下示例演示如何声明和初始化对其他 shared_ptr 已分配的对象具有共享所有权的 shared_ptr 实例。 假设 sp2 是已初始化的 shared_ptr。
    

    //用复制构造函数初始化。增加引用计数。
    auto sp3(sp2);

    //通过赋值初始化。增加引用计数。
    auto sp4 = sp2;

    //用 nullptr 初始化。 sp7 是空的。
    shared_ptr<Song> sp7(nullptr);

   // 用另一个共享的ptr初始化。 sp1 和 sp2
    // 交换指针和引用计数。
    sp1.swap(sp2);



    // Example 3
    // 在你使用复制元素的算法时，shared_ptr 在 C++ 标准库容器中很有用。 
    // 您可以将元素包装在 shared_ptr 中，然后将其复制到其他容器中（请记住，只要您需要，基础内存就会一直有效）。 
    // 以下示例演示如何在向量中对 remove_copy_if 实例使用 shared_ptr 算法。
    vector<shared_ptr<Song>> v{
  make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"),
  make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"),
  make_shared<Song>(L"Thalía", L"Entre El Mar y Una Estrella")
    };

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](shared_ptr<Song> s)
        {
            return s->artist.compare(L"Bob Dylan") == 1; //删除下标1的值
        });

    for (const auto& s : v2)
    {
        wcout << s->artist << L":" << s->title << endl;
    }
    
    cout << "-------------------------"<<endl;
    // Example 4
 /*
 您可以使用 dynamic_pointer_cast、static_pointer_cast 和 const_pointer_cast 来转换 shared_ptr。 
 这些函数类似于 dynamic_cast、static_cast 和 const_cast 运算符。
 以下示例演示如何测试基类的 shared_ptr 向量中每个元素的派生类型，然后复制元素并显示有关它们的信息。
 */

    vector<shared_ptr<MediaAsset>> assets{
      make_shared<Song>(L"Himesh Reshammiya", L"Tera Surroor"),
      make_shared<Song>(L"Penaz Masani", L"Tu Dil De De"),
      make_shared<Photo>(L"2011-04-06", L"Redmond, WA", L"Soccer field at Microsoft.")
    };

    vector<shared_ptr<MediaAsset>> photos;

    copy_if(assets.begin(), assets.end(), back_inserter(photos), [](shared_ptr<MediaAsset> p) -> bool
        {
// 使用动态指针强制转换来测试是否
            // 元素是一个共享的ptr&lt;Photo&gt;。
            shared_ptr<Photo> temp = dynamic_pointer_cast<Photo>(p);
            return temp.get() != nullptr;
        });

    for (const auto& p : photos)
    {
// 我们知道照片向量只包含
        // 共享 ptr&lt;Photo&gt; 对象，所以使用静态转换。
        wcout << "Photo location: " << (static_pointer_cast<Photo>(p))->location << endl;
    }





    // Example 6

// 初始化两个独立的原始指针。
// 请注意，它们包含相同的值。
    auto song1 = new Song(L"Village People", L"YMCA");
    auto song2 = new Song(L"Village People", L"YMCA");

// 创建两个不相关的共享ptr。
    shared_ptr<Song> p1(song1);
    shared_ptr<Song> p2(song2);

    // 不相关的共享 ptr 永远不会相等。
    wcout << "p1 < p2 = " << std::boolalpha << (p1 < p2) << endl;
    wcout << "p1 == p2 = " << std::boolalpha << (p1 == p2) << endl;

    // 相关的共享 ptr 实例总是相等的。
    shared_ptr<Song> p3(p2);
    wcout << "p3 == p2 = " << std::boolalpha << (p3 == p2) << endl;
    return 0;
}