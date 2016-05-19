#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
const int inf=0x3fffffff;
int n,t,q,m,x,ans;
int a[1024],b[1024],dp[200][200];

int main()
{
    while(~scanf("%d%d%d",&n,&t,&q))
    {
        if(n==0&&t==0&&q==0) break;
        for(int i=0;i<n;i++)
            scanf("%d%d",a+i,b+i);
        m=100/q;
        if(100%q) m++;
        //printf("%d\n",m);
        ans=inf;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=100;j++)
            {
                dp[i][j]=inf;
            }
        }

        dp[0][100]=100;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=100;j++)
            {
                if(dp[i][j]==inf) continue;
                x=j+t;
                if(x>=100) x=100;
                dp[i+1][x]=min(dp[i+1][x],dp[i][j]-1);
                if(dp[i+1][x]<=0) ans=min(ans,i+1);
                for(int k=0;k<n;k++)
                {
                    if(a[k]>j) continue;
                    x=j-a[k]+t;
                    if(x>=100) x=100;
                    dp[i+1][x]=min(dp[i+1][x],dp[i][j]-b[k]);
                    if(dp[i+1][x]<=0) ans=min(ans,i+1);
                }

            }
        }

        if(ans>m) puts("My god");
        else printf("%d\n",ans);
    }
    return 0;
}
