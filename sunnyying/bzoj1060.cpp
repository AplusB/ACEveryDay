    #include <cstdio>
    #include <string.h>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <queue>
    #include <set>
    #include <map>
    #include <stack>
    #include <string>
    #include <math.h>
    #include <stdlib.h>
    #define N 500010
    #define INF 0x3f3f3f3f
    #define endl '\n'
    #define ll long long
    #define mod 1000000007
    using namespace std;
    ll mx[N],m,ans[N];
    struct node
    {
        ll to,val;
    };
    vector<node>v[N];
    void dfs(ll x,ll pre)
    {
        ll mmx=0;
        for(ll i=0;i<v[x].size();i++)
        {
            ll xx=v[x][i].to;
            if(xx==pre) continue;
            dfs(xx,x);
            mmx=max(mx[xx]+v[x][i].val,mmx);
        }
        mx[x]=mmx;
        if(v[x].size()==1&&x!=m) {mx[x]=0;ans[x]=0;return;}
        for(int i=0;i<v[x].size();i++)
        {
            int xx=v[x][i].to;
            if(xx==pre) continue;
            ans[x]=ans[x]+ans[xx]+mmx-mx[xx]-v[x][i].val;
        }
    }
    int main()
    {
      //  freopen("in.in","r",stdin);
       // freopen("out.out","w",stdout);
        ll n,x,y,z;
        scanf("%lld%lld",&n,&m);
        for(int i=0;i<n-1;i++)
        {
            scanf("%lld%lld%lld",&x,&y,&z);
            node e;
            e.to=y,e.val=z;
            v[x].push_back(e);
            e.to=x;
            v[y].push_back(e);
        }
        dfs(m,0);cout<<ans[m]<<endl;
        return 0;
    }
