

//示例：静态成员的地址

// expre_Address_Of_Operator.cpp
// C2440 expected
class PTM {
public:
    int iValue;
    static float fValue;
};

int main4() {
    int   PTM::* piValue = &PTM::iValue;  // OK: non-static
  //  float PTM::* pfValue = &PTM::fValue;  // C2440 error: static
  //  float* spfValue = &PTM::fValue;  // OK

    return 0;
}

//示例：引用类型的地址

// expre_Address_Of_Operator2.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;
int main42() {
    double d=3.14;        // Define an object of type double.
    double& rd = d;  // Define a reference to the object.

    // 获取并比较他们的地址
    if (&d == &rd)
        cout << "&d equals &rd" << endl;

    cout << "d 地址 : " << &d << endl;

    cout << "rd 地址 : " << &rd << endl;
    return 0;
}

//示例：作为参数的函数地址

// expre_Address_Of_Operator3.cpp
// compile with: /EHsc
// Demonstrate address-of operator &

#include <iostream>
using namespace std;

// Function argument is pointer to type int
int square(int* n) {
    return (*n) * (*n);
}

int main43() {
    int mynum = 5;
    cout << square(&mynum) << endl;   // pass address of int

    return 0;
}