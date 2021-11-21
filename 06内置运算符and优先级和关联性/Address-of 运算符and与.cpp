

//ʾ������̬��Ա�ĵ�ַ

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

//ʾ�����������͵ĵ�ַ

// expre_Address_Of_Operator2.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;
int main5() {
    double d=3.14;        // Define an object of type double.
    double& rd = d;  // Define a reference to the object.

    // ��ȡ���Ƚ����ǵĵ�ַ
    if (&d == &rd)
        cout << "&d equals &rd" << endl;

    cout << "d ��ַ : " << &d << endl;

    cout << "rd ��ַ : " << &rd << endl;
    return 0;
}

//ʾ������Ϊ�����ĺ�����ַ

// expre_Address_Of_Operator3.cpp
// compile with: /EHsc
// Demonstrate address-of operator &

#include <iostream>
using namespace std;

// Function argument is pointer to type int
int square(int* n) {
    return (*n) * (*n);
}

int main() {
    int mynum = 5;
    cout << square(&mynum) << endl;   // pass address of int
}