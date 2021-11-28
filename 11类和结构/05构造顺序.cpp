
/*
派生类构造函数始终调用基类构造函数，因此，在完成任何额外任务之前，它可以依赖于完全构造的基类。 
基类构造函数按派生顺序调用，例如，如果 派生自 （派生自 ），则首先调用构造函数，然后调用构造函数，
然后调用 ClassA ClassB ClassC ClassC ClassB ClassA 构造函数。

如果基类没有默认构造函数，则必须在派生类构造函数中提供基类构造函数参数：
*/

#include <iostream>

using namespace std;

class Contained1 {
public:
    Contained1() { cout << "包含 1 个演员\n"; }//1
};

class Contained2 {
public:
    Contained2() { cout << "包含 2 ctor\n"; }//2
};

class Contained3 {
public:
    Contained3() { cout << "包含 3 ctor\n"; }//4
};

class BaseContainer {
public:
    BaseContainer() { cout << "基础容器构造器\n"; }//3
private:
    Contained1 c1;
    Contained2 c2;
};

class DerivedContainer : public BaseContainer {
public:
    DerivedContainer() : BaseContainer() { cout << "派生容器构造函数\n"; }//5
private:
private:
    Contained3 c3;
};

int main100105() {
    DerivedContainer dc;
    return 0;
}

/*

派生类构造函数始终调用基类构造函数，因此，在完成任何额外任务之前，它可以依赖于完全构造的基类。
基类构造函数按派生顺序调用，例如，如果 派生自 （派生自 ），则首先调用构造函数，然后调用构造函数，
然后调用 ClassA ClassB ClassC ClassC ClassB ClassA 构造函数。

如果基类没有默认构造函数，则必须在派生类构造函数中提供基类构造函数参数：
*/

class Box {
public:
    Box(int width, int length, int height) {
        m_width = width;
        m_length = length;
        m_height = height;
    }

private:
    int m_width;
    int m_length;
    int m_height;
};

class StorageBox : public Box {
public:
    StorageBox(int width, int length, int height, const string label) : Box(width, length, height) {
        m_label = label;
    }
private:
    string m_label;
};

int main10010501() {

    const string aLabel = "aLabel";
    StorageBox sb(1, 2, 3, aLabel);

    return 0;
}