#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
size_t N = 0;
vector<bool> bef;
vector<bool> aft;
vector<int> s; // optimal solution
vector<int> c; // current
ifstream ifs("transform.in");
void read(vector<bool>& v) {
    string str = "";
    for (size_t i = 0; i != N; i++) {
        ifs >> str;
        for (size_t j = 0; j != N; j++) {
            v.push_back(str[j] == '@');
        }
    }   
}
int main(int argc, char *argv[]) {
    enum Transformation {
        T_90CW = 1,
        T_180CW,
        T_270CW,
        T_YREFL,
        T_REFL_ROT,
        T_SAME,
        T_INVALID
    };
    ifs >> N;
    read(bef);
    read(aft);
    if (bef != aft && N > 1) {
                
    }
    else {
        s.push_back(T_SAME);
    }
    ofstream ofs;
    ofs.open("transform.out");
    for (size_t i = 0; i != s.size(); i++) {
        ofs << s[i];
    }
    ofs << endl;
    return 0;
}
