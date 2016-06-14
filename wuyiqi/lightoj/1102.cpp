#include <cstdio>
const int MOD = (int) 1e9 + 7;

long long p[2000100], fac[2000010];

int Pow(int a, int b)
{
    int ret = 1;
    while(b) {
        if(b & 1) {
            ret = 1LL * ret * a % MOD;
        }
        b >>= 1;
        a = 1LL * a * a % MOD;
    }
    return ret;
}
int main()
{
    int T, ca = 1;
    p[0] = 1;
    for(int i = 1; i <= 2000000; i++) {
        p[i] = 1LL * p[i - 1] * Pow(i, MOD - 2) % MOD;
    }
    fac[0] = 1;
    for(int i = 1; i <= 2000000; i++) {
        fac[i] = 1LL * fac[i - 1] * i % MOD;
    }
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        printf("Case %d: ", ca++);
        int m = n + k - 1;
        int ret = 1LL * fac[m] * p[n] % MOD * p[m - n] % MOD;
        printf("%d\n", ret);
    }
    return 0;
}
