// 用于::静态成员
#include <iostream>
class ClassG {
public:
    static int get_x() { return x; }
    static int x;
};

int ClassG::x = 6;
using namespace std;
int main295() {

    int gx1 = ClassG::x;

    cout << "gxl : " << gx1 << endl;
    int gx2 = ClassG::get_x();

    cout << "gx2 : " << gx2 << endl;

    return 0;
}