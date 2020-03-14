/*
USER: theoakt1
TASK: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
unsigned maxc = 0, maxi = 0; // max continuous & idle
struct intv{
    unsigned b = 0;
    unsigned e = 0;
    bool overlaps(const intv& rhs) const {
        return max(b,rhs.b) <= min(e,rhs.e);
    }
    bool within(const intv& rhs) const {
        return rhs.b < b && rhs.e > e;
    }
    void merge(const intv& rhs) {
        b = min(b,rhs.b);
        e = max(e,rhs.e);
    }
    unsigned len() const { return e-b; }
    operator string() const {
        return to_string(b) + " " + to_string(e);
    }
} c;
bool comp(const intv& lhs, const intv& rhs) {
    return lhs.b <= rhs.b;
}
vector<intv> v; 
stack<intv> idle; 
intv C;
unsigned N = 0;
void find_idle() {
    unsigned old_maxi = maxi;
    maxi = max(maxi, C.b > c.e?C.b - c.e:0);
    if (maxi != old_maxi)
        idle.push({c.e,C.b});
    if (!idle.empty() && idle.top().within(c)) {
        while (idle.size()) {
            idle.pop();
            if (idle.empty() || !idle.top().overlaps(c)) break;
        }
    }
    if (idle.empty()) maxi = 0;
    else maxi = idle.top().len();
}
int main(int argc, char *argv[]) {
    ifstream ifs("milk2.in");
    ifs >> N;
    // somehow v.reserve(N) screws up std::sort
    // so I just used push_back
    for (size_t i = 0; i < N; i++) {
        ifs >> c.b >> c.e;
        v.push_back(c);
    }
    if (N > 1) {
        sort(v.begin(), v.end(),comp);
        c = v[0];
        for (size_t i = 1; i < N; ++i) {
            C = v[i];
            if (c.overlaps(C))
                c.merge(C);
            else {
                maxc = max(c.len(), maxc);
                find_idle();
                c = C;
            }
            if (i == N - 1) {
                maxc = max(c.len(), maxc);
                find_idle();
            }
        }
    }
    else if (N == 1) {
        maxc = v[0].len();
        maxi = 0;
    }
    ofstream ofs;
    ofs.open("milk2.out");
    ofs << maxc << ' ' << maxi << '\n';
    return 0;
}
