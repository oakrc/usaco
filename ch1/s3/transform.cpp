/*
ID: theoakt1
TASK: transform
LANG: C++
*/

// from https://jvonk.github.io/usaco/2018/09/29/transform.html
// I was too lazy

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#define MAXN 10

struct Board {
    int n;
    char b[MAXN][MAXN];
};

/* rotate 90 degree clockwise: [r, c] -> [c, n - r] */
Board rotate(const Board& b) {
    Board nb;
    int r, c;

    nb.n = b.n;
    for(r=0; r<b.n; r++)
        for(c=0; c<b.n; c++)
            nb.b[c][b.n-1 - r] = b.b[r][c];
    return nb;
}

/* reflect board horizontally: [r, c] -> [r, n-1 -c] */
Board reflect(const Board& b)
{
    Board nb;
    int r, c;

    nb.n = b.n;
    for(r=0; r<b.n; r++)
        for(c=0; c<b.n; c++)
            nb.b[r][b.n-1 - c] = b.b[r][c];
    return nb;
}

/* return non-zero iff boards are equal */
int comp(const Board& b, const Board& bb) {
    int r, c;

    if(b.n != bb.n)
        return 0;
    for(r=0; r<b.n; r++)
        for(c=0; c<b.n; c++)
            if(b.b[r][c] != bb.b[r][c])
                return 0;
    return 1;
}

Board read(FILE *fin, int n) {
    Board b;
    int r, c;

    b.n = n;
    for(r=0; r<n; r++) {
        for(c=0; c<n; c++)
            b.b[r][c] = getc(fin);
        assert(getc(fin) == '\n');
    }
    return b;
}

int main() {
    FILE *fin, *fout;
    Board b, nb;
    int n, change;

    fin = fopen("transform.in", "r");
    fout = fopen("transform.out", "w");
    assert(fin != NULL && fout != NULL);

    fscanf(fin, "%d\n", &n);
    b = read(fin, n);
    nb = read(fin, n);

    if(comp(nb, rotate(b)))
        change = 1;
    else if(comp(nb, rotate(rotate(b))))
        change = 2;
    else if(comp(nb, rotate(rotate(rotate(b)))))
        change = 3;
    else if(comp(nb, reflect(b)))
        change = 4;
    else if(comp(nb, rotate(reflect(b)))
         || comp(nb, rotate(rotate(reflect(b))))
         || comp(nb, rotate(rotate(rotate(reflect(b))))))
        change = 5;
    else if(comp(nb, b))
        change = 6;
    else
        change = 7;

    fprintf(fout, "%d\n", change);
    return 0;
}
