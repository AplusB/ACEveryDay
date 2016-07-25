//lightoj 1125

#include<bits/stdc++.h>
//#include<cstdio>
//#include<math.h>
//#include<string.h>
//#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e8+7;
const LL INF=0x3f3f3f3f;

const int N=1e2+10;

int a[N*2];
LL dp[12][25];

int main()
{
    int cas=1;
    int n,w,q,d,m;
    int t,x,sum;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&q);
            for(int i=1;i<=n;i++)
                scanf("%d",&a[i]);

        printf("Case %d:\n",cas++);

        for(int k=1;k<=q;k++)
        {
            scanf("%d%d",&d,&m);
            memset(dp,0,sizeof(dp));
            dp[0][0]=1LL;
            for(int i=1;i<=n;i++)
            {
                int temp=a[i]%d;
                for(int j=m;j>=1;j--)
                    for(int x=0;x<d;x++)
                        dp[j][x]+=dp[j-1][(x+2*d-temp)%d];
            }
            printf("%lld\n",dp[m][0]);
        }
    }
    return 0;
}
