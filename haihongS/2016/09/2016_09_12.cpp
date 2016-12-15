#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;

vector<int> G[maxn];
int dis[maxn];

void add_edge(int u,int v);

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<maxn;i++)
        {
            G[i].clear();
            dis[i]=-1;
        }
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            add_edge(u,v);
        }
        int s;
        scanf("%d",&s);
        dis[s]=0;
        int all=n-1,now=0;
        while(all>0)
        {
            now++;
            int uu=0;
            for(int i=1;i<=n;i++)
            {
                if(dis[i]!=-1) continue;
                int len=G[i].size();
                int cnt=0;
                for(int j=0;j<len;j++)
                {
                    int nx=G[i][j];
                    if(dis[nx]!=-1 && dis[nx]<now) cnt++;
                }
                if(cnt+all==n) continue;
                dis[i]=now;
                uu++;
            }
            all-=uu;
            if(uu==0) break;
        }
        int ff=0;
        for(int i=1;i<=n;i++)
        {
            if(i==s) continue;
            if(ff==0) printf("%d",dis[i]),ff=1;
            else printf(" %d",dis[i]);
        }
        printf("\n");

    }
    return 0;
}

void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}


