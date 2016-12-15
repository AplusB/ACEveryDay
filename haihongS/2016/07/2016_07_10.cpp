#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=2e6+9;
const ll inf=2e9+9;

int n,m;
ll num[maxn],sum,del;
vector<int> G[maxn];

ll deal(int node,int fa);

ll abss(ll x)
{
    if(x<0)
        return -x;
    return x;
}

int main()
{
    int cass=1;
    while(scanf("%d%d",&n,&m) && n+m)
    {
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&num[i]);
            sum+=num[i];
        }
        del=sum;
        for(int i=0;i<maxn;i++)
            G[i].clear();
        for(int j=0;j<m;j++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        deal(1,1);
        printf("Case %d: ",cass++);
        printf("%lld\n",del);
    }
    return 0;
}

ll deal(int node,int fa)
{
    ll tmp=num[node];
    for(int i=0;i<G[node].size();i++)
    {
        if(G[node][i]==fa) continue;
        ll t1=deal(G[node][i],node);
        del=min(del,abss(abss(sum-t1)-t1));
        tmp+=t1;
    }
    return tmp;
}
