#include<bits/stdc++.h>
using namespace std;
const int N=1024;
int s[N],cnt,d[N],u[N];
vector<int>g[N];

void dfs(int x,int dep)
{
    //printf("%d %d\n",x,g[x].size());
    cnt=max(cnt,dep);
    for(int i=0; i<g[x].size(); i++)
    {
        dfs(g[x][i],dep+1);
    }
    if(g[x].size()==0) s[dep]++;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<N; i++)
    {
        g[i].clear();
    }
    int x,y,k;
    for(int i=0; i<m; i++)
    {
        scanf("%d",&x);
        u[x]=1;
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&y);
            u[y]=1;
            g[x].push_back(y);
        }
    }
    memset(s,0,sizeof(s));
    cnt=1;
    dfs(1,1);
    for(int i=1; i<=cnt; i++)
    {
        if(i>=2) printf(" ");
        printf("%d",s[i]);
    }
    printf("\n");
    return 0;
}
