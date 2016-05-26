#include <bits/stdc++.h>

#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

using namespace std;
int F[100];
map<string, int> M;

string make_key(int a, int b) {
    return to_string(a) + ':' + to_string(b);
}

int main() {
    int A, B, n;
    F[1] = F[2] = 1;
    while(scanf("%d%d%d", &A, &B, &n) && !(A == 0 && B == 0 && n == 0)) {
        M.clear();
        M[make_key(F[1], F[2])] = 2;
        int i = 3;
        int j = -1;
        do {
            F[i] = (A * F[i - 1] + B * F[i - 2]) % 7;
            string key = make_key(F[i], F[i - 1]);
            if (M.find(key) == M.end()) {
                M[key] = i;
            } else {
                j = M[key];
                break;
            }
            i++;
        } while(true);

        // from j => i - 1
        if (n < j) printf("%d\n", F[n]);
        else {
            int idx = (n - j) % (i - j);
            idx += j;
            printf("%d\n", F[idx]);
        }
    }
    return 0;
}
