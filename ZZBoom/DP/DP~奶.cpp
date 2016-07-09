//poj 3616

#include<iostream>
#include<cstdio>
#include<math.h>
#include<queue>
#include<map>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;
#define INF 0x3f3f3f3f
#define PI acos(-1.0)

//因为同一点结束的时间段会有多个，这里没考虑；
//无限wa；
const int N=1e6+7;
int b[N];
LL a[N];
LL dp[N];
struct asd{
    int s;
    int t;
    LL w;
};
asd q[N];

bool cmp(asd z,asd x)
{
    if(z.t<x.t)
        return 1;
    return 0;
}

int main()
{
    int n,m,r;
    while(~scanf("%d%d%d",&n,&m,&r))
    {
        int s,t;
        LL w;
        for(int i=0;i<m;i++){
            scanf("%d%d%lld",&s,&t,&w);
            q[i].s=s;
            q[i].t=t;
            q[i].w=w;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            dp[q[i].t]=max(q[i].w,dp[q[i].t]);
        }
        sort(q,q+m,cmp);

        int x;
        int i,j=0;
        for(i=1;i<=n;i++){
            dp[i]=max(dp[i],dp[i-1]);
            for(;j<m;){
                if(q[j].t==i){
                    x=q[j].s-r;
                    if(x<0) x=0;
                    dp[i]=max(dp[i],dp[x]+q[j].w);
                    j++;
                }
                else
                    break;
            }
        }

/*        for(int i=1;i<=n;i++){
            printf("%d ",dp[i]);
        }
        puts("");*/


        printf("%d\n",dp[n]);
    }
    return 0;
}

/*
12 4 2
1 2 8
10 12 19
3 5 24
7 10 31

12 4 2
1 2 8
10 12 19
3 6 24
7 10 31
*/
