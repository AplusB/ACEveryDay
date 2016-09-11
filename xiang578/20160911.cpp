#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
ll ans,k,a[N],w[N],b[N];
int n,in[N],c[N];
vector<int>g[N];

int get(int x)
{
    int ret=0;
    //if(x>n) x=2*n;
    while(x>0)
    {
        ret+=c[x];
        x-=x&-x;
    }
    return ret;
}

void add(int x,int val)
{
    while(x<=2*n)
    {
        c[x]+=val;
        x+=x&-x;
    }
}

void dfs(int x)
{
    ans+=get(w[x]);
    add(a[x],1);
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        dfs(y);
    }
    add(a[x],-1);
}
int main()
{
    int _,u,v;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;i++)
            g[i].clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            if(a[i]==0) w[i]=1e18;
            else w[i]=k/a[i];
            b[2*i-2]=a[i];
            b[2*i-1]=w[i];
        }
        sort(b,b+2*n);
        for(int i=1;i<=n;i++)
        {
            a[i]=lower_bound(b,b+2*n,a[i])-b+1;
            w[i]=lower_bound(b,b+2*n,w[i])-b+1;
        }
        memset(in,0,sizeof(in));
        memset(c,0,sizeof(c));
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            in[v]++;
        }
        int rt;
        for(int i=1;i<=n;i++)
        {
            if(!in[i])
            {
                rt=i;
                break;
            }
        }
        ans=0;
        dfs(rt);
        printf("%lld\n",ans);
    }
    return 0;
}

/*
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int N=2e5+10;
typedef long long ll;
ll ans,k,a[N],b[N];
int n,in[N],c[N];
vector<int>g[N];

int get(int x)
{
    int ret=0;
    while(x>0)
    {
        ret+=c[x];
        x-=x&-x;
    }
    return ret;
}

void add(int x,int val)
{
    while(x<=2*n)
    {
        c[x]+=val;
        x+=x&-x;
    }
}
void dfs(int x)
{
    ll v;
    if(b[a[x]-1]==0) v=n+5;
    else
    {
        v=k/b[a[x]-1];
        v=lower_bound(b,b+n,v)-b+1;
    }
    //printf("%d %d %d %d\n",v,x,get(n),get(v+1));
    ans+=get(v);
    add(a[x],1);
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        dfs(y);
    }
    add(a[x],-1);
}
int main()
{
    int _,u,v;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            b[i-1]=a[i];
        }
        for(int i=1;i<=n;i++)
        {
            g[i].clear();
        }
        sort(b,b+n);
        for(int i=1;i<=n;i++)
        {
            a[i]=lower_bound(b,b+n,a[i])-b+1;
        }
        memset(in,0,sizeof(in));
        memset(c,0,sizeof(c));
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            in[v]++;
        }
        int rt;
        for(int i=1;i<=n;i++)
        {
            if(!in[i])
            {
                rt=i;
                break;
            }
        }
        ans=0;
        dfs(rt);
        printf("%lld\n",ans);
    }
    return 0;
}
*/
