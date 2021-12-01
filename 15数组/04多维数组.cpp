


#include <limits>   // Includes DBL_MAX
#include <iostream>

const int cMkts = 4, cFacts = 2;

//声明一个代表运输成本的浮点数
double TransportCosts[][cMkts] = {
   { 32.19, 47.29, 31.99, 19.11 },
   { 11.29, 22.49, 33.47, 17.29 },
   { 41.97, 22.09,  9.76, 22.55 }
};

// 计算未指定维度的大小
const int cFactories = sizeof TransportCosts /
sizeof(double[cMkts]);

double FindMinToMkt(int Mkt, double myTransportCosts[][cMkts], int mycFacts);

using namespace std;

int main0401(int argc, char* argv[]) {
    double MinCost;

    if (argv[1] == 0) {
        cout << "您必须指定市场的数量." << endl;
        exit(0);
    }
    MinCost = FindMinToMkt(*argv[1] - '0', TransportCosts, cFacts);
    cout << "最小的市场成本 " << argv[1] << " is: "
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