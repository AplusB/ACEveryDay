#include <cstdio>
const int  mod = 10000007;

long long f[10010];
int main()
{
    int T, ca = 1;
    scanf("%d", &T);
    while(T--) {
        printf("Case %d: ", ca++);
        int n;
        for(int i = 0; i < 6; i++) {
            scanf("%lld", &f[i]);
            f[i] %= mod;
        }
        scanf("%d", &n);
        for(int i = 6; i <= n; i++) {
            f[i] = 0;
            for(int j = i - 1; j >= i - 6; j--) {
                f[i] += f[j];
                f[i] %= mod;
            }
        }
        printf("%lld\n", f[n]);
    }
    return 0;
}
