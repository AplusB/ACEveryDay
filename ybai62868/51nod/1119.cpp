#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,n) for(int i = a; i < n; i++)
#define repe(i,a,n) for(int i = a; i <= n; i++)
#define per(i,n,a) for(int i = n; i >= a; i--)
#define clc(a,b) memset(a,b,sizeof(a))
const int INF = 0x3f3f3f3f, MAXN = 2000000+10;
const LL MOD = (LL)1e9+7;
LL f[MAXN];
 
LL pow_mod(LL x, int n)
{
    LL ans = 1;
    while(n)
    {
        if(n&1) ans = ans*x%MOD;
        x = x*x%MOD;
        n >>= 1;
    }
    return ans;
}
int main()
{
#ifdef SHY
    freopen("d:\\1.txt", "r", stdin);
#endif
    int n,m;
    scanf("%d%d", &n, &m);
    f[1] = 1;
    repe(i,2,n+m-2) f[i] = f[i-1]*i%MOD;
    LL a = f[n+m-2], b = f[m-1]*f[n-1]%MOD;
    printf("%lld\n", a*pow_mod(b,MOD-2)%MOD);
    return 0;
}
