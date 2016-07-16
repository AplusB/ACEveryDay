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
    #define N 200000+10
    #define INF 0x3f3f3f3f
    #define endl '\n'
    #define mod 1000000009
    #define ll long long
    using namespace std;
    int ver[2*N],h[2*N],f[N],dp[2*N][30],n,sum=1,vis[N],dis[N];
    vector<int>v[N];
    void init()
    {
        for(int i=1;i<sum;i++) dp[i][0]=i;
        for(int j=1;(1<<j)<sum;j++)
            for(int i=1;i+(1<<j)-1<sum;i++)
               dp[i][j]=h[dp[i][j-1]]>h[dp[i+(1<<(j-1))][j-1]]?dp[i+(1<<(j-1))][j-1]:dp[i][j-1];
    }
    void dfs(int x,int dep)
    {
        ver[sum]=x,h[sum]=dep,vis[x]=1,f[x]=sum++;
        for(int i=0;i<v[x].size();i++)
        {
            int xx=v[x][i];
            if(vis[xx]) continue;
            dis[xx]=dis[x]+1;
            dfs(xx,dep+1);
            ver[sum]=x,h[sum++]=dep;
        }
    }
    int rmq(int x,int y)
    {
        int m=(int)(log((y-x+1)*1.0)/log(2.0));
        return h[dp[x][m]]>h[dp[y-(1<<m)+1][m]]?dp[y-(1<<m)+1][m]:dp[x][m];
    }
    int lca(int x,int y)
    {
     
        x=f[x],y=f[y];
        if(x>y) swap(x,y);
        return ver[rmq(x,y)];
    }
    int main()
    {
        scanf("%d",&n);
        int x;
        for(int i=2;i<=n;i++)
        {
            scanf("%d",&x);
            v[x].push_back(i);
        }
        dis[1]=1;
        dfs(1,1);
        init();
        int u=1,v=2,ans=1;
        cout<<1;
        for(int i=3;i<=n;i++)
        {
            int x=dis[i]+dis[u]-2*dis[lca(i,u)];
            int y=dis[i]+dis[v]-2*dis[lca(i,v)];
            if(x>ans&&x>=y) v=i,ans=x;
            if(y>ans&&y>=x) u=i,ans=y;
            cout<<" "<<ans;
        }
        cout<<endl;
        return 0;
    }
