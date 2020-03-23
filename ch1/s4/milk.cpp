/*
ID: theoakt1
TASK: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream ifs("milk.in");
ofstream ofs("milk.out");
unsigned N = 0; // milk needed
unsigned M = 0; // # sellers
unsigned p = 0; // total price to pay
unsigned a = 0; // total units ordered
unsigned n = 0; // current units
struct offer {
    unsigned units = 0; // max units avail
    unsigned price = 0;
}tmp;
vector<offer> order;
int main(int argc, char *argv[]) {
    ifs >> N >> M;
    for (unsigned i = 0; i != M; i++) {
        ifs >> tmp.price >> tmp.units;
        order.push_back(tmp);
    }
    sort(order.begin(),order.end(), [](const offer& lhs, const offer& rhs) {
        return lhs.price < rhs.price;
    });
    for (unsigned i = 0; i != order.size() && N != a; i++) {
        n = min(N-a,order[i].units);
        p += n * order[i].price;
        a += n;
    }
    ofs << p << '\n';
    return 0;
}
