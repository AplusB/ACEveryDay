#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int g[1024],num[1024],cnt,dp[105][70][70],p[105];
char s[105][15];

void init(int m)
{
    cnt=0;
    int up=1<<m,f,sum=0;
    for(int i=0;i<up;i++)
    {
        f=1;
        sum=0;
        for(int j=0;j<m;j++)
        {
            if(i&(1<<j))
            {
                sum++;
                if(j+1<m&&(i&(1<<(j+1)))) f=0;
                if(j+2<m&&(i&(1<<(j+2)))) f=0;
            }
            if(!f) break;
        }
        if(f) {g[cnt]=i;num[cnt]=sum;cnt++;}
    }
}

int main()
{
    int n,m,ans,tmp;
    while(~scanf("%d%d",&n,&m))
    {
        init(m);
        memset(p,0,sizeof(p));
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            tmp=0;
            for(int j=0;j<m;j++)
            {
                if(s[i][j]=='P') tmp=tmp*2+1;
                else tmp=tmp*2;
            }
            p[i]=tmp;
            //printf("%d\n",tmp);
        }
        ans=0;
        memset(dp,0xff,sizeof(dp));
        for(int i=0;i<cnt;i++)
        {
            tmp=g[i]&p[0];
            if(tmp>=g[i])
            {
                dp[0][i][0]=num[i];
            }
            ans=max(dp[0][i][0],ans);
        }
        /*for(int i=1;i<min(2,n);i++)
        {
            for(int j=0;j<cnt;j++)
            {
                if((g[j]&p[1])<g[j]) continue;
                for(int k=0;k<cnt;k++)
                {
                    if(dp[0][k][0]==-1) continue;
                    if(g[j]&g[k]) continue;
                    dp[1][j][k]=max(dp[1][j][k],dp[0][k][0]+num[j]);
                    ans=max(dp[1][j][k],ans);
                }
            }
        }*/
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                if((g[j]&p[i])<g[j]) continue;
                for(int k=0;k<cnt;k++)
                {
                    if(g[j]&g[k]) continue;
                    for(int q=0;q<cnt;q++)
                    {
                        if(g[q]&g[k]) continue;
                        if(g[j]&g[q]) continue;
                        if(dp[i-1][k][q]==-1) continue;
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][q]+num[j]);
                    }
                    ans=max(dp[i][j][k],ans);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
