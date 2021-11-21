// expre_Selection_Operator.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

struct Date {
    Date(int i, int j, int k) : day(i), month(j), year(k) {}
    int month;
    int day;
    int year;
};

int main211() {
    Date mydate(1, 1, 1900);
    mydate.month = 2;
    cout << mydate.month << "/" << mydate.day
        << "/" << mydate.year << endl;//2 //1 //1900

    Date* mydate2 = new Date(1, 1, 2000);
    mydate2->month = 2;
    cout << mydate2->month << "/" << mydate2->day
        << "/" << mydate2->year << endl; //2 //1 //2000
    delete mydate2;

    return 0;
}