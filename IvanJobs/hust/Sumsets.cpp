#include <stdio.h>

#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

long long A[1000000 + 100];

int main() {
    int N;
    scanf("%d", &N);
    A[1] = 1;
    A[2] = 2;
    A[3] = 2;
    A[4] = 4;
    if (N <= 4) printf("%lld\n", A[N]);
    else {
        for (int i = 5; i <= N; i++) {
            if (i & 1) {
                A[i] = A[i - 1];
            } else {
                A[i] = (A[i - 2] + A[i/2]) % 1000000000;
            }
        }
        printf("%lld\n", A[N]);
    }
    return 0;
}
