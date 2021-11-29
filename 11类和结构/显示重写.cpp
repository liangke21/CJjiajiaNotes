//��������������� �ӿ� ��������ͬһ�麯���������������������Щ�ӿڣ��������ʽ��дÿ���麯����
//extern "C" int printf_s(const char*, ...);

#include <stdio.h>
__interface IMyInt1 {
    void mf1();
    void mf1(int);
    void mf2();
    void mf2(int);
};

__interface IMyInt2 {
    void mf1();
    void mf1(int);
    void mf2();
    void mf2(int);
};

class CMyClass : public IMyInt1, public IMyInt2 {
public:
    void IMyInt1::mf1() {
        printf_s("�� CMyClass::IMyInt1::mf1()\n");
    }

    void IMyInt1::mf1(int) {
        printf_s("�� CMyClass::IMyInt1::mf1(int)\n");
    }

    void IMyInt1::mf2();
    void IMyInt1::mf2(int);

    void IMyInt2::mf1() {
        printf_s("�� CMyClass::IMyInt2::mf1()\n");
    }

    void IMyInt2::mf1(int) {
        printf_s("�� CMyClass::IMyInt2::mf1(int)\n");
    }

    void IMyInt2::mf2();
    void IMyInt2::mf2(int);
};

void CMyClass::IMyInt1::mf2() {
    printf_s("�� CMyClass::IMyInt1::mf2()\n");
}

void CMyClass::IMyInt1::mf2(int) {
    printf_s("�� CMyClass::IMyInt1::mf2(int)\n");
}

void CMyClass::IMyInt2::mf2() {
    printf_s("�� CMyClass::IMyInt2::mf2()\n");
}

void CMyClass::IMyInt2::mf2(int) {
    printf_s("�� CMyClass::IMyInt2::mf2(int)\n");
}

int main1401() {
    CMyClass* pIMyInt0 = new CMyClass();
    IMyInt1* pIMyInt1 = new CMyClass();
    IMyInt2* pIMyInt2 = dynamic_cast<IMyInt2*>(pIMyInt1);

    //pIMyInt0->mf1();//
    //pIMyInt0->mf1(1);//
    //pIMyInt0->mf2();//
    //pIMyInt0->mf2(2);          //������غ���

    pIMyInt1->mf1();//
    pIMyInt1->mf1(1);//
    pIMyInt1->mf2();//
    pIMyInt1->mf2(2);

    pIMyInt2->mf1();
    pIMyInt2->mf1(3);
    pIMyInt2->mf2();
    pIMyInt2->mf2(4);
    /*


////////////////////////////////////////

    �� CMyClass::IMyInt1::mf1()
    �� CMyClass::IMyInt1::mf1(int)
    �� CMyClass::IMyInt1::mf2()
    �� CMyClass::IMyInt1::mf2(int)

/////////////////////////////////////////////
     �� CMyClass::IMyInt2::mf1()
     �� CMyClass::IMyInt2::mf1(int)

     �� CMyClass::IMyInt2::mf2()
     �� CMyClass::IMyInt2::mf2(int)
    */
    // Cast to a CMyClass pointer so that the destructor gets called
    CMyClass* p = dynamic_cast<CMyClass*>(pIMyInt1);
    delete p;
}