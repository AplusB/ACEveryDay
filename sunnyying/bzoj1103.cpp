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
    #define INF 0x7fffffff
    #define endl '\n'
    #define ll long long
    #define eps 1e-8
    #define N 5000100
    using namespace std;
    int sum,mark[N],fa[N],mark1[N],flag[N];
    vector<int>v[N];
    void dfs(int x)
    {
         mark[x]=sum;flag[sum++]=0;
         for(int i=0;i<v[x].size();i++)
         {
             int xx=v[x][i];
             if(xx==fa[x]) continue;
             fa[xx]=x;
             dfs(xx);
         }
         flag[sum]=1;mark1[x]=sum++;
    }
    int st[500100];
    void change(int x,int v)
    {
        while(x<=sum)
        {
            st[x]+=v;
            x+=(x&(-x));
        }
    }
    int query(int x)
    {
        int ans=0;
        while(x)
        {
            ans+=st[x];
            x-=(x&(-x));
        }
        return ans;
    }
    int main()
    {
        int n,x,y,m;
        char c[5];
        scanf("%d",&n);
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        sum=1,dfs(1);sum–;
        for(int i=1;i<=sum;i++)
        {
            if(flag[i]) change(i,-1);
            else change(i,1);
        }
        scanf("%d",&m);
        m=m+n-1;
        while(m–)
        {
            scanf("%s%d",c,&x);
            if(c[0]=='W') cout<<query(mark[x])-1<<endl;
            else
            {
                scanf("%d",&y);
                if(fa[y]==x) change(mark[y],-1),change(mark1[y],1);
                else change(mark[x],-1),change(mark1[x],1);
            }
        }
        return 0;
    }
