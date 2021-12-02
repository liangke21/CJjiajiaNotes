


/*
有时，对象必须存储访问对象的基础对象 shared_ptr而不导致 引用计数递增。 
通常，当实例之间具有循环引用时，会发生 shared_ptr 此情况。

最佳设计是尽可能避免指针的共享所有权。 但是，如果必须具有实例的共享 shared_ptr 所有权，
请避免在实例之间循环引用。 当循环引用无法避免，或者出于某种原因更可取时，
请使用 weak_ptr为一个或多个所有者提供对另一个 的弱引用 。 通过使用 ，
可以创建联接到现有相关实例集的 ，但仅在基础内存资源 weak_ptrshared_ptr 仍然有效时。
weak_ptr本身不参与引用计数，因此它不能阻止引用计数进入零。
但是，可以使用 weak_ptr 尝试获取用于初始化它的 shared_ptr 的新副本。 
如果内存已被删除， weak_ptr 则 的 bool 运算符返回 false 。
如果内存仍然有效，则新的共享指针会递增引用计数，
并保证只要变量保留在范围内，内存 shared_ptr 就有效。


示例
下面的代码示例演示了一种情况，其中 用于 weak_ptr 确保正确删除具有循环依赖项的对象。
检查该示例时，假设它仅在考虑替代解决方案后创建。 Controller对象表示计算机进程的某些方面，
它们独立运行。 每个控制器必须能够随时查询其他控制器的状态，
并且每个控制器都包含一个 vector<weak_ptr<Controller>> 专用控制器。
每个向量都包含一个循环引用，因此使用 实例 weak_ptr 而不是 shared_ptr 。
*/


#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;



class Controller
{

public:
    int Num;
    wstring Status;
    vector<weak_ptr<Controller>> others;
    explicit Controller(int i) : Num(i), Status(L"On")
    {
        wcout << L"Creating Controller" << Num << endl;
    }

    ~Controller()
    {
        wcout << L"Destroying Controller" << Num << endl;
    }

// 演示如何测试是否
    // 指向的内存是否仍然存在。
    void CheckStatuses() const
    {
        for_each(others.begin(), others.end(), [](weak_ptr<Controller> wp) {
            auto p = wp.lock();
            if (p)
            {
                wcout << L"Status of " << p->Num << " = " << p->Status << endl;
            }
            else
            {
                wcout << L"Null object" << endl;
            }
            });
    }
};

void RunTest()
{
    vector<shared_ptr<Controller>> v{
        make_shared<Controller>(0),
        make_shared<Controller>(1),
        make_shared<Controller>(2),
        make_shared<Controller>(3),
        make_shared<Controller>(4),
    };

// 每个控制器都依赖于未被删除的所有其他控制器。
    // 给每个控制器一个指向所有其他控制器的指针。
    for (int i = 0; i < v.size(); ++i)
    {
        for_each(v.begin(), v.end(), [&v, i](shared_ptr<Controller> p) {
            if (p->Num != i)
            {
                v[i]->others.push_back(weak_ptr<Controller>(p));
                wcout << L"push_back to v[" << i << "]: " << p->Num << endl;
            }
            });
    }

    for_each(v.begin(), v.end(), [](shared_ptr<Controller>& p) {
        wcout << L"use_count = " << p.use_count() << endl;
        p->CheckStatuses();
        });
}

int main170701()
{
    RunTest();
    wcout << L"按任意键" << endl;
    char ch;
    cin.getline(&ch, 1);

    return 0;
}