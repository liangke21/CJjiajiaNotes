// MemoryBlock.h
#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <format>

class MemoryBlock
{
public:

    // ��ʼ����Դ�ļ򵥹��캯����
    explicit MemoryBlock(size_t length)
        : _length(length)
        , _data(new int[length])
    {
        std::cout << "���ڴ���У���С t�������� = "
            << _length << "." << std::endl;
    }

    // Destructor.
    ~MemoryBlock()
    {
        std::cout << "�� ~Memory Block() �С����� = "
            << _length << ".";

        if (_data != nullptr)
        {
            std::cout << " ����ɾ����Դ��";
            // ɾ����Դ��
            delete[] _data;
        }

        std::cout << std::endl;
    }

    //���ƹ��캯����
    MemoryBlock(const MemoryBlock& other)
        : _length(other._length)
        , _data(new int[other._length])
    {
        std::cout << "���ڴ�飨const Memory Block&amp;���С�����= "
            << other._length << ". ������Դ." << std::endl;

        std::copy(other._data, other._data + _length, _data);
    }

    // ���Ƹ�ֵ�������
    MemoryBlock& operator=(const MemoryBlock& other)
    {
        std::cout << "�� operator=(const Memory Block&amp;) �С����� = "
            << other._length << ". ������Դ��" << std::endl;

        if (this != &other)
        {
            // �ͷ�������Դ��
            delete[] _data;

            _length = other._length;
            _data = new int[_length];
            std::copy(other._data, other._data + _length, _data);
        }
        return *this;
    }

    // ����������Դ�ĳ��ȡ�
    size_t Length() const
    {
        return _length;
    }


    // �ƶ����캯����
    MemoryBlock(MemoryBlock&& other) noexcept
        : _data(nullptr)
        , _length(0)
    {
        std::cout << "���ڴ�飨Memory Block&amp;&amp;�������� = "
            << other._length << ". �ƶ���Դ��" << std::endl;

        //��������ָ�뼰�䳤��
        // Դ����
        _data = other._data;
        _length = other._length;

        // ��Դ�����ͷ�����ָ�룬�Ա�
        // ���������������ͷ��ڴ档
        other._data = nullptr;
        other._length = 0;
    }

    // �ƶ���ֵ�������
    MemoryBlock& operator=(MemoryBlock&& other) noexcept
    {
        std::cout << "�� operator=(Memory Block&amp;&amp;) �С����� = "
            << other._length << "." << std::endl;

        if (this != &other)
        {
            // �ͷ�������Դ��
            delete[] _data;

            // ��������ָ�뼰�䳤��
            // Դ����
            _data = other._data;
            _length = other._length;

            // ��Դ�����ͷ�����ָ�룬�Ա�
            //���������������ͷ��ڴ档
            other._data = nullptr;
            other._length = 0;
        }
        return *this;
    }



private:
    size_t _length; // ��Դ�ĳ��ȡ�
    int* _data; // ��Դ��




    //����ƶ����캯���͸�ֵ�����


    



};


int main100301()
{
    // ����һ��ʸ�������������һЩԪ�ء�
    std::vector<MemoryBlock> v;
    v.push_back(MemoryBlock(25));
    v.push_back(MemoryBlock(75));
    //push_back   ͨ���ƶ���Ԫ��ĩβ���룬�ṩǿ�����ı�֤
    // �������ĵڶ���λ�ò���һ����Ԫ�ء�
    v.insert(v.begin() + 1, MemoryBlock(50));

    return 0;
}

/*
���ڴ���У���С t�������� = 25.
���ڴ�飨Memory Block&amp;&amp;�������� = 25. �ƶ���Դ��
�� ~Memory Block() �С����� = 0.
���ڴ���У���С t�������� = 75.
���ڴ�飨Memory Block&amp;&amp;�������� = 75. �ƶ���Դ��
���ڴ�飨Memory Block&amp;&amp;�������� = 25. �ƶ���Դ��
�� ~Memory Block() �С����� = 0.
�� ~Memory Block() �С����� = 0.
���ڴ���У���С t�������� = 50.
���ڴ�飨Memory Block&amp;&amp;�������� = 50. �ƶ���Դ��
���ڴ�飨Memory Block&amp;&amp;�������� = 25. �ƶ���Դ��
���ڴ�飨Memory Block&amp;&amp;�������� = 75. �ƶ���Դ��
�� ~Memory Block() �С����� = 0.
�� ~Memory Block() �С����� = 0.
�� ~Memory Block() �С����� = 0.
�� ~Memory Block() �С����� = 25. ����ɾ����Դ��
�� ~Memory Block() �С����� = 50. ����ɾ����Դ��
�� ~Memory Block() �С����� = 75. ����ɾ����Դ��


*/