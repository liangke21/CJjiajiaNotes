/*
指针和数组密切相关。 当数组按值传递到函数时，它将作为指向第一个元素的指针传递。 下面的示例演示了指针和数组的以下重要属性：

sizeof运算符返回数组的总大小（以字节为单位）
若要确定元素的数目，请将总字节数除以一个元素的大小
当数组传递到函数时，它会 decays 到指针类型
sizeof应用到指针时，运算符返回指针大小、x86 上的4个字节或 x64 上的8个字节
*/

/*
指针和数组密切相关。 当数组按值传递到函数时，它将作为指向第一个元素的指针传递。 下面的示例演示了指针和数组的以下重要属性：

sizeof运算符返回数组的总大小（以字节为单位）
若要确定元素的数目，请将总字节数除以一个元素的大小
当数组传递到函数时，它会 decays 到指针类型

sizeof应用到指针时，运算符返回指针大小、x86 上的4个字节或 x64 上的8个字节
*/
#include <iostream>

void func(int arr[], int length)
{
    // 返回指针大小。在这里没用。
    size_t test = sizeof(arr);

    for (int i = 0; i < length; ++i)
    {
        std::cout << arr[i] << " ";
    }
}

int main0301()
{

    int i[5]{ 1,2,3,4,5 };
    // sizeof(i) = total bytes
    int j = sizeof(i) / sizeof(i[0]);// 获取数组的长度
    std::cout << sizeof(i) <<"  "<< sizeof(i[0]) << std::endl; //20 4
    func(i, j);
    return 0;
}
/*
某些算术运算可用于非 const 指针，以使其指向其他内存位置。 
使用 ++ 、 +=-= 和运算符递增和递减指针 -- 。 
此方法可用于数组中，在非类型化数据的缓冲区中尤其有用。
void*按 char (1 字节) 的大小增加。 类型化指针将按它所指向的类型的大小增加。


下面的示例演示如何使用指针算法访问 Windows 上的位图中的单个像素。 请注意，和的使用 newdelete 和取消引用运算
*/

#include <Windows.h>
#include <fstream>

using namespace std;

int main0301()
{

    BITMAPINFOHEADER header;
    header.biHeight = 100; // 为简单起见，4 的倍数。
    header.biWidth = 100;
    header.biBitCount = 24;
    header.biPlanes = 1;
    header.biCompression = BI_RGB;
    header.biSize = sizeof(BITMAPINFOHEADER);

    constexpr int bufferSize = 30000;
    unsigned char* buffer = new unsigned char[bufferSize];

    BITMAPFILEHEADER bf;
    bf.bfType = 0x4D42;
    bf.bfSize = header.biSize + 14 + bufferSize;
    bf.bfReserved1 = 0;
    bf.bfReserved2 = 0;
    bf.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER); //54

    // 创建一个带有 2 像素宽轮廓的灰色方块。
    unsigned char* begin = &buffer[0];
    unsigned char* end = &buffer[0] + bufferSize;
    unsigned char* p = begin;
    constexpr int pixelWidth = 3;
    constexpr int borderWidth = 2;

    while (p < end)
    {
        // 是上边还是下边？
        if ((p < begin + header.biWidth * pixelWidth * borderWidth)
            || (p > end - header.biWidth * pixelWidth * borderWidth)
            // 是左边缘还是右边缘？
            || (p - begin) % (header.biWidth * pixelWidth) < (borderWidth * pixelWidth)
            || (p - begin) % (header.biWidth * pixelWidth) > ((header.biWidth - borderWidth) * pixelWidth))
        {
            *p = 0x0; // Black
        }
        else
        {
            *p = 0xC3; // Gray
        }
        p++; // 增加一字节 sizeof(unsigned char)。
    }

    ofstream wf(R"(box.bmp)", ios::out | ios::binary);

    wf.write(reinterpret_cast<char*>(&bf), sizeof(bf));
    wf.write(reinterpret_cast<char*>(&header), sizeof(header));
    wf.write(reinterpret_cast<char*>(begin), bufferSize);

    delete[] buffer; // 将内存返回给操作系统。
    wf.close();

    return 0;
}