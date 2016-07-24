//poj 2955
//#include <bits/stdc++.h>
#include<cstdio>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int N=1e2+10;

char s[N];
int dp[N][N];

int main()
{
    int len,i,j,k,x;
    while(scanf("%s",s),s[0]!='e'){
        len=strlen(s);
        memset(dp,0,sizeof(dp));
        for(k=1;k<len;k++)
        {
            for(i=0,j=k;j<len;i++,j++)
            {
                if(s[i]=='('&&s[j]==')'||s[i]=='['&&s[j]==']')  //直接判断，进行匹配
                    dp[i][j]=dp[i+1][j-1]+2;
                for(x=i;x<j;x++)                            //小区间构成大区间**迭代更新
                    dp[i][j]=max(dp[i][j],dp[i][x]+dp[x+1][j]);
                //printf("dp[%d][%d]=%d ",i,j,dp[i][j]);
            }
            //puts("");
        }
        printf("%d\n",dp[0][len-1]);
    }
}
