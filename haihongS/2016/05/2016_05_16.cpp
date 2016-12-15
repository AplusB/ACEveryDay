#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;
const int maxn=1e3+9;

double dp[maxn][maxn];

int main()
{
    int n,s;
    while(~scanf("%d%d",&n,&s))
    {
        memset(dp,0,sizeof(dp));
        for(int i=n;i>=0;i--)
        {
            for(int j=s;j>=0;j--)
            {
                if(i==n && j==s) continue;
                double t1=1.0*(n-i)*j;
                double t2=1.0*i*(s-j);
                double t3=1.0*(n-i)*(s-j);
                dp[i][j]=t1*dp[i+1][j]+t2*dp[i][j+1]+t3*dp[i+1][j+1];
                dp[i][j]=1.0*dp[i][j]/(1.0*n*s-1.0*i*j)+1.0*n*s/(n*s-i*j);
            }
        }
        printf("%.4lf\n",dp[0][0]);
    }
    return 0;
}
