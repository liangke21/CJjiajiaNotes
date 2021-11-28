// MemoryBlock.h
#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <format>

class MemoryBlock
{
public:

    // 初始化资源的简单构造函数。
    explicit MemoryBlock(size_t length)
        : _length(length)
        , _data(new int[length])
    {
        std::cout << "在内存块中（大小 t）。长度 = "
            << _length << "." << std::endl;
    }

    // Destructor.
    ~MemoryBlock()
    {
        std::cout << "在 ~Memory Block() 中。长度 = "
            << _length << ".";

        if (_data != nullptr)
        {
            std::cout << " 正在删除资源。";
            // 删除资源。
            delete[] _data;
        }

        std::cout << std::endl;
    }

    //复制构造函数。
    MemoryBlock(const MemoryBlock& other)
        : _length(other._length)
        , _data(new int[other._length])
    {
        std::cout << "在内存块（const Memory Block&amp;）中。长度= "
            << other._length << ". 复制资源." << std::endl;

        std::copy(other._data, other._data + _length, _data);
    }

    // 复制赋值运算符。
    MemoryBlock& operator=(const MemoryBlock& other)
    {
        std::cout << "在 operator=(const Memory Block&amp;) 中。长度 = "
            << other._length << ". 复制资源。" << std::endl;

        if (this != &other)
        {
            // 释放现有资源。
            delete[] _data;

            _length = other._length;
            _data = new int[_length];
            std::copy(other._data, other._data + _length, _data);
        }
        return *this;
    }

    // 检索数据资源的长度。
    size_t Length() const
    {
        return _length;
    }


    // 移动构造函数。
    MemoryBlock(MemoryBlock&& other) noexcept
        : _data(nullptr)
        , _length(0)
    {
        std::cout << "在内存块（Memory Block&amp;&amp;）。长度 = "
            << other._length << ". 移动资源。" << std::endl;

        //复制数据指针及其长度
        // 源对象。
        _data = other._data;
        _length = other._length;

        // 从源对象释放数据指针，以便
        // 析构函数不会多次释放内存。
        other._data = nullptr;
        other._length = 0;
    }

    // 移动赋值运算符。
    MemoryBlock& operator=(MemoryBlock&& other) noexcept
    {
        std::cout << "在 operator=(Memory Block&amp;&amp;) 中。长度 = "
            << other._length << "." << std::endl;

        if (this != &other)
        {
            // 释放现有资源。
            delete[] _data;

            // 复制数据指针及其长度
            // 源对象。
            _data = other._data;
            _length = other._length;

            // 从源对象释放数据指针，以便
            //析构函数不会多次释放内存。
            other._data = nullptr;
            other._length = 0;
        }
        return *this;
    }



private:
    size_t _length; // 资源的长度。
    int* _data; // 资源。




    //完成移动构造函数和赋值运算符


    



};


int main100301()
{
    // 创建一个矢量对象并向其添加一些元素。
    std::vector<MemoryBlock> v;
    v.push_back(MemoryBlock(25));
    v.push_back(MemoryBlock(75));
    //push_back   通过移动到元素末尾插入，提供强有力的保证
    // 在向量的第二个位置插入一个新元素。
    v.insert(v.begin() + 1, MemoryBlock(50));

    return 0;
}

/*
在内存块中（大小 t）。长度 = 25.
在内存块（Memory Block&amp;&amp;）。长度 = 25. 移动资源。
在 ~Memory Block() 中。长度 = 0.
在内存块中（大小 t）。长度 = 75.
在内存块（Memory Block&amp;&amp;）。长度 = 75. 移动资源。
在内存块（Memory Block&amp;&amp;）。长度 = 25. 移动资源。
在 ~Memory Block() 中。长度 = 0.
在 ~Memory Block() 中。长度 = 0.
在内存块中（大小 t）。长度 = 50.
在内存块（Memory Block&amp;&amp;）。长度 = 50. 移动资源。
在内存块（Memory Block&amp;&amp;）。长度 = 25. 移动资源。
在内存块（Memory Block&amp;&amp;）。长度 = 75. 移动资源。
在 ~Memory Block() 中。长度 = 0.
在 ~Memory Block() 中。长度 = 0.
在 ~Memory Block() 中。长度 = 0.
在 ~Memory Block() 中。长度 = 25. 正在删除资源。
在 ~Memory Block() 中。长度 = 50. 正在删除资源。
在 ~Memory Block() 中。长度 = 75. 正在删除资源。


*/