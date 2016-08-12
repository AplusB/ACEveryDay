#include<cstdio>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define eps 1e-8
typedef __int64 LL;

const int N=1e4+10;

int val[4]={1,5,10,25};

int dp[N];  //在该面值的最大硬币数量
int num[5];
int pre[N];//记录背包路径
int cnt[N];//每次更新是临时计数
int ans[30]; //计数

int main()
{
    int n;
    int t;
    bool flag=true;
    while(1)
    {
        scanf("%d",&t);
        for(int i=0;i<4;i++)
        {
            scanf("%d",&num[i]);
            if(num[i]) flag=true;
        }
        if(!t&&!num[0]&&!num[1]&&!num[2]&&!num[3]) break;//在这里wa了，以后判0乖乖这样做。

        memset(pre,0,sizeof(pre));
        memset(dp,-1,sizeof(dp));

        dp[0]=0;
        pre[0]=-1;

        for(int i=0;i<4;i++)
        {
            memset(cnt,0,sizeof(cnt));
            for(int j=val[i];j<=t;j++)
            {
                if(dp[j-val[i]]>=0&&(dp[j-val[i]]+1)>dp[j]&&num[i]>cnt[j-val[i]])//首先dp[j-val[i]]>=0，因为要保证你前面那个是满足的
                {
                    dp[j]=dp[j-val[i]]+1;
                    cnt[j]=cnt[j-val[i]]+1;
                    pre[j]=j-val[i];
                }
            }
        }

        if(dp[t]<0)
        {
            printf("Charlie cannot buy coffee.\n");
            continue;
        }
        //printf("%d\n",dp[t]);

        memset(ans,0,sizeof(ans));
        int x=t;
        while(1)
        {
            if(pre[x]==-1) break;
            ans[x-pre[x]]++;
            x=pre[x];
        }
        printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",ans[1],ans[5],ans[10],ans[25]);
    }
    return 0;
}
