/*
ID: theoakt1
TASK: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long ul;
struct gap {
    ul b = 0; // start of gap; unoccupied
    ul e = 0; // end of gap; unoccupied
    unsigned len() const { return b && e?e - b + 1:0; }
    bool operator==(const gap& rhs) const { return b == rhs.b && e == rhs.e; }
};

ifstream ifs("barn1.in");
ofstream ofs("barn1.out");
ul M = 0; // #max boards
ul S = 0; // #stalls
ul C = 0; // #cows (#occupied stalls)
ul i = 0;
ul l = 0; // last occupied stall
ul n = 0; // current occupied stall
ul L = 0; // total length of board
gap gb, ge;
bool b = false, e = false;

vector<int> occupied;
vector<gap> gaps;
vector<gap> lgaps; // largest M gaps

int main(int argc, char *argv[]) {
    ifs >> M >> S >> C;
    for (i = 0; i != C; i++) {
        ifs >> n;
        occupied.push_back(n);
    }
    sort(occupied.begin(),occupied.end());
    for (i = 0; i != C; i++) {
        n = occupied[i];
        if (n - l > 1) 
            gaps.push_back({l+1,n-1});
        l = n;
    }
    if (l != S)
        gaps.push_back(ge = {l + 1, S});
    if (gaps[0].b == 1)
        gb = gaps[0];
    sort(gaps.begin(), gaps.end(), [](const gap& lhs, const gap& rhs) {
        return lhs.len() > rhs.len();
    });
    for (i = 0; i != min(M - 1, (ul)gaps.size()); i++) {
        lgaps.push_back(gaps[i]);
        if (gaps[i] == gb){
            M++;
            gb = {0,0};
        }
        if (gaps[i] == ge) {
            M++;
            ge = {0,0};
        }
    }
    L = S;
    for (i = 0; i != lgaps.size(); i++)
        L -= lgaps[i].len();
    ofs << L - gb.len() - ge.len() << '\n';
    return 0;
}
