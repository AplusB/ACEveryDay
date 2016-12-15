#include <bits/stdc++.h>

using namespace std;
const int maxn=2e3+9;

vector<int> G[maxn];
int flag[maxn],n,m;

int dfs(int v,int fa,int no);

int main()
{
    int k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        for(int i=0;i<maxn;i++)
            G[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        while(k--)
        {
            int v;
            scanf("%d",&v);
            memset(flag,0,sizeof(flag));
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(i==v) continue;
                if(flag[i]==0)
                {
                    cnt++;
                    flag[i]=1;
                    dfs(i,i,v);
                }
            }
            printf("%d\n",cnt-1);
        }

    }
    return 0;
}

int dfs(int v,int fa,int no)
{
    int len=G[v].size();
    for(int i=0;i<len;i++)
    {
        int u=G[v][i];
        if(flag[u]==1 ||u==no) continue;
        flag[u]=1;
        dfs(u,v,no);
    }
    return 0;
}



