#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=50+9;
const ll inf=1e8+2;

ll bin(ll v);

int main()
{
    ll n;
    while(~scanf("%lld",&n))
    {
        ll node=bin(n);
        ll tmp=node*(node+1)/2;
        if(tmp==n)
            printf("%lld\n",node);
        else
            printf("%lld\n",n-tmp);
    }
    return 0;
}


ll bin(ll v)
{
    ll lt,rt,mid;
    lt=1,rt=inf;
    ll ans=1;
    while(lt<=rt)
    {
        mid=lt+(rt-lt)/2;
        ll sum=(1+mid)*mid/2;
        if(sum>v)
            rt=mid-1;
        else
        {
            lt=mid+1;
            ans=max(ans,mid);
        }
    }
    return ans;
}
