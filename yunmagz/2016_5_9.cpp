//lightoj 1145 - Dice (I)
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int mod=1e8+7;
LL dp[2][15010];
int main()
{
//    freopen("in.in","r",stdin);
//    freopen("out.out","w",stdout);
  int t,cas=1,n,s,k;
  cin>>t;
  while(t--){
    cin>>n>>k>>s;
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    LL sum=0;
    int now=0;
    for(int i=1;i<=n;i++){
      sum=0;
      now^=1;
      for(int j=0;j<=s;j++){
          if(j) sum=(sum+dp[now^1][j-1])%mod;
          if(j>k) sum=((sum-dp[now^1][j-k-1])%mod+mod)%mod;
          dp[now][j]=sum;
      }
	  }
    printf("Case %d: %d\n",cas++,dp[now][s]);
  }
  return 0;
}
