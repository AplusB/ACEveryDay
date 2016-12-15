#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;

int n,m;
vector<int> G[maxn];
int flag[maxn],r1[maxn],r2[maxn];
int f1;
vector<int> cnt1,cnt0;

int dfs(int node,int x);

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        // init
        for(int i=0;i<maxn;i++)
            G[i].clear();
        memset(flag,-1,sizeof(flag));

        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            r1[i]=u,r2[i]=v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        f1=0;
        cnt0.clear(),cnt1.clear();

        for(int i=0;i<m;i++)
        {
            int u1=r1[i],u2=r2[i];
            if(flag[u1]==-1)
            {
                dfs(u1,1);
                if(f1==-1)
                {
                    printf("-1\n");
                    break;
                }

            }
            if(flag[u2]==-1)
            {
                dfs(u2,1);
                if(f1==-1)
                {
                    printf("-1\n");
                    break;
                }
            }
        }
        if(f1==-1)
            continue;

        printf("%d\n",cnt0.size());
        for(int i=0;i<cnt0.size();i++)
        {
            if(i==0)
                printf("%d",cnt0[i]);
            else
                printf(" %d",cnt0[i]);
        }
        printf("\n");
        printf("%d\n",cnt1.size());
        for(int i=0;i<cnt1.size();i++)
        {
            if(i==0)
                printf("%d",cnt1[i]);
            else
                printf(" %d",cnt1[i]);
        }
        printf("\n");
    }
    return 0;
}

int dfs(int node,int x)
{
    flag[node]=x;
    if(x==1)
        cnt1.push_back(node);
    else if(x==0)
        cnt0.push_back(node);

    for(int i=0;i<G[node].size();i++)
    {
        int j=G[node][i];
        if(flag[j]!=-1 && flag[j]==!x)
            continue;
        if(flag[j]==x)
        {
            f1=-1;
            return 0;
        }
        dfs(j,!x);
        if(f1==-1)
            return 0;
    }
    return 0;
}
