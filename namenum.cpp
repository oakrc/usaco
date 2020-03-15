#include <fstream>
#include <string>
#include <vector>
using namespace std;
vector<string> names;
typedef struct trie_node {
    trie_node *c[26];
    bool word = false;
    trie_node() {
        for (size_t i = 0; i < 26; i++)
            c[i] = nullptr;
    }
    ~trie_node() {
        for (size_t i = 0; i < 26; i++)
            delete c[i];
    }
} trie;
void insert(trie &t, const string &w) {
    trie_node *n = &t;
    unsigned a = 0;
    for (size_t i = 0; i != w.size(); i++) {
        a = unsigned(w[i] - 'A');
        if (n->c[a] == nullptr) {
            n->c[a] = new trie_node;
        }
        n = n->c[a];
    }
    n->word = true;
}
void query(trie_node* n, const string &w, size_t i = 0, string s = "") {
    unsigned num = w[i] - 48, alpha = 0;
    for (unsigned j = 0; j != 3; j++) {
        alpha = 3*(num-2)+j;
        if (alpha > 15) alpha++;
        if (n->c[alpha] != nullptr) {
            if (i < w.size() - 1)
                query(n->c[alpha], w, i+1, s + char(alpha + 65));
            else if (n->c[alpha]->word)
                names.push_back(s + char(alpha + 65));
        }
    }
}
int main(int argc, char *argv[]) {
    trie t;
    ifstream fdict("dict.txt");
    ifstream ifs("namenum.in");
    string line;
    while (getline(fdict, line))
        insert(t,line);
    ifs >> line;
    query(&t,line);
    ofstream ofs;
    ofs.open("namenum.out");
    size_t sz = names.size();
    for (size_t i = 0; i != sz; i++)
        ofs << names[i] << '\n';
    if (!sz)
        ofs << "NONE\n";
    return 0;
}
