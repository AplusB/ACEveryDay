#include <bits/stdc++.h>
#define LL long long
using namespace std;

void extend_gcd(LL A, LL B, LL &a, LL &b)
{
    if(A % B == 0)
    {
        a = 0;
        b = 1;
        return;
    }
    LL tx,ty;
    extend_gcd(B,A%B,tx,ty);
    LL x = ty,y = tx - (A/B)*ty;
    a = x;
    b = y;
}

LL gcd(LL A, LL B)
{
    if(A % B == 0) return B;
    else
        return gcd(B,A%B);
}

LL solve()
{
    int n;
    scanf("%d",&n);
    LL m[1005],r[1005];
    for(int i = 0; i < n; i++)
        scanf("%lld %lld",&m[i], &r[i]);
    LL M,R;
    M = m[0];
    R = r[0];
    for(int i = 1; i < n; i++)
    {
        LL d = gcd(M,m[i]);
        LL c = r[i] - R;

        if(c % d) return -1;

        LL k1,k2;
        extend_gcd(M/d,m[i]/d,k1,k2);
        k1 = (c/d *k1) % (m[i]/d);
        R += k1*M;
        M = M/d*m[i];
        R %= M;
    }
    if(R < 0) R += M;
    return R;
}

int main()
{
    printf("%lld\n",solve());
    return 0;
}
