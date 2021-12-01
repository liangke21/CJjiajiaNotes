


#include <limits>   // Includes DBL_MAX
#include <iostream>

const int cMkts = 4, cFacts = 2;

//����һ����������ɱ��ĸ�����
double TransportCosts[][cMkts] = {
   { 32.19, 47.29, 31.99, 19.11 },
   { 11.29, 22.49, 33.47, 17.29 },
   { 41.97, 22.09,  9.76, 22.55 }
};

// ����δָ��ά�ȵĴ�С
const int cFactories = sizeof TransportCosts /
sizeof(double[cMkts]);

double FindMinToMkt(int Mkt, double myTransportCosts[][cMkts], int mycFacts);

using namespace std;

int main0401(int argc, char* argv[]) {
    double MinCost;

    if (argv[1] == 0) {
        cout << "������ָ���г�������." << endl;
        exit(0);
    }
    MinCost = FindMinToMkt(*argv[1] - '0', TransportCosts, cFacts);
    cout << "��С���г��ɱ� " << argv[1] << " is: "
        << MinCost << "\n";

    return 0;
}

double FindMinToMkt(int Mkt, double myTransportCosts[][cMkts], int mycFacts) {
    double MinCost = DBL_MAX;

    for (size_t i = 0; i < cFacts; ++i)
        MinCost = (MinCost < TransportCosts[i][Mkt]) ?
        MinCost : TransportCosts[i][Mkt];

    return MinCost;
}