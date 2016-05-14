#include <bits/stdc++.h>
using namespace std;
double ax,ay,bx,by,tx,ty;
double ans,x[100005],y[100005],len[100005],dp[100005][3];
int n;
int main()
{
    scanf("%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&tx,&ty);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lf%lf",x+i,y+i),
        len[i]=sqrt((x[i]-tx)*(x[i]-tx)+(y[i]-ty)*(y[i]-ty)),
        ans+=len[i];
    ans*=2;
    dp[0][0]=dp[0][1]=dp[0][2]=-1e100;
    for(int i=1;i<=n;++i)
    {
        double ta=sqrt((x[i]-ax)*(x[i]-ax)+(y[i]-ay)*(y[i]-ay));
        double tb=sqrt((x[i]-bx)*(x[i]-bx)+(y[i]-by)*(y[i]-by));
        dp[i][0]=max(dp[i-1][0],len[i]-ta);
        dp[i][1]=max(dp[i-1][1],len[i]-tb);
        dp[i][2]=max(len[i]-ta+dp[i-1][1],len[i]-tb+dp[i-1][0]);
        dp[i][2]=max(dp[i][2],dp[i-1][2]);
    }
    ans-=max(dp[n][0],max(dp[n][1],dp[n][2]));
    printf("%.15lf\n",ans);
    return 0;
}
