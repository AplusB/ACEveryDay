#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int g[1024],num[1024],cnt,dp[105][200][200],p[105],m,ok[200][200];

void init()
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
                if(j+2<m&&(i&(1<<(j+2)))) f=0;
            }
            if(!f) break;
        }
        if(f) {g[cnt]=i;num[cnt]=sum;cnt++;}
    }
}

int ok1(int x,int y)
{
    for(int i=0;i<m;i++)
    {
        if(g[x]&(1<<i))
        {
            if(i-1>0)
            {
                if(g[y]&(1<<(i-1))) return 0;
            }
            if(i+1<m)
            {
                if(g[y]&(1<<(i+1))) return 0;
            }
        }

        if(g[y]&(1<<i))
        {
            if(i-1>0)
            {
                if(g[x]&(1<<(i-1))) return 0;
            }
            if(i+1<m)
            {
                if(g[x]&(1<<(i+1))) return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n,ans,tmp,t;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        memset(p,0,sizeof(p));
        for(int i=0;i<n;i++)
        {
            tmp=0;
            for(int j=0;j<m;j++)
            {
                scanf("%d",&t);
                tmp=tmp*2+t;
            }
            p[i]=tmp;
        }
        ans=0;
        for(int i=0;i<cnt;i++)
            for(int j=i;j<cnt;j++)
                ok[i][j]=ok[j][i]=ok1(i,j);
        memset(dp,0xff,sizeof(dp));
        for(int i=0;i<cnt;i++)
        {
            if((g[i]&p[0])>=g[i])
                dp[0][i][0]=num[i];
            ans=max(dp[0][i][0],ans);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                if((g[j]&p[i])<g[j]) continue;
                for(int k=0;k<cnt;k++)
                {
                    if(ok[j][k]==0) continue;
                    for(int q=0;q<cnt;q++)
                    {
                        if(ok[k][q]==0) continue;
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
