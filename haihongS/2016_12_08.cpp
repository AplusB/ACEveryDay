#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=3009;

vector<pair<int,int> > aha;
vector<int> G[maxn],rG[maxn];
ll mat[maxn][maxn];

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        aha.clear();
        for(int i=0;i<maxn;i++)
        {
            G[i].clear();
            rG[i].clear();
        }
        memset(mat,0,sizeof(mat));
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            rG[v].push_back(u);
            aha.push_back(make_pair(u,v));
        }
        for(int i=0;i<m;i++)
        {
            int u,v;
            u=aha[i].first,v=aha[i].second;
            int len=rG[u].size();
            for(int j=0;j<len;j++)
            {
                int m=rG[u][j];
                mat[m][v]+=1;
            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(mat[i][j]<=1)  continue;
                ll v=mat[i][j];
                ans+=v*(v-1)/2;
            }
        }
        printf("%lld\n",ans);


    }
    return 0;
}

