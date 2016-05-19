#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=1e3+9;
const double eps=1e-9;

double p[maxn][maxn];
double dp[maxn][35][35];
double f[maxn][35];

int main()
{
    int m,t,n;
    while(scanf("%d%d%d",&m,&t,&n) && m+t+n)
    {
        for(int i=1;i<=t;i++)
        {
            for(int j=1;j<=m;j++)
                scanf("%lf",&p[i][j]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=t;i++)
        {
            dp[i][0][0]=1;

            for(int j=0;j<=m;j++)
            {
                for(int k=1;k<=m;k++)
                {
                    if(j==0)
                    {
                        if(k==1) dp[i][j][k]=1-p[i][k];
                        else dp[i][j][k]=dp[i][j][k-1]*(1-p[i][k]);
                        continue;
                    }
                    dp[i][j][k]=dp[i][j-1][k-1]*p[i][k]+dp[i][j][k-1]*(1-p[i][k]);
                }
            }
        }

        memset(f,0,sizeof(f));
        for(int i=1;i<=t;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=0;k<=j;k++)
                    f[i][j]+=dp[i][k][m];
            }
        }

        double ans=1;
        for(int i=1;i<=t;i++)
            ans*=(1-dp[i][0][m]);
        double tmp=1;
        for(int i=1;i<=t;i++)
        {
            tmp*=(f[i][n-1]-f[i][0]);
        }
        ans-=tmp;
        printf("%.3lf\n",ans);
    }
    return 0;
}
