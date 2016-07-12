/*
    多重背包 
*/
#include<stdio.h>
#include<string.h>
int t,ca=0,n,K,v[55],c[55],dp[1011];

int main()
{
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));dp[0]=1;
        int i,j,k,l,res,tmp,ans;
        scanf("%d%d",&n,&K);
        for(i=1;i<=n;i++)scanf("%d",&v[i]);
        for(i=1;i<=n;i++)scanf("%d",&c[i]);
        for(i=1;i<=n;i++){
            for(j=K;j>=v[i];j--){
                for(k=1;k<=c[i]&&k*v[i]<=j;k++)
                    dp[j]=(dp[j]+dp[j-k*v[i]])%100000007;
            }
        }
        printf("Case %d: %d\n",++ca,dp[K]);
    }
    return 0;
}
