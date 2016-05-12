//lightoj 1191-Bar Codes
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int n,k,m;
LL dp[55],A[55];
int main(){
    int cas=1,t;
    cin>>t;
    while(t--){
        scanf("%d%d%d",&n,&k,&m);
        memset(dp,0,sizeof dp);
        memset(A,0,sizeof A);
        dp[0]=1;
        int l,r;
        LL sum=0;
        for(int i=1;i<=k;i++){
            for(int j=0;j<=n;j++){
                l=j+1,r=min(j+m+1,n+1);
                A[l]+=dp[j];
                A[r]-=dp[j];
            }
            sum=0;
            for(int j=0;j<=n;j++){
                sum+=A[j];
                dp[j]=sum;
                A[j]=0;
            }
        }
        printf("Case %d: %lld\n",cas++,dp[n]);
    }
    return 0;
}
