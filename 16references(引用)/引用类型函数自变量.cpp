



#include <iostream>

struct Date
{
    short Month;
    short Day;
    short Year;
};

// ����һ����ʽΪ DDDYYYY (day of year, year) ������
// �������ڡ�
long DateOfYear(const Date& date)
{
    static int cDaysInMonth[] = {
        31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    long dateOfYear = 0;

 // ����Ѿ���ȥ���·ݵ�������
    for (int i = 0; i < date.Month - 1; ++i)
        dateOfYear += cDaysInMonth[i];

// ��ӱ��µ�������
    dateOfYear += date.Day;

// ������ꡣ
    if (date.Month > 2 &&
        ((date.Year % 100 != 0 || date.Year % 400 == 0) &&
            date.Year % 4 == 0))
        dateOfYear++;

// �����ݡ�
    dateOfYear *= 10000;
    dateOfYear += date.Year;

    return dateOfYear;
}

int main0401()
{
    Date date{ 12, 2, 2021};
    long dateOfYear = DateOfYear(date);
    std::cout << dateOfYear << std::endl;



    return 0;
}

/*
������Ϊ�������ʹ��ݵĲ�����ѭ��ָ�����͵��﷨�������Ǳ�����ָ�����͵�һ����Ҫ��������������Ϊ �����������ǿ��޸ĵ� const �� �������������Ŀ�Ĳ����޸Ķ��� date����˸����ʵĺ���ԭ���ǣ�

C++

����
long DateOfYear( const Date& date );
*/