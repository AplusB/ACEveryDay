#include<bits/stdc++.h>
using namespace std;
const int N=10000+10;
const double inf=1e7;
double a[N],b[N],dp[2][N],ans;
int n,m,k;

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        if(n<=m)
        {
            for(int i=1; i<=n; i++) scanf("%lf",a+i);
            for(int j=1; j<=m; j++) scanf("%lf",b+j);
        }
        else
        {
            for(int i=1; i<=n; i++) scanf("%lf",b+i);
            for(int j=1; j<=m; j++) scanf("%lf",a+j);
            swap(n,m);
        }
        sort(a+1,a+n+1);
        sort(b+1,b+m+1);
        k=0;
        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
        {
            dp[k][i-1]=inf;
            for(int j=i; j<=min(m,i+100); j++)
            {
                dp[k][j]=min(dp[k^1][j-1]+fabs(a[i]-b[j]),dp[k][j-1]);
            }
            k=k^1;
        }
        printf("%.6f\n",dp[k^1][m]);
    }
    return 0;
}
