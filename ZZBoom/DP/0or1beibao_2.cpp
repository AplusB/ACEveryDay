//lightoj 1079
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

const int N=1e4;
double dp[N+50];

int main()
{
    int x;
    double y,p;
    int cas=1;
    int t,i,k,j,n;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0;i<=N;i++)
            dp[i]=-1;
        dp[0]=0;
        scanf("%lf%d",&p,&n);
        for(i=1;i<=n;i++){
            scanf("%d%lf",&x,&y);
            for(j=N;j>=x;j--){
                if(dp[j-x]==-1)
                    continue;
                if(dp[j]==-1)
                    dp[j]=dp[j-x]+(1.0-dp[j-x])*y;
                else
                    dp[j]=min(dp[j],dp[j-x]+(1.0-dp[j-x])*y);
            }
        }
        int ans = 0;
        for(int i=0;i<=N;i++)
            if(dp[i]!=-1&&dp[i]<=p)
                ans=i;
        printf("Case %d: %d\n",cas++,ans);
    }
    return 0;
}


