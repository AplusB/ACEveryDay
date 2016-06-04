#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn=100+9;

int fa[maxn];
int num[maxn];
vector<int> G[maxn];

int findit(int x);
int union_it(int x,int y);

int main()
{
    memset(fa,-1,sizeof(fa));
    for(int i=0;i<maxn;i++)
    {
        num[i]=1;
        G[i].clear();
    }

    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int a,b,r;
        scanf("%d%d%d",&a,&b,&r);
        if(r==-1)
        {
            G[a].push_back(b);
            G[b].push_back(a);
        }
        else if(r==1)
        {
            union_it(a,b);
        }
    }
    for(int i=0;i<k;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int f1=0,f2=0;
        if(findit(x)==findit(y))
            f1=1;
        for(int j=0;j<G[x].size();j++)
        {
            if(G[x][j]==y)
            {
                f2=1;break;
            }
        }
        if(f1==1 && f2==1)
            printf("OK but...\n");
        else if(f1==1 && f2==0)
            printf("No problem\n");
        else if(f1==0 && f2==1)
            printf("No way\n");
        else if(f1==0 && f2==0)
            printf("OK\n");
    }

    return 0;
}

int union_it(int x,int y)
{
    int fx=findit(x),fy=findit(y);
    if(fx==fy) return 0;
    if(num[fx]>num[fy])
    {
        num[fx]+=num[fy];
        fa[fy]=fx;
    }
    else
    {
        num[fy]+=num[fx];
        fa[fx]=fy;
    }
    return 0;
}

int findit(int x)
{
    if(fa[x]==-1) return x;
    return fa[x]=findit(fa[x]);
}
