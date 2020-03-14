/*
ID: theoakt1
TASK: beads
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
#include <queue>
using namespace std; // for CP's sake
int main() {
    ifstream ifs("beads.in");
    string bd; // beads
    ifs >> bd >> bd; // discard N
    size_t len = bd.length();
    unsigned maxb = 0;
    bool same = true;
    if (bd.size() > 1) {
        bd += bd; // simulate a ring
        struct group {
            char b = '\0';
            unsigned n = 0;
            unsigned w = 0;
        } c;
        c.b = bd[0];
        c.n = 1;
        c.w = c.b=='w'?1:0;
        size_t groups = 0;
        queue<group> q;
        int rc = 0; // count groups processed after i >= len
        for (size_t i = 1; i <= len - 1 || (groups > 2 && !same && i <= len*2-1 && rc <= 2); i++) {
            if (c.b == 'w' && bd[i] != 'w') {
                c.b = bd[i];
                c.w=0;
                c.n++;
            }
            else if (bd[i] == 'w') {
                c.n++;
                c.w++;
            }
            else if (c.b != bd[i] || (groups == 1 && i == len - 1 && c.n++)) {
                same = false;
                q.push(c);
                groups++;
                c.b = bd[i];
                c.n = 1;
                c.w = 0;
                if (q.size() == 2) {
                    unsigned w = q.front().w;
                    maxb = max(maxb, q.front().n + q.back().n);
                    q.pop();
                    q.front().n += w;
                    if (i >= len) rc++;
                }
            }
            else {
                c.n++;
                c.w=0;
            }
        }
    }
    else maxb=len;
    if (same) maxb = len;
    ofstream ofs;
    ofs.open("beads.out");
    ofs << maxb << '\n';
    return 0;
}
