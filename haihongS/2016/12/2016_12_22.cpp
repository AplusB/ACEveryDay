#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll d,k,a,b,t;
    while(~scanf("%I64d%I64d%I64d%I64d%I64d",&d,&k,&a,&b,&t))
    {
        ll ans=d*b;
        if(k>=d)
            ans=min(ans,d*a);
        if(d-k>=0)
            ans=min(ans,k*a+(d-k)*b);
        ll pos=d/k,now=0;
        if(pos>0)
            now=(pos-1)*t+pos*k*a;
        ans=min(ans,now+d%k*b);
        ans=min(ans,now+d%k*a+t);
        printf("%I64d\n",ans);
    }
    return 0;
}
