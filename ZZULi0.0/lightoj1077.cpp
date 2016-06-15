#include <bits/stdc++.h>
#define LL long long
#define PI acos(-1.0)
using namespace std;

LL gcd(LL a ,LL b)
{
    if(a % b == 0) return b;
    return gcd(b,a%b);
}

void solve()
{
    LL a,b,c,d;
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    a = abs(a-c);
    b = abs(b-d);
    if(a == 0 || b == 0)
        printf("%lld\n",abs(b-a)+1);
    else
        printf("%lld\n",gcd(a,b)+1);
}

int main(void)
{
    int t,cnt = 0;

    scanf("%d",&t);
    while(t--)
    {
        printf("Case %d: ",++cnt);
        solve();
    }
    return 0;
}
