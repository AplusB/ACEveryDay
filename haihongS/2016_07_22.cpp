#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const int inf=2e9+9;
const int maxgs=1<<21;

int gs[maxgs],vis[30];

int pre(int x);

int main()
{
    int t;
    scanf("%d",&t);

    memset(gs,-1,sizeof(gs));
    gs[0]=gs[1]=0;
    for(int i=2;i<=(1<<20)+2;i++)
        gs[i]=pre(i);

    while(t--)
    {
        int n;
        scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int m;
            scanf("%d",&m);
            int tmp=0;
            for(int j=0;j<m;j++)
            {
                int x;
                scanf("%d",&x);
                tmp|=1<<(20-x);
            }
            sum^=gs[tmp];
        }
        if(sum==0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

int pre(int x)
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<20;i++)
    {
        if(x&(1<<i))
        {
            for(int j=i-1;j>=0;j--)
            {
                if((x&(1<<j))==0)
                {
                    int tmp=x^(1<<i)^(1<<j);
                    vis[gs[tmp]]=1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<20;i++)
    {
        if(vis[i]==0) 
            return i;
    }
}
