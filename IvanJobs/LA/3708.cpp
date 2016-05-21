#include <bits/stdc++.h>

#define REP(i, n) for(int _n = n, i = 0; i < _n; i++)
#define FOR(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define RFOR(i, b, a) for (int i = (b), _b = (a); i >= _b; i--)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Abs(x) ((x) > 0 ? (x) :(-(x)))
#define L(fmt, ...) do {if(true) printf(fmt"\n", ##__VA_ARGS__);} while(false)

#define EP 0.0000000001

int main() {
    int n, m;
    const double L = 10000.00;
    while(scanf("%d%d", &n, &m) != EOF) {
        double dn = L/(double)n;
        double dm = L/(double)(m + n);
        
        double res = 0.0;
        FOR(i, 1, n - 1) {
            double remain = (dn * i) - floor(dn * i / dm) * dm;
            res += Min(remain, dm - remain);
        }
        
        printf("%.4lf\n", res);
        
    }
    return 0;
}
