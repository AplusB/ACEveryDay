#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#include <set>

using namespace std;
typedef long long ll;
const int maxn=2e4+100;
const ll inf=2e9+9;

ll dfs(ll pos,ll ideal,ll times,ll rest);

int main()
{
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        ll p,q;
        scanf("%lld%lld",&p,&q);
        //printf("case #%d\n",cas++);
        if(q>=p)
        {
            printf("%lld\n",q-p);
            continue;
        }
        ll ans=dfs(p,q,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}

ll dfs(ll pos,ll ideal,ll times,ll rest)
{
    ll k=0;
    for(;k<100;k++)
    {
        if(((ll)(1)<<k)-1+ideal>=pos) break;
    }
    ll tmp=(ll)(1)<<k;
    if(max(pos-tmp+1,(ll)0)==ideal) return times+k;
    ll go=max(0LL,pos-tmp+1);
    go=ideal-go;
    ll ans=times+k+max(0LL,go-rest);
    ans=min(ans,dfs(pos-tmp/2+1,ideal,times+k,rest+1));
    return ans;
}
