/*
ID: theoakt1
TASK: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream ifs("palsquare.in");
ofstream ofs("palsquare.out");
unsigned B = 0; // given base
unsigned n = 1; // current number
unsigned s = 0; // squared
unsigned d = 0; // digit
unsigned r = 0; // reversed n
unsigned t = 0; // temp
string itoa(unsigned num) {
    string ret = "";
    while (num != 0) {
        d = num % B;
        if (d < 10) ret = char(d + 48) + ret;
        else ret = char(d + 55) + ret;
        num /= B;
    }
    return ret;
}
int main() {
    ifs >> B;
    for (; n <= 300; n++) {
        r = 0;
        t = s = n*n;
        while (t != 0) {
            d = t % B;
            r = r * B + d;
            t /= B;
        }
        if (r == s)
            ofs << itoa(n) << ' ' << itoa(s) << '\n';
    }
    return 0;
}
