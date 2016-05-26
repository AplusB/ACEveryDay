#include <bits/stdc++.h>

#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

using namespace std;

map<int, int> M;

int main() {
    int step, mod;
    while(scanf("%d%d", &step, &mod) != EOF) {
        int seed = 0;
        int idx = 0;
        int b, e;
        M.clear();
        M[0] = 0;
        do {
            seed = (seed + step) % mod;
            idx++;
            if (M.find(seed) == M.end()) {
                M[seed] = idx;
            } else {
                b = M[seed];
                e = idx;
                break;
            }
        } while(true);

        if (e - b == mod) {
            printf("%10d%10d    %-10s\n", step, mod, "Good Choice");
        } else {
            printf("%10d%10d    %-10s\n", step, mod, "Bad Choice");
        }
        printf("\n");
    }
    return 0;
}
