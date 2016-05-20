#include <bits/stdc++.h>

#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

using namespace std;

long long A[1000000 + 100];
long long C[1000000 + 100];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        long long s = 0;
        FOR(i, 1, n) {
            scanf("%lld", &A[i]);
            s += A[i];
        }
        long long avg = s / n;
       
        FOR(i, 1, n) {
            C[i] = avg - A[i];
        }
        
        C[0] = 0;

        FOR(i, 1, n) {
            C[i] += C[i - 1];
        }
        
        sort(C, C + n);
        long long res = 0;
        long long cur = C[n/2];
        REP(i, n) {
            res += Abs(C[i] - cur);
        }
        printf("%lld\n", res);
    }
    return 0;
}
