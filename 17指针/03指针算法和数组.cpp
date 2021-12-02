/*
ָ�������������ء� �����鰴ֵ���ݵ�����ʱ��������Ϊָ���һ��Ԫ�ص�ָ�봫�ݡ� �����ʾ����ʾ��ָ��������������Ҫ���ԣ�

sizeof���������������ܴ�С�����ֽ�Ϊ��λ��
��Ҫȷ��Ԫ�ص���Ŀ���뽫���ֽ�������һ��Ԫ�صĴ�С
�����鴫�ݵ�����ʱ������ decays ��ָ������
sizeofӦ�õ�ָ��ʱ�����������ָ���С��x86 �ϵ�4���ֽڻ� x64 �ϵ�8���ֽ�
*/

/*
ָ�������������ء� �����鰴ֵ���ݵ�����ʱ��������Ϊָ���һ��Ԫ�ص�ָ�봫�ݡ� �����ʾ����ʾ��ָ��������������Ҫ���ԣ�

sizeof���������������ܴ�С�����ֽ�Ϊ��λ��
��Ҫȷ��Ԫ�ص���Ŀ���뽫���ֽ�������һ��Ԫ�صĴ�С
�����鴫�ݵ�����ʱ������ decays ��ָ������

sizeofӦ�õ�ָ��ʱ�����������ָ���С��x86 �ϵ�4���ֽڻ� x64 �ϵ�8���ֽ�
*/
#include <iostream>

void func(int arr[], int length)
{
    // ����ָ���С��������û�á�
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
    int j = sizeof(i) / sizeof(i[0]);// ��ȡ����ĳ���
    std::cout << sizeof(i) <<"  "<< sizeof(i[0]) << std::endl; //20 4
    func(i, j);
    return 0;
}
/*
ĳЩ������������ڷ� const ָ�룬��ʹ��ָ�������ڴ�λ�á� 
ʹ�� ++ �� +=-= ������������͵ݼ�ָ�� -- �� 
�˷��������������У��ڷ����ͻ����ݵĻ��������������á�
void*�� char (1 �ֽ�) �Ĵ�С���ӡ� ���ͻ�ָ�뽫������ָ������͵Ĵ�С���ӡ�


�����ʾ����ʾ���ʹ��ָ���㷨���� Windows �ϵ�λͼ�еĵ������ء� ��ע�⣬�͵�ʹ�� newdelete ��ȡ����������
*/

#include <Windows.h>
#include <fstream>

using namespace std;

int main0301()
{

    BITMAPINFOHEADER header;
    header.biHeight = 100; // Ϊ�������4 �ı�����
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

    // ����һ������ 2 ���ؿ������Ļ�ɫ���顣
    unsigned char* begin = &buffer[0];
    unsigned char* end = &buffer[0] + bufferSize;
    unsigned char* p = begin;
    constexpr int pixelWidth = 3;
    constexpr int borderWidth = 2;

    while (p < end)
    {
        // ���ϱ߻����±ߣ�
        if ((p < begin + header.biWidth * pixelWidth * borderWidth)
            || (p > end - header.biWidth * pixelWidth * borderWidth)
            // �����Ե�����ұ�Ե��
            || (p - begin) % (header.biWidth * pixelWidth) < (borderWidth * pixelWidth)
            || (p - begin) % (header.biWidth * pixelWidth) > ((header.biWidth - borderWidth) * pixelWidth))
        {
            *p = 0x0; // Black
        }
        else
        {
            *p = 0xC3; // Gray
        }
        p++; // ����һ�ֽ� sizeof(unsigned char)��
    }

    ofstream wf(R"(box.bmp)", ios::out | ios::binary);

    wf.write(reinterpret_cast<char*>(&bf), sizeof(bf));
    wf.write(reinterpret_cast<char*>(&header), sizeof(header));
    wf.write(reinterpret_cast<char*>(begin), bufferSize);

    delete[] buffer; // ���ڴ淵�ظ�����ϵͳ��
    wf.close();

    return 0;
}