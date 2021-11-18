// cl /EHsc /nologo /W4

class MyRefType {
private:
    MyRefType& operator=(const MyRefType&);
    MyRefType(const MyRefType&);
public:
    MyRefType() {}
};

int main11()
{
    MyRefType Data1, Data2;

 //   Data1 = Data2; // ≤ªø…∑√Œ 

    return 0;
}