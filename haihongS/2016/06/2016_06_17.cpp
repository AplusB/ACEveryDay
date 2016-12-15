#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=50+9;
const ll inf=1e8+2;

ll quick(ll x,ll n);

int main()
{
    ll n;
    while(~scanf("%lld",&n))
    {
        printf("%lld\n",quick(5,n));
    }
    return 0;
}

ll quick(ll x,ll n)
{
    ll mod=100;
    ll ans=1;
    while(n)
    {
        if(n&1)
            ans*=x;
        ans%=mod;
        n>>=1;
        x*=x;
        x%=mod;
    }
    return ans;
}

