//hdoj 1160
//dp[i]表示以第i个数据结尾的符合要求的子列长度

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;

const int N=1e3+7;
struct asd{
    int w,s;
    int indxe;
};
asd q[N];

bool cmp(asd z,asd x)
{
    if(z.w<x.w) return 1;
    else if(z.w==x.w&&z.s>x.s) return 1;
    return 0;
}
int dp[N];
int pre[N];
int res[N];

int main()
{
    int i=1,j;
    while(scanf("%d%d",&q[i].w,&q[i].s)!=EOF){
        dp[i]=1;
        pre[i]=0;
        q[i].indxe=i;
        i++;
    }
    int n=i-1;
    sort(q,q+n+1,cmp);
    int maxlen=0;
    int maxi;
    dp[1]=1;
    for(i=1;i<=n;i++){
        for(j=1;j<i;j++)
        if(q[i].w>q[j].w&&q[i].s<q[j].s&&dp[j]+1>dp[i]){
            dp[i]=dp[j]+1;
            pre[i]=j;
            if(dp[i]>maxlen){
                maxi=i;
                maxlen=dp[i];
            }
        }
    }
    int t=maxi;
    i=0;
    while(t!=0){
        res[i++]=t;
        t=pre[t];
    }
    printf("%d\n",i);
    while(i>0){
        i--;
        printf("%d\n",q[res[i]].indxe);
    }
    return 0;
}




