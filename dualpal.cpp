/*
ID: theoakt1
TASK: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
ifstream ifs("dualpal.in");
ofstream ofs("dualpal.out");
unsigned N = 0;
unsigned S = 0;
unsigned b = 0;
unsigned n = 1; // current number
unsigned d = 0; // digit
unsigned r = 0; // reversed digit
unsigned t = 0; // temp
unsigned c = 0; // palindrome count
int main()
{
    ifs >> N >> S;
    for (n = S + 1; n <= S + N; n++) {
        c = 0;
        for (b = 2; b <= 10; b++) {
            r = 0;
            t = n;
            while (t != 0) {
                d = t % b;
                r = r * b + d;
                t /= b;
            }
            if (r == n) {
                c++;
                if (c == 2) {
                    ofs << n << '\n';
                    goto next;
                }
            }
        }
next:;
    }
    return 0;
}
