#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=400;
const ll inf=2e12+9;
ll G[maxn][maxn];


int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%lld",&G[i][j]);
        }
        int ans=n*(n-1)/2;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                ll minn=inf;
                for(int k=1;k<=n;k++)
                {
                    if(k==i || k==j) continue;
                    minn=min(minn,G[i][k]+G[k][j]);
                }
                if(minn==G[i][j])
                ans--;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
