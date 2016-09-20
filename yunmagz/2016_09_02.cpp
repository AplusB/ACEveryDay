//HDU 5446 Unknown Treasure
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=772002;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
void extend_gcd(LL a, LL &x, LL b, LL &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return;
    }
    LL x1, y1;
    extend_gcd(b, x1, a%b, y1);
    x = y1;
    y = x1 - (a / b)*y1;
}
LL inv(LL a, LL m)
{
    LL t1, t2;
    extend_gcd(a, t1, m, t2);
    return (t1%m + m) % m;
}
LL qpow(LL x, LL y, LL m)
{
    if (!y)return 1;
    LL ans = qpow(x, y >> 1, m);
    ans = ans*ans%m;
    if (y & 1)ans = ans*x%m;
    return ans;
}

LL nump(LL x, LL p)
{
    LL ans = 0;
    while (x)ans += x / p, x /= p;
    return ans;
}
LL fac(LL n, LL p, LL pk)
{
    if (n == 0)return 1;
    LL ans = 1;
    for (LL i = 1; i <= pk; i++)
    {
        if (i%p == 0)continue;
        ans = ans*i%pk;
    }
    ans = qpow(ans, n / pk, pk);
    LL to = n%pk;
    for (LL i = 1; i <= to; i++)
    {
        if (i%p == 0)continue;
        ans = ans*i%pk;
    }
    return fac(n / p, p, pk)*ans%pk;
}
LL cal(LL n, LL m, LL p, LL pi, LL pk)
{
    LL a = fac(n, pi, pk), b = fac(m, pi, pk), c = fac(n - m, pi, pk);
    LL d = nump(n, pi) - nump(m, pi) - nump(n - m, pi);
    LL ans = a%pk * inv(b, pk) % pk * inv(c, pk) % pk*qpow(p, d, pk) % pk;
    return ans*(p / pk) % p*inv(p / pk, pk) % p;
}
LL mCnmodp(LL n, LL m,LL p)
{
    LL ans = 0;
    LL x = p;
    for (LL i = 2; i*i <= x&&x>1; i++)
    {
        LL k = 0, pk = 1;
        while (x%i == 0)
        {
            x /= i;
            k++;
            pk *= i;
        }
        if (k>0)
            ans = (ans + cal(n, m, p, i, pk)) % p;
    }
    if (x>1)ans = (ans + cal(n, m, p, x, x)) % p;
    return ans;
}
LL qtpow(LL x, LL y, LL M)
{
    LL ret = 0LL;
    for (x %= M; y; y >>= 1LL)
    {
        if (y & 1LL)
        {
            ret += x;
            ret %= M;
            if (ret<0) ret += M;
        }
        x += x;
        x %= M;
        if (x<0) x += M;
    }
    return ret;
}
void solve(LL r[], LL s[], int t)
{
    LL M = 1LL, ans = 0LL;
    LL p[20], q[20], e[20];
    for (int i = 0; i<t; i++)
        M *= r[i];
    for (int i = 0; i<t; i++)
    {
        LL tmp = M / r[i], tt;
        extend_gcd(tmp, p[i], r[i], q[i]);
        p[i] %= M;
        if (p[i]<0) p[i] += M;
        e[i] = qtpow(tmp, p[i], M);
        tt = qtpow(e[i], s[i], M);
        ans = (ans + tt) % M;
        if (ans<0) ans += M;
    }
    printf("%I64d\n", ans);
}

LL CCC[20], DDD[20];
int main()
{
    int t;
    scanf("%d", &t);
    int num = 0;
    LL n, m, p;
    while (t--)
    {
        memset(CCC, 0, sizeof(CCC));
        memset(DDD, 0, sizeof(DDD));
        scanf("%I64d %I64d %d", &n, &m, &num);
        for (int i = 0; i<num; i++)
        {
            scanf("%I64d", &CCC[i]);
            DDD[i] = mCnmodp(n, m, CCC[i]);
        }
        solve(CCC, DDD, num);
    }
    return 0;
}
