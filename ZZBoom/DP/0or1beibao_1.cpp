//poj 1837
//#include<bits/stdc++.h>
#include<cstdio>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=998244353;
const LL INF=0x3f3f3f3f;

const int N=25;
int dp[N][15007];
int a[N];
int b[N];

int main()
{
    int t,i,k,j;
    int c,g;
    scanf("%d%d",&c,&g);
    for(i=1;i<=c;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=g;i++)
        scanf("%d",&b[i]);
    memset(dp,0,sizeof(dp));
    dp[0][7500]=1;
    for(i=1;i<=g;i++)
        for(j=0;j<=15000;j++)
            if(dp[i-1][j])
                for(k=1;k<=c;k++)
                    dp[i][j+a[k]*b[i]]+=dp[i-1][j];
    printf("%d\n",dp[g][7500]);
}


